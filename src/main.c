#include "DECODE_ARM.h"

int main(void)
{
  FILE *f;

  char instruction[10];    // Vetor que vai armazenar a tradução -> EX: mov r0, #3

  char string_in[4];

  printf("Digite uma sequencia\n");
  scanf("%[^\n]", string_in);

  switch (string_in[0]){
  case '2':
    strcat(instruction, "mov");
    if(string_in[1] == '0'){
      strcat(instruction, ", r0");
    }else if(string_in[1] == '1'){
      strcat(instruction, ", r1");
    }else if(string_in[1] == '2'){
      strcat(instruction, ", r2");
    }else if(string_in[1] == '3'){
      strcat(instruction, ", r3");
    }else if(string_in[1] == '4'){
      strcat(instruction, ", r4");
    }else if(string_in[1] == '5'){
      strcat(instruction, ", r5");
    }else if(string_in[1] == '6'){
      strcat(instruction, ", r6");
    }else {
      strcat(instruction, ", r7");
    }
    break;

  default:
    break;
  }

  printIntruction(f, instruction);
  return 0;
}
