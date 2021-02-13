#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1000
char opcode[2*MAX];
char instruction[2*MAX]; // Vetor que vai armazenar a tradução -> EX: mov r0, #3
char buffer[2*MAX];

void printIntruction(FILE *f,  char* intruction);
void calc_immed8_mov(char caracter3, char caracter4, char* instruction);
void printMem(FILE *f,  char* instruction);
char* lerLinha(FILE *f);
void instructionDecoder(char* opcode, char* instruction);