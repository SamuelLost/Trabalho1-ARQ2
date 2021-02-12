#include "DECODER_THUMB.h"

int main(void){
	FILE *f;
	FILE *entrada;
	char instruction[15];    // Vetor que vai armazenar a tradução -> EX: mov r0, #3

	char string_in[4];

	printf("Digite uma sequencia\n");
	scanf("%[^\n]", string_in);
	printMem(f, string_in); //Printa o código da instrução.
	switch (string_in[0]){
	case '2':
		strcat(instruction, "mov");
		if(string_in[1] == '0'){
			strcat(instruction, " r0");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}else if(string_in[1] == '1'){
			strcat(instruction, " r1");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}else if(string_in[1] == '2'){
			strcat(instruction, " r2");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}else if(string_in[1] == '3'){
			strcat(instruction, " r3");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}else if(string_in[1] == '4'){
			strcat(instruction, " r4");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}else if(string_in[1] == '5'){
			strcat(instruction, " r5");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}else if(string_in[1] == '6'){
			strcat(instruction, " r6");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}else {
			strcat(instruction, " r7");
			calc_immed8_mov(string_in[2], string_in[3], instruction);
			printIntruction(f, instruction);
		}
		break;

	default:
		break;
	}

	return 0;
}
