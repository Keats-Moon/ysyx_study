#include "miniRV.h"
//#include "mem.h"
#include "vga.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <am.h>
#include <klib-macros.h>

uint8_t M[MEM_SIZE];

void load_bin(void){
  if (vga_bin_len > MEM_SIZE){
    printf("file_bin is too big!\n");
    exit(1);
  }
  memcpy(M, vga_bin, vga_bin_len);
}

void mem_insert(uint32_t addr, const uint8_t *bytes, int len){
  for (int i = 0; i < len; i++){
    M[addr + i] = bytes[i];
  } 
}

int main(void){
  ioe_init();

  load_bin();
  const uint8_t ebreak_bytes[4] = {0x73, 0x00, 0x10, 0x00};
  mem_insert(0xdb0, ebreak_bytes, 4);
  while(1){
    inst_cycle();
    if (inst_count % 10000 == 0){
      printf("inst: %lu, PC: %08X\n",inst_count, PC);
    }
  }
  return 0;
}
