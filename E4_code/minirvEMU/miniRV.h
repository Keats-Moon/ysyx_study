#ifndef MINIRV
#define MINIRV

#include <stdint.h>
#include <am.h>
#include <klib-macros.h>

#define MEM_SIZE 0x100000u
#define R_COUNT 32
#define FB_SIZE 0x10000

extern uint32_t PC;
extern uint32_t R[R_COUNT];
extern uint8_t M[];
extern uint64_t inst_count;
extern uint32_t fb[];

void inst_cycle(void);
uint32_t memory_get(uint32_t addr);
void memory_input(uint32_t addr, uint32_t value);
uint32_t imm_get(uint32_t count7, uint32_t count5, int enable);

extern uint32_t temp_M;
extern int32_t opcode;
extern int32_t rd;
extern uint32_t funct3;
extern uint32_t rs1;
extern uint32_t rs2;
extern uint32_t funct7;

void addi(uint32_t rs1, uint32_t rd, uint32_t imm);
void jalr(uint32_t rs1, uint32_t rd, uint32_t imm);
void add(uint32_t rs1, uint32_t rs2, uint32_t rd);
void lui(uint32_t imm, uint32_t rd);
void lw_lbu(uint32_t rs1, uint32_t rd, uint32_t funct3, uint32_t imm);
void sw_sb(uint32_t rs1, uint32_t rs2, uint32_t funct3, uint32_t imm);
void ebreak(void);

#define ADDI   0b0010011
#define JALR   0b1100111
#define ADD    0b0110011
#define LUI    0b0110111
#define LW_LBU 0b0000011
#define SW_SB  0b0100011
#define EBREAK 0b1110011

#endif
