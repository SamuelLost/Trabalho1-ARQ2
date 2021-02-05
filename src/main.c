#include "DECODE_ARM.h"

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
      printIntruction(f, "mov");
      break;
    default:
      break;
    }
    read(STDIN_FILENO, charPtr, 1);
  }
  return 0;
}
