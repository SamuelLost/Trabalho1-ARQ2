#include "DECODER_THUMB.h"

void instructionDecoder(char* opcode, char* instruction){

	char* ptr;
	long int intInstruction;
	int aux = 0, aux2 = 0;
    int offset = 0;

	while(scanf("%s[^\n]\n", opcode) != EOF){
		printf("%s	", opcode);
		intInstruction = strtol(opcode, &ptr, 16);
		switch (intInstruction >> 12 & 0xF){
			case 0x0: //Primeira Linha da Tabela - LSL|LSR
				if((intInstruction >> 11) & 0x1) {
					strcpy(instruction, "LSR");
					strcat(instruction, " r");
					aux = (intInstruction & 0x7); //descobrindo qual register r0-r7
					sprintf(buffer, "%d", aux);  //int to int
					strcat(instruction, buffer);
					strcat(instruction, ", r");
					aux = (intInstruction >> 3) & 0x7; //descobrindo o segundo registrador
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, ", #");
					aux = (intInstruction >> 6) & 0x0F; //descobrindo o segundo registrador
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
				}
				else {
					strcpy(instruction, "LSL");
					strcat(instruction, " r");
					aux = (intInstruction & 0x7); //descobrindo qual register r0-r7
					sprintf(buffer, "%d", aux);  //int to int
					strcat(instruction, buffer);
					strcat(instruction, ", r");
					aux = (intInstruction >> 3) & 0x7; //descobrindo o segundo registrador
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, ", #");
					aux = (intInstruction >> 6) & 0x1F; //descobrindo o immed5
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
				}

				printf("%s", instruction);
				break;
			case 0x1: //Segunda, terceira e quarta Linha da Tabela - ASR ou ADD|SUB ou ADD|SUB
				if((intInstruction >> 11) & 0x1) { //bit 11 = 1
					if((intInstruction >> 10) & 0x1) { // bit 10 = 1
						if((intInstruction >> 9) & 0x1) { //bit 9 = 1
							strcpy(instruction, "SUB");
							strcat(instruction, " r");
							aux = (intInstruction & 0x7); //descobrindo qual register r0-r7
							sprintf(buffer, "%d", aux);  //int to int
							strcat(instruction, buffer);
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							strcat(instruction, ", #");
							aux = (intInstruction >> 6) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
						}
						else { //bit 9 = 0
							strcpy(instruction, "ADD");
							strcat(instruction, " r");
							aux = (intInstruction & 0x7); //descobrindo qual register r0-r7
							sprintf(buffer, "%d", aux);  //int to int
							strcat(instruction, buffer);
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							strcat(instruction, ", #");
							aux = (intInstruction >> 6) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
						}
					}
					else { //bit 10 = 0
						if((intInstruction >> 9) & 0x1) { //bit 9 = 1
							strcpy(instruction, "SUB");
							strcat(instruction, " r");
							aux = (intInstruction & 0x7); //descobrindo qual register r0-r7
							sprintf(buffer, "%d", aux);  //int to int
							strcat(instruction, buffer);
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							strcat(instruction, ", r");
							aux = (intInstruction >> 6) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

						}
						else { //bit 9 = 0
							strcpy(instruction, "ADD");
							strcat(instruction, " r");
							aux = (intInstruction & 0x7); //descobrindo qual register r0-r7
							sprintf(buffer, "%d", aux);  //int to int
							strcat(instruction, buffer);
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							strcat(instruction, ", r");
							aux = (intInstruction >> 6) & 0x7; //descobrindo o segundo registrador
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
						}
					}
				}
				else { //bit 11 = 0
					strcpy(instruction, "ASR");
					strcat(instruction, " r");
					aux = (intInstruction & 0x7); //descobrindo qual register r0-r7
					sprintf(buffer, "%d", aux);  //int to int
					strcat(instruction, buffer);
					strcat(instruction, ", r");
					aux = (intInstruction >> 3) & 0x7; //descobrindo o segundo registrador
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, ", #");
					aux = (intInstruction >> 6) & 0x1F; //descobrindo o segundo registrador
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
				}

				printf("%s", instruction);
				break;
			case 0x2:
				if((intInstruction >> 11) & 0x1) {
					strcpy(instruction, "CMP");
				}
				else {
					strcpy(instruction, "MOV");
				}
				strcat(instruction, " r");
				aux = (intInstruction >> 8) & 0x7; //descobrindo qual register r0-r7
				sprintf(buffer, "%d", aux);  //int to int
				strcat(instruction, buffer);
				strcat(instruction, ", #");
				aux = (intInstruction & 0xFF); //imediato
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);

				printf("%s", instruction);
				break;
			case 0x3:
				if((intInstruction >> 11) & 0x1) {
					strcpy(instruction, "SUB");
				}
				else {
					strcpy(instruction, "ADD");
				}
				strcat(instruction, " r");
				aux = (intInstruction >> 8) & 0x7;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				strcat(instruction, ", #");
				aux = (intInstruction & 0xFF); //imediato
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);

				printf("%s", instruction);

				break;
			case 0x4:
				if(!((intInstruction >> 11) & 0x1)){ // Instruções para bit 11 = 0
					aux = (intInstruction >> 8) & 0x7;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "0"))){ // Instruções AND | EOR | LSL | LSR
						aux = (intInstruction >> 6) & 0x3;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "0"))){   // Instrução AND
							strcpy(instruction, "AND");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "1"))){ // Instrução EOR
							strcpy(instruction, "EOR");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "2"))){ // Instrução LSL
							strcpy(instruction, "LSL");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "3"))){ // Instrução LSR
							strcpy(instruction, "LSR");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							printf("%s", instruction);

						}
					}
					else if(!(strcmp(buffer, "1"))){ // Instruções ASR | ADC | SBC | ROR
						aux = (intInstruction >> 6) & 0x3;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "0"))){ // Instrução ASR
							strcpy(instruction, "ASR");

							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "1"))){ // Instrução ADC
							strcpy(instruction, "ADC");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "2"))){ // Instrução SBC
							strcpy(instruction, "SBC");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "3"))){ // Instrução ROR
							strcpy(instruction, "ROR");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
					}
					else if(!(strcmp(buffer, "2"))){	// Instruções TST | NEG | CMP | CMN
						aux = (intInstruction >> 6) & 0x3;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "0"))){	// Instrução TST
							strcpy(instruction, "TST");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "1"))){ // Instrução NEG
							strcpy(instruction, "NEG");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "2"))){ // Instrução CMP
							strcpy(instruction, "CMP");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "3"))){ // Instrução CMN
							strcpy(instruction, "CMN");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
					}
					else if(!(strcmp(buffer, "3"))){// Instruções ORR | MUL | BIC | MVN
						aux = (intInstruction >> 6) & 0x3;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "0"))){// Instrução ORR
							strcpy(instruction, "ORR");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "1"))){// Instrução MUL
							strcpy(instruction, "MUL");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "2"))){// Instrução BIC
							strcpy(instruction, "BIC");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "3"))){// Instrução MVN
							strcpy(instruction, "MVN");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
					}
					else if(!(strcmp(buffer, "4"))){
						aux = (intInstruction >> 6) & 0x3;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "1"))){ // Intrução ADD ld, Hm
							strcpy(instruction, "ADD");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", (aux + 8));
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "2"))){ // Instrução ADD Hd, lm
							strcpy(instruction, "ADD");
							// Registrador fonte
							strcat(instruction, " r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", (aux + 8));
							strcat(instruction, buffer);

							// Registrador de destino
							strcat(instruction, ", r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "3"))){ // Instrução ADD Hd, Hm
							strcpy(instruction, "ADD");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", (aux + 8));
							strcat(instruction, buffer);

							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", (aux + 8));
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
					}
					else if(!(strcmp(buffer, "5"))){ // Instrução CMP
						aux = (intInstruction >> 6) & 0x3;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "1"))){ // Instrução CMP ln, Hm
							strcpy(instruction, "CMP");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", (aux+8));
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "2"))){ // Instrução CMP Hm, ln
							strcpy(instruction, "CMP");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", (aux+8));
							strcat(instruction, buffer);

							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							printf("%s", instruction);
						}
						else if(!(strcmp(buffer, "3"))){ // Instrução CMP Hm, Hn
							strcpy(instruction, "CMP");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", (aux+8));
							strcat(instruction, buffer);

							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", (aux+8));
							strcat(instruction, buffer);
							printf("%s", instruction);
						}
					}
					else if(!(strcmp(buffer, "6"))){
						aux = (intInstruction >> 6) & 0x3;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "0"))){ // Instrução CPY

							strcpy(instruction, "CPY");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}else if(!(strcmp(buffer, "1"))){
							strcpy(instruction, "MOV");
							// Registrador de destino
							strcat(instruction, " r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);
							// Registrador fonte
							strcat(instruction, ", r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", (aux + 8));
							strcat(instruction, buffer);

							printf("%s", instruction);
						}else if(!(strcmp(buffer, "2"))){ // Instrução MOV Hd, Lm
							strcpy(instruction, "MOV");
							// Registrador fonte
							strcat(instruction, " r");
							aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
							sprintf(buffer, "%d", (aux + 8));
							strcat(instruction, buffer);
							// Registrador de destino
							strcat(instruction, ", r");
							aux = intInstruction & 0x7; // Bits 2,1,0
							sprintf(buffer, "%d", aux);
							strcat(instruction, buffer);

							printf("%s", instruction);
						}
					}
					else if(!(strcmp(buffer, "7"))){// Instruções BX | BLX
						aux = (intInstruction >> 7) & 0x1;
						sprintf(buffer, "%d", aux);
						if(!(strcmp(buffer, "0"))){ // Instrução BX
							strcpy(instruction, "BX");
						}else { // Instrução BLX
							strcpy(instruction, "BLX");
						}
						strcat(instruction, " r");
						// Encontrando qual registrador
						aux = (intInstruction >> 3) & 0xF; // Bits 6,5,4,3
						sprintf(buffer, "%d", aux);
						strcat(instruction, buffer);

						printf("%s", instruction);
					}
				}
				else { // Instruções com bit 11 = 1
					strcpy(instruction, "LDR"); // Instrução Ld, [pc, #immed*4]
					aux = (intInstruction >> 8) & 0x7; // Bits 10,9,8
					sprintf(buffer, "%d", aux);
					strcat(instruction, " r");
					strcat(instruction, buffer);
					strcat(instruction, ", [pc, #");
					aux = (intInstruction & 0xFF)*4; // Bits 10,9,8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, "]");
					printf("%s", instruction);
				}
				break;
			case 0x5:
				if(!((intInstruction >> 11) & 0x1)){ // Instruções com o bit 11 = 0 -> Instruções STR | STRH | STRB | LDRSB
					aux = (intInstruction >> 9) & 0x3;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "0"))){ // Instrução STR Rd, [Rb, Ro]
						strcpy(instruction, "STR");
					}else if(!(strcmp(buffer, "1"))){ //Instrução STRH Rd, [Rb, Ro]
						strcpy(instruction, "STRH");
					}else if(!(strcmp(buffer, "2"))){ //Instrução STRB Rd, [Rb, Ro]
						strcpy(instruction, "STRB");
					}else if(!(strcmp(buffer, "3"))){ //Instrução LDRSB Rd, [Rb, Ro]
						strcpy(instruction, "LDRSB");
					}
					// Registrador de destino(Rd)
					strcat(instruction, " r");
					aux = intInstruction & 0x7; // Bits 2,1,0
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);

					// Registrador de destino(Rb)
					strcat(instruction, ", [r");
					aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);

					// Registrador de destino(Rb)
					strcat(instruction, ", r");
					aux = (intInstruction >> 6) & 0x7; // Bits 8,7,6
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, "]");

					printf("%s", instruction);
				}
				else { // Instruções com o bit 11 = 1 -> Instruções LDR | LDRH | LDRB | LDRSH
					aux = (intInstruction >> 9) & 0x3;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "0"))){ // Instrução LDR Rd, [Rb, Ro]
						strcpy(instruction, "LDR");
					}else if(!(strcmp(buffer, "1"))){ //Instrução LDRH Rd, [Rb, Ro]
						strcpy(instruction, "LDRH");
					}else if(!(strcmp(buffer, "2"))){ //Instrução LDRB Rd, [Rb, Ro]
						strcpy(instruction, "LDRB");
					}else if(!(strcmp(buffer, "3"))){ //Instrução LDRSH Rd, [Rb, Ro]
						strcpy(instruction, "LDRSH");
					}
					// Registrador de destino(Rd)
					strcat(instruction, " r");
					aux = intInstruction & 0x7; // Bits 2,1,0
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);

					// Registrador de destino(Rb)
					strcat(instruction, ", [r");
					aux = (intInstruction >> 3) & 0x7; // Bits 5,4,3
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);

					// Registrador de destino(Rb)
					strcat(instruction, ", r");
					aux = (intInstruction >> 6) & 0x7; // Bits 8,7,6
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, "]");

					printf("%s", instruction);
				}
				break;
			case 0x6:
				if(!((intInstruction >> 11) & 0x1)){ // Instrução com o bit 11 = 0 -> STR | LDR Ld, [Ln, #immed*4]
					strcpy(instruction, "STR");
				}
				else {
					strcpy(instruction, "LDR");
				}
				// Registrador de destino
				strcat(instruction, " r");
				aux = intInstruction & 0x7;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);

				strcat(instruction, ", [r");
				aux = (intInstruction >> 3) & 0x7;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				// Encontrando immed5
				strcat(instruction, ", #");
				aux = ((intInstruction >> 6) & 0x1F) * 4;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				strcat(instruction, "]");

				printf("%s", instruction);
				break;
			case 0x7:
				if(!((intInstruction >> 11) & 0x1)){ // Instrução com o bit 11 = 0 -> STRB | LDRB Ld, [Ln, #immed*4]
					strcpy(instruction, "STRB");
				}
				else {
					strcpy(instruction, "LDRB");
				}
				// Registrador de destino
				strcat(instruction, " r");
				aux = intInstruction & 0x7;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);

				strcat(instruction, ", [r");
				aux = (intInstruction >> 3) & 0x7;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				// Encontrando immed5
				strcat(instruction, ", #");
				aux = (intInstruction >> 6) & 0x1F;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				strcat(instruction, "]");

				printf("%s", instruction);
				break;
			case 0x8:
				if(!((intInstruction >> 11) & 0x1)){ // Instrução com o bit 11 = 0 -> STRH | LDRH Ld, [Ln, #immed*2]
					strcpy(instruction, "STRH");
				}
				else {
					strcpy(instruction, "LDRH");
				}
				// Registrador de destino
				strcat(instruction, " r");
				aux = intInstruction & 0x7;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);

				strcat(instruction, ", [r");
				aux = (intInstruction >> 3) & 0x7;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				// Encontrando immed5
				strcat(instruction, ", #");
				aux = ((intInstruction >> 6) & 0x1F) * 2;
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				strcat(instruction, "]");

				printf("%s", instruction);
				break;
			case 0x9:
				if((intInstruction >> 11) & 0x1) {
					strcpy(instruction, "LDR");
					strcat(instruction, ", r");
					aux = (intInstruction >> 8) & 0x7;
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, ", [sp, #");
					aux = (intInstruction & 0xFF)*4;
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, "]");
				}
				else {
					strcpy(instruction, "STR");
					strcat(instruction, ", r");
					aux = (intInstruction >> 8) & 0x7;
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, ", [sp, #");
					aux = (intInstruction & 0xFF)*4;
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, "]");
				}
				printf("%s", instruction);
				break;
			case 0xA:
				if(!((intInstruction >> 11) & 0x1)){  // Instrução ADD Ld, pc, #immed*4
					strcpy(instruction, "ADD");
					// Registrador de destino
					strcat(instruction, " r");
					aux = (intInstruction >> 8 & 0x7); //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, ", pc, #");

					// Calculando o immed*4
					aux = (intInstruction & 0xFF)*4; //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					printf("%s", instruction);
				}
				else {
					strcpy(instruction, "ADD");
					// Registrador de destino
					strcat(instruction, " r");
					aux = (intInstruction >> 8 & 0x7); //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					strcat(instruction, ", sp, #");

					// Calculando o immed*4
					aux = (intInstruction & 0xFF)*4; //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					printf("%s", instruction);
				}
				break;
			case 0xB:
				aux = (intInstruction >> 8) & 0xF;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "0"))){ // Instruções ADD sp, #immed*4 | SUB sp, #immed*4
					if(!((intInstruction >> 7) & 0x1)){ // ADD sp, #immed*4
						strcpy(instruction, "ADD");
					}else { // SUB sp, #immed*4
						strcpy(instruction, "SUB");
					}
					strcat(instruction, " sp, #");
					aux = (intInstruction & 0x7F)*4; //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					printf("%s", instruction);
				}
				else if(!(strcmp(buffer, "2"))){// Instruções SXTH | SXTB | UXTH | UXTB
					aux = (intInstruction >> 6) & 0x3;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "0"))){
						strcpy(instruction, "SXTH");
					}else if(!(strcmp(buffer, "1"))){
						strcpy(instruction, "SXTB");
					}else if(!(strcmp(buffer, "2"))){
						strcpy(instruction, "UXTH");
					}else if(!(strcmp(buffer, "3"))){
						strcpy(instruction, "UXTB");
					}
					// Registrador de destino
					strcat(instruction, " r");
					aux = (intInstruction & 0x7);
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					// Registrador fonte
					strcat(instruction, ", r");
					aux = (intInstruction >> 3 & 0x7);
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);

					printf("%s", instruction);
				}else if(!(strcmp(buffer, "4"))){ // Instrução PUSH, { register-list }
					strcpy(instruction, "PUSH");
					strcat(instruction, " {");
					// Encontrando o register list
					aux = (intInstruction) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, "r0");
					}
					aux = (intInstruction >> 1) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r1");
					}
					aux = (intInstruction >> 2) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r2");
					}
					aux = (intInstruction >> 3) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r3");
					}
					aux = (intInstruction >> 4) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r4");
					}
					aux = (intInstruction >> 5) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r5");
					}
					aux = (intInstruction >> 6) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r6");
					}
					aux = (intInstruction >> 7) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r7");
					}
					strcat(instruction, "}");
					printf("%s", instruction);
				}else if(!(strcmp(buffer, "5"))){ // Instrução PUSH {register-list, lr}
					strcpy(instruction, "PUSH");
					strcat(instruction, " {");
					// Encontrando o register list
					aux = (intInstruction) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, "r0");
					}
					aux = (intInstruction >> 1) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r1");
					}
					aux = (intInstruction >> 2) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r2");
					}
					aux = (intInstruction >> 3) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r3");
					}
					aux = (intInstruction >> 4) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r4");
					}
					aux = (intInstruction >> 5) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r5");
					}
					aux = (intInstruction >> 6) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r6");
					}
					aux = (intInstruction >> 7) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r7");
					}
					strcat(instruction, ", lr}");
					printf("%s", instruction);
				}
				else if(!(strcmp(buffer, "6"))){//
					aux = (intInstruction >> 4) & 0xF;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "5"))){ // Instruções SETEND LE | SETEND BE
						if(!((intInstruction >> 3) & 0x1)){ // Instrução SETEND LE
							strcpy(instruction, "SETEND LE");
						}else{
							strcpy(instruction, "SETEND BE");
						}
						printf("%s", instruction);
					}
					else{// Instruções CPSIE | CPSID
						if(!((intInstruction >> 4) & 0x1)){ // Instrução CPSIE
							strcpy(instruction, "CPSIE");
						}else{
							strcpy(instruction, "CPSID");
						}
						printf("%s", instruction);
					}
				}
				else if(!(strcmp(buffer, "10"))){// Instruções REV | REV16 | REVSH
					aux = (intInstruction >> 6) & 0x3;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "0"))){
						strcpy(instruction, "REV");
					}
					else if(!(strcmp(buffer, "1"))){
						strcpy(instruction, "REV16");
					}
					else if(!(strcmp(buffer, "2"))){
						strcpy(instruction, "REVSH");
					}
					// Registrador de destino
					strcat(instruction, " r");
					aux = (intInstruction & 0x7);
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					// Registrador fonte
					strcat(instruction, ", r");
					aux = (intInstruction >> 3 & 0x7);
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);

					printf("%s", instruction);
				}else if(!(strcmp(buffer, "12"))){ // Instrução POP { register-list }
					strcpy(instruction, "POP");
					strcat(instruction, " {");
					// Encontrando o register list
					aux = (intInstruction) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, "r0");
					}
					aux = (intInstruction >> 1) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r1");
					}
					aux = (intInstruction >> 2) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r2");
					}
					aux = (intInstruction >> 3) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r3");
					}
					aux = (intInstruction >> 4) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r4");
					}
					aux = (intInstruction >> 5) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r5");
					}
					aux = (intInstruction >> 6) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r6");
					}
					aux = (intInstruction >> 7) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r7");
					}
					strcat(instruction, "}");
					printf("%s", instruction);
				}else if(!(strcmp(buffer, "13"))){ // Instrução PUSH, { register-list }
					strcpy(instruction, "POP");
					strcat(instruction, " {");
					// Encontrando o register list
					aux = (intInstruction) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, "r0");
					}
					aux = (intInstruction >> 1) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r1");
					}
					aux = (intInstruction >> 2) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r2");
					}
					aux = (intInstruction >> 3) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r3");
					}
					aux = (intInstruction >> 4) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r4");
					}
					aux = (intInstruction >> 5) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r5");
					}
					aux = (intInstruction >> 6) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r6");
					}
					aux = (intInstruction >> 7) & 0x1;
					sprintf(buffer, "%d", aux);
					if(!(strcmp(buffer, "1"))){
						strcat(instruction, ", r7");
					}
					strcat(instruction, ", pc}");
					printf("%s", instruction);
				}
				else if(!(strcmp(buffer, "14"))){// Instrução BKPT immed8
					strcpy(instruction, "BKPT");
					strcat(instruction, ", #");
					aux = (intInstruction & 0xFF); //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					printf("%s", instruction);
				}
				break;
			case 0xC:
				if(intInstruction >> 11 & 0x1) { //bit 11 = 1
					strcpy(instruction, "LDMIA");
				}
				else { //bit 11 = 0
					strcpy(instruction, "STMIA");
				}
				strcat(instruction, " r");
				aux = (intInstruction >> 8) & 0x7; //Ln, r0-r7
				sprintf(buffer, "%d", aux);
				strcat(instruction, buffer);
				strcat(instruction, "!, {");
				//Calcular o register_list
				aux = (intInstruction) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, "r0");
				}
				aux = (intInstruction >> 1) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, ", r1");
				}
				aux = (intInstruction >> 2) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, ", r2");
				}
				aux = (intInstruction >> 3) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, ", r3");
				}
				aux = (intInstruction >> 4) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, ", r4");
				}
				aux = (intInstruction >> 5) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, ", r5");
				}
				aux = (intInstruction >> 6) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, ", r6");
				}
				aux = (intInstruction >> 7) & 0x1;
				sprintf(buffer, "%d", aux);
				if(!(strcmp(buffer, "1"))){
					strcat(instruction, ", r7");
				}
				strcat(instruction, "}");
				printf("%s", instruction);
				break;
			case 0xD:
				if(((intInstruction >> 8) & 0xF) == 0xF) { // Instrução SWI
					strcpy(instruction, "SWI");
					strcat(instruction, ", #");
					aux = (intInstruction & 0xFF); //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					printf("%s", instruction);
				}
				else if(((intInstruction >> 8) & 0xE) == 0xE) { //Undefined and expected to remain so
					//0xE = 0b1110
					strcpy(instruction, "Indefinido");
					printf("%s", instruction);
					break;
				}
				else /*if(((intInstruction >> 8)) < 0xE)*/ { //B<cond>
					strcpy(instruction, "B");
					aux2 = (intInstruction >> 8) & 0xF;
					if(aux2 == 0x0) {
						strcat(instruction, "EQ");
					}
					else if(aux2 == 0x1) {
						strcat(instruction, "NE");
					}
					else if(aux2 == 0x2) {
						strcat(instruction, "CS");
					}
					else if(aux2 == 0x3) {
						strcat(instruction, "CC");
					}
					else if(aux2 == 0x4) {
						strcat(instruction, "MI");
					}
					else if(aux2 == 0x5) {
						strcat(instruction, "PL");
					}
					else if(aux2 == 0x6) {
						strcat(instruction, "VS");
					}
					else if(aux2 == 0x7) {
						strcat(instruction, "VC");
					}
					else if(aux2 == 0x8) {
						strcat(instruction, "HI");
					}
					else if(aux2 == 0x9) {
						strcat(instruction, "LS");
					}
					else if(aux2 == 0xA) {
						strcat(instruction, "GE");
					}
					else if(aux2 == 0xB) {
						strcat(instruction, "LT");
					}
					else if(aux2 == 0xC) {
						strcat(instruction, "GT");
					}
					else if(aux2 == 0xD) {
						strcat(instruction, "LE");
					}
					strcat(instruction, " #");
					offset = intInstruction & 0xFF;
					aux = (intInstruction >> 12) + 4 + (offset*2);
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					printf("%s", instruction);
				}
				/*aux = ((intInstruction >> 8)  & 0xF);
				sprintf(buffer, "%d", aux);
				if (!(strcmp(buffer, "15"))){
					strcpy(instruction, "SWI");
					strcat(instruction, ", #");
					aux = (intInstruction & 0xFF); //immed8
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
					printf("%s", instruction);
				}
				else {
					strcpy(instruction, "Indefinido");
					printf("%s", instruction);
				}*/
				break;
			case 0xE:
				if((intInstruction >> 11) & 0x1) {
					strcpy(instruction, "BLX");
					/*Falta os calculos*/
				}
				else {
					strcpy(instruction, "B");
					strcat(instruction, " #");
					aux = (intInstruction & 0x7FF)*2 + 4;
					aux +=  ((intInstruction >> 11) & 0x1);
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);
				}
				printf("%s", instruction);
				break;
            case 0xF:
                if((intInstruction >> 11) & 0x1) { //bit 11 = 1
					strcpy(instruction, "BL #");
					/*Falta os calculos*/
                    offset = intInstruction & 0x7FF; // 11bits de offset
                    aux = (intInstruction >> 12) + 4 + (offset*2);
                    /*Não tenho 100% de certeza desses calculos*/
                    sprintf(buffer, "%d", aux);
                    strcat(instruction, buffer);

				}
				else { //bit 11 = 0
					/*strcpy(instruction, "B");
					strcat(instruction, " #");
					aux = (intInstruction & 0x7FF)*2 + 4;
					aux +=  ((intInstruction >> 11) & 0x1);
					sprintf(buffer, "%d", aux);
					strcat(instruction, buffer);*/
					break; //Tira qnd souber fazer
				}
				printf("%s", instruction);
                break;
			default:
			break;

		}

		printf("\n");
	}

}
