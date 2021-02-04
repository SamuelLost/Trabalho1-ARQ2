#include "DECODE_ARM.h"
void printIntruction(FILE *f,  char* intruction){

    f = fopen("code.txt","w");

    if(f == 0)
      printf("Não foi possivel escrever o arquivo!");
    
    fprintf(f,"%s\n", intruction);
    fclose(f);
}