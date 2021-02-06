#include "DECODE_ARM.h"
void printIntruction(FILE *f,  char* instruction){

    f = fopen("code.txt","a");

    if(f == 0)
      printf("Não foi possivel escrever o arquivo!");

    fprintf(f,"%s\n", instruction);
    fclose(f);
}
