#include "DECODE_ARM.h"
void printIntruction(FILE *f,  char* instruction){

    f = fopen("code.txt","a");

    if(f == 0)
      printf("Não foi possivel escrever o arquivo!");

    fprintf(f,"%s\n", instruction);
    fclose(f);
}

void calc_immed8(char caracter3, char caracter4, char* instruction){
  switch (caracter3){
    case '0':
      if(caracter4 == '0'){
        strcat(instruction, ", #0");
      }else if(caracter4 == '1'){
        strcat(instruction, ", #1");
      }else if(caracter4 == '2'){
        strcat(instruction, ", #2");
      }else if(caracter4 == '3'){
        strcat(instruction, ", #3");
      }else if(caracter4 == '4'){
        strcat(instruction, ", #4");
      }else if(caracter4 == '5'){
        strcat(instruction, ", #5");
      }else if(caracter4 == '6'){
        strcat(instruction, ", #6");
      }else if(caracter4 == '7'){
        strcat(instruction, ", #7");
      }else if(caracter4 == '8'){
        strcat(instruction, ", #8");
      }else if(caracter4 == '9'){
        strcat(instruction, ", #9");
      }else if(caracter4 == 'a'){
        strcat(instruction, ", #10");
      }else if(caracter4 == 'b'){
        strcat(instruction, ", #11");
      }else if(caracter4 == 'c'){
        strcat(instruction, ", #12");
      }else if(caracter4 == 'd'){
        strcat(instruction, ", #13");
      }else if(caracter4 == 'e'){
        strcat(instruction, ", #14");
      }else{
        strcat(instruction, ", #15");
      }
      break;
      case '1':
      if(caracter4 == '0'){
        strcat(instruction, ", #16");
      }else if(caracter4 == '1'){
        strcat(instruction, ", #17");
      }else if(caracter4 == '2'){
        strcat(instruction, ", #18");
      }else if(caracter4 == '3'){
        strcat(instruction, ", #19");
      }else if(caracter4 == '4'){
        strcat(instruction, ", #20");
      }else if(caracter4 == '5'){
        strcat(instruction, ", #21");
      }else if(caracter4 == '6'){
        strcat(instruction, ", #22");
      }else if(caracter4 == '7'){
        strcat(instruction, ", #23");
      }else if(caracter4 == '8'){
        strcat(instruction, ", #24");
      }else if(caracter4 == '9'){
        strcat(instruction, ", #25");
      }else if(caracter4 == 'a'){
        strcat(instruction, ", #26");
      }else if(caracter4 == 'b'){
        strcat(instruction, ", #27");
      }else if(caracter4 == 'c'){
        strcat(instruction, ", #28");
      }else if(caracter4 == 'd'){
        strcat(instruction, ", #29");
      }else if(caracter4 == 'e'){
        strcat(instruction, ", #30");
      }else{
        strcat(instruction, ", #31");
      }
      break;
      case '2':
        if(caracter4 == '0'){
        strcat(instruction, ", #32");
      }else if(caracter4 == '1'){
        strcat(instruction, ", #33");
      }else if(caracter4 == '2'){
        strcat(instruction, ", #34");
      }else if(caracter4 == '3'){
        strcat(instruction, ", #35");
      }else if(caracter4 == '4'){
        strcat(instruction, ", #36");
      }else if(caracter4 == '5'){
        strcat(instruction, ", #37");
      }else if(caracter4 == '6'){
        strcat(instruction, ", #38");
      }else if(caracter4 == '7'){
        strcat(instruction, ", #39");
      }else if(caracter4 == '8'){
        strcat(instruction, ", #40");
      }else if(caracter4 == '9'){
        strcat(instruction, ", #41");
      }else if(caracter4 == 'a'){
        strcat(instruction, ", #42");
      }else if(caracter4 == 'b'){
        strcat(instruction, ", #43");
      }else if(caracter4 == 'c'){
        strcat(instruction, ", #44");
      }else if(caracter4 == 'd'){
        strcat(instruction, ", #45");
      }else if(caracter4 == 'e'){
        strcat(instruction, ", #46");
      }else{
        strcat(instruction, ", #47");
      }
      break;
      case '3':
        if(caracter4 == '0'){
        strcat(instruction, ", #48");
      }else if(caracter4 == '1'){
        strcat(instruction, ", #49");
      }else if(caracter4 == '2'){
        strcat(instruction, ", #50");
      }else if(caracter4 == '3'){
        strcat(instruction, ", #51");
      }else if(caracter4 == '4'){
        strcat(instruction, ", #52");
      }else if(caracter4 == '5'){
        strcat(instruction, ", #53");
      }else if(caracter4 == '6'){
        strcat(instruction, ", #54");
      }else if(caracter4 == '7'){
        strcat(instruction, ", #55");
      }else if(caracter4 == '8'){
        strcat(instruction, ", #56");
      }else if(caracter4 == '9'){
        strcat(instruction, ", #57");
      }else if(caracter4 == 'a'){
        strcat(instruction, ", #58");
      }else if(caracter4 == 'b'){
        strcat(instruction, ", #59");
      }else if(caracter4 == 'c'){
        strcat(instruction, ", #60");
      }else if(caracter4 == 'd'){
        strcat(instruction, ", #61");
      }else if(caracter4 == 'e'){
        strcat(instruction, ", #62");
      }else{
        strcat(instruction, ", #63");
      }
      break;
      case '4':
        if(caracter4 == '0'){
        strcat(instruction, ", #64");
      }else if(caracter4 == '1'){
        strcat(instruction, ", #65");
      }else if(caracter4 == '2'){
        strcat(instruction, ", #66");
      }else if(caracter4 == '3'){
        strcat(instruction, ", #67");
      }else if(caracter4 == '4'){
        strcat(instruction, ", #68");
      }else if(caracter4 == '5'){
        strcat(instruction, ", #69");
      }else if(caracter4 == '6'){
        strcat(instruction, ", #70");
      }else if(caracter4 == '7'){
        strcat(instruction, ", #71");
      }else if(caracter4 == '8'){
        strcat(instruction, ", #72");
      }else if(caracter4 == '9'){
        strcat(instruction, ", #73");
      }else if(caracter4 == 'a'){
        strcat(instruction, ", #74");
      }else if(caracter4 == 'b'){
        strcat(instruction, ", #75");
      }else if(caracter4 == 'c'){
        strcat(instruction, ", #76");
      }else if(caracter4 == 'd'){
        strcat(instruction, ", #77");
      }else if(caracter4 == 'e'){
        strcat(instruction, ", #78");
      }else{
        strcat(instruction, ", #79");
      }
      break;
      case '5':
        if(caracter4 == '0'){
        strcat(instruction, ", #80");
      }else if(caracter4 == '1'){
        strcat(instruction, ", #81");
      }else if(caracter4 == '2'){
        strcat(instruction, ", #82");
      }else if(caracter4 == '3'){
        strcat(instruction, ", #83");
      }else if(caracter4 == '4'){
        strcat(instruction, ", #84");
      }else if(caracter4 == '5'){
        strcat(instruction, ", #85");
      }else if(caracter4 == '6'){
        strcat(instruction, ", #86");
      }else if(caracter4 == '7'){
        strcat(instruction, ", #87");
      }else if(caracter4 == '8'){
        strcat(instruction, ", #88");
      }else if(caracter4 == '9'){
        strcat(instruction, ", #89");
      }else if(caracter4 == 'a'){
        strcat(instruction, ", #90");
      }else if(caracter4 == 'b'){
        strcat(instruction, ", #91");
      }else if(caracter4 == 'c'){
        strcat(instruction, ", #92");
      }else if(caracter4 == 'd'){
        strcat(instruction, ", #93");
      }else if(caracter4 == 'e'){
        strcat(instruction, ", #94");
      }else{
        strcat(instruction, ", #95");
      }
      break;
      case '6':

      break;
  }
}
