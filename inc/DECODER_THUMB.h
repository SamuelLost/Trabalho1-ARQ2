#ifndef _DECODER_THUMB_H

#define _DECODER_THUMB_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1000
char opcode[2*MAX];
char instruction[2*MAX]; // Vetor que vai armazenar a tradução -> EX: mov r0, #3
char buffer[2*MAX];

void instructionDecoder(char* opcode, char* instruction);
#endif