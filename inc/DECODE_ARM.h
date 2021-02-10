#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void printIntruction(FILE *f,  char* intruction);
void calc_immed8_mov(char caracter3, char caracter4, char* instruction);
void printMem(FILE *f,  char* instruction);
char* lerLinha(FILE *f);
