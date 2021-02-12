#include "DECODER_THUMB.h"

int main(){
	// FILE *f;
	FILE *entrada;
	char instruction[30];    // Vetor que vai armazenar a tradução -> EX: mov r0, #3

	char string_in[4];

  int op = 0;
    do{
        system("clear");
        printf("==============================================\n");
        printf("=                                            =\n");
        printf("=          MENU DE OPÇÕES                    =\n");
        printf("=                                            =\n");
        printf("=     1-  LER DE UM ARQUIVO                  =\n");
        printf("=     2-  DIGITAR O CÓDIGO                   =\n");
        printf("=     3-  SAIR                               =\n");
        printf("==============================================\n");

        scanf("%d",&op);


        switch(op){
            case 1:
                entrada = fopen("entrada.txt", "r");

                if(entrada == 0)
                  printf("Não foi possivel lê o arquivo!");

                while(fgets(string_in, 5, entrada) != NULL){
                  instructionDecoder(string_in, instruction); //Funcionando
                }

                fclose(entrada);
                return 0;
            break;
            case 2:
                printf("Digite uma sequencia\n");
	              scanf("%[^\n]", string_in);
                instructionDecoder(string_in, instruction); //Funcionando
                return 0;
            break;
            case 3:
                return 0;
            break;
        }

    }while(op != 3);


	//printMem(f, string_in); //Printa o código da instrução.



	/*switch (string_in[0]){
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
	*/

	return 0;
}
