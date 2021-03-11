#ifndef _DECODER_THUMB_H
#define _DECODER_THUMB_H

/*
 * =====================================================================================
 *
 *       Filename:  DECODER_THUMB.h
 * 	  Description:	Protótipos e declarações de variáveis
 *       Compiler:  gcc
 *        Authors:  Anderson Silva (475242) e Samuel Henrique (473360)
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

/*Bibliotecas Extras*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*Definição de uma tamanho MAX para as strings*/
#define MAX 1000

/*Declaração de strings globais que serão usadas no código*/
char opcode[2*MAX];			// String que receberá linha por linha do arquivo .in
char instruction[2*MAX]; 	// String que irá armazenar a tradução e imprimir o seu conteúdo no arquivo .out -> EX: mov r0, #3
char buffer[2*MAX];			// String auxiliar que será usada na transformação de inteiros para string

/*Protótipo da função*/
void instructionDecoder(char* opcode, char* instruction);

#endif /*_DECODER_THUMB_H*/