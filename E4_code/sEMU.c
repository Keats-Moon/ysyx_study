#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t PC = 0;

uint8_t R[4] = {0, 0, 0, 0};

uint8_t M[16] = {
    0x90,
    0xA0,
    0xB1,
    0x2B,
    0x16,
    0xCE,
    0x50,
    0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
void inst_cycle(void){
  uint8_t temp = M[PC];

  uint8_t opcode = temp & 0xC0;
  uint8_t rd     = (temp >> 4) & 0x03;
  uint8_t rs1    = (temp >> 2) & 0x03;
  uint8_t rs2    =  temp       & 0x03;
  uint8_t imm    =  temp       & 0x0F;
  uint8_t addr   = (temp >> 2) & 0x0F;
  switch (opcode){
    case 0x00:
      R[rd] = R[rs1] + R[rs2];
      PC++;
      break;
    case 0x80:
      R[rd] = imm;
      PC++;
      break;
    case 0xC0:
      if (R[0] != R[rs2]){
        PC = addr;
        break;
      }else{
        PC++;
        break;
      }
      break;
    case 0x40:
      printf("R[%u] = %u", rd, R[1]);
      PC++;
      break;
    default:
      PC++;
      break;



  }
}
int main(int argc, char *argv[]){
  if (argc < 2){
    printf("No data\n");
    return 1;
  }

  R[0] = (uint8_t)atoi(argv[1]);
  while(1){
    inst_cycle();

    if (PC == 7){
      break;
    }
  }
  return 0;
}
