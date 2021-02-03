#include <stdio.h>
#include <unistd.h>

void printIntruction(FILE *f,  char* intruction){

    f = fopen("code.txt","w");

    if(f == 0)
      printf("Não foi possivel escrever o arquivo!");
    
    fprintf(f,"%s\n", intruction);
    fclose(f);
}



int main(void)
{
  FILE *f;

  char intruction[20];    // Vetor que vai armazenar a tradução -> EX: mov r0, #3

  char aChar[4];
  char* charPtr = aChar;

  write(STDOUT_FILENO,"Digite uma sequência em Hexadecimal: ", 37);

  read(STDIN_FILENO, charPtr, 1);  
  while (*charPtr != '\n') {        
    switch (*charPtr)
    {
    case '2':
      printIntruction(f, "MOV");
      break;
    default:
      break;
    }
    read(STDIN_FILENO, charPtr, 1);
  }
  return 0;
}
