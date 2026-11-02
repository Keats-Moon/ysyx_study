#include "miniRV.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t PC = 0;
uint32_t R[R_COUNT] = {0};
uint32_t fb[FB_SIZE];

//取出内存,4字节拼接
uint32_t memory_get(uint32_t PC){
  uint32_t MEM32 = ((uint32_t)M[PC]) |
      ((uint32_t)M[PC+1] << 8) |
      ((uint32_t)M[PC+2] <<16) |
      ((uint32_t)M[PC+3] <<24);
  return MEM32;
}

//向内存中存入数据
void memory_input(uint32_t PC, uint32_t value){
  M[PC] = value & 0xFF;
  M[PC+1] = (value>>8) & 0xFF;
  M[PC+2] = (value>>16) & 0xFF;
  M[PC+3] = (value>>24) & 0xFF;
}

//用于判断地址是内存还是缓冲帧
_Bool judge_memory(uint32_t addr){
  return (addr >= 0x20000000) && (addr < 0x20040000);
}

//拼接imm，由一个使能控制。使能为0时imm=funct7+rs2；为1时imm=funct7+rd。
//这里需要注意，imm要进行有符号位拓展，不能直接强制转化成32位,所以我在最后进行了一次转化。
uint32_t imm_get(uint32_t count7, uint32_t count5, int enable){
  (void)enable;
  uint32_t imm;
  imm = ((count7 & 0x7Fu)<<5) | (count5 & 0x1Fu);
  imm = imm & 0xFFFu;
  return (imm ^ 0x800u) - 0x800u;
}

//各个指令的函数实现
void addi(uint32_t rs1, uint32_t rd, uint32_t imm){
  if (rd != 0){
    R[rd] = R[rs1] + imm;
  }
  PC = PC + 4;
}

void jalr(uint32_t rs1, uint32_t rd, uint32_t imm){
  uint32_t new_addr = (R[rs1] + imm) & ~1;
  if(rd != 0){
    R[rd] = PC + 4;
  }//RV32I手册中指出：Register x0 is hardwired with all bits equal to 0.
  PC = new_addr;
}

void add(uint32_t rs1, uint32_t rs2, uint32_t rd){
  if (rd != 0){
    R[rd] = R[rs1] + R[rs2];
  }
  PC = PC + 4;
}

void lui(uint32_t imm, uint32_t rd){
  if (rd != 0){
    R[rd] = imm;
  }
  PC = PC + 4;;
}

void lw_lbu(uint32_t rs1, uint32_t rd, uint32_t funct3, uint32_t imm){
  switch(funct3){
    case 0x02:{
                uint32_t addr = R[rs1] + imm;
                if (rd != 0){
                  R[rd] = memory_get(addr);
                }
                PC = PC + 4;
                break;
              }
    case 0x04:{
                uint32_t addr = R[rs1] + imm;
                if (rd != 0){
                  R[rd] = M[addr];
                }
                PC = PC + 4;
                break;
              }
    default: printf("Can not find the correct instruction\n");
             break;
  }
}

void sw_sb(uint32_t rs1, uint32_t rs2, uint32_t funct3, uint32_t imm){
  switch(funct3){
    case 0x02:{  //sw
                uint32_t addr = R[rs1] + imm;
                if (judge_memory(addr)) {
                  fb[(addr - 0x20000000) / 4] = R[rs2];
                } else{
                  memory_input(addr, R[rs2]);
                }
                PC = PC + 4;
                break;
              }
    case 0x00:{  //sb
                uint32_t addr = R[rs1] + imm;
                M[addr] = R[rs2] & 0xFF;
                PC = PC + 4;
                break;
              }
    default: printf("Can not find the correct instruction\n");
             break;
  }
}

void ebreak(void){
  if (R[10] == 0){
    printf("HIT GOOD TRAP\n");
  } else if (R[10] != 0){
    printf("HIT BAD TRAP\n");
  }
  io_write(AM_GPU_FBDRAW, 0, 0, fb, 256, 256, true);
  while(1);
}

uint64_t inst_count = 0;//指令计数器
void inst_cycle(void){
  uint32_t temp_M = memory_get(PC);
  uint32_t opcode = temp_M & 0x7F;
  uint32_t rd = (temp_M>>7) & 0x1F;
  uint32_t funct3 = (temp_M>>12) & 0x07;
  uint32_t rs1 = (temp_M>>15) & 0x1F;
  uint32_t rs2 = (temp_M>>20) & 0x1F;
  uint32_t funct7 = (temp_M>>25) & 0x7F;
  switch(opcode){
    case ADDI:
      addi(rs1, rd, imm_get(funct7, rs2, 0));
      inst_count++;
      break;

    case JALR:
      jalr(rs1, rd, imm_get(funct7, rs2, 0));
      inst_count++;
      break;

    case ADD:
      add(rs1, rs2, rd);
      inst_count++;
      break;

    case LUI:
      lui(temp_M & 0xFFFFF000u, rd);
      inst_count++;
      break;

    case LW_LBU:
      lw_lbu(rs1, rd, funct3, imm_get(funct7, rs2, 0));
      inst_count++;
      break;

    case SW_SB:
      sw_sb(rs1, rs2, funct3, imm_get(funct7, rd, 1));
      inst_count++;
      break;

    case EBREAK:
      if (imm_get(funct7, rs2, 0) == 0x01){
        ebreak();
      }
      break;

    default: printf("The opcode is wrong\n");
             break;
  }
  
} 

