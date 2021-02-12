#include "DECODER_THUMB.h"
void printIntruction(FILE *f,  char* instruction){

	f = fopen("code.txt","a");

	if(f == 0)
	  printf("Não foi possivel escrever o arquivo!");

	fprintf(f,"%s\n", instruction);
	fclose(f);
}

void calc_immed8_mov(char caracter3, char caracter4, char* instruction){
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
    if(caracter4 == '0'){
		strcat(instruction, ", #96");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #97");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #98");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #99");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #100");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #101");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #102");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #103");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #104");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #105");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #106");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #107");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #108");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #109");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #110");
	  }else{
		strcat(instruction, ", #111");
	  }
	  break;
    case '7':
      if(caracter4 == '0'){
		strcat(instruction, ", #112");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #113");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #114");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #115");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #116");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #117");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #118");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #119");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #120");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #121");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #122");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #123");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #124");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #125");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #126");
	  }else{
		strcat(instruction, ", #127");
	  }
    break;
    case '8':
      if(caracter4 == '0'){
		strcat(instruction, ", #128");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #129");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #130");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #131");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #132");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #133");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #134");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #135");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #136");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #137");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #138");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #139");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #140");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #141");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #142");
	  }else{
		strcat(instruction, ", #143");
	  }
    break;
    case '9':
      if(caracter4 == '0'){
		strcat(instruction, ", #144");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #145");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #146");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #147");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #148");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #149");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #150");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #151");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #152");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #153");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #154");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #155");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #156");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #157");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #158");
	  }else{
		strcat(instruction, ", #159");
	  }
    break;
    case 'a':
      if(caracter4 == '0'){
		strcat(instruction, ", #160");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #161");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #162");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #163");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #164");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #165");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #166");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #167");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #168");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #169");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #170");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #171");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #172");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #173");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #174");
	  }else{
		strcat(instruction, ", #175");
	  }
    break;
    case 'b':
        if(caracter4 == '0'){
		strcat(instruction, ", #176");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #177");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #178");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #179");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #180");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #181");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #182");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #183");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #184");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #185");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #186");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #187");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #188");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #189");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #190");
	  }else{
		strcat(instruction, ", #191");
	  }
    break;
    case 'c':
    if(caracter4 == '0'){
		strcat(instruction, ", #192");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #193");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #194");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #195");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #196");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #197");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #198");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #199");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #200");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #201");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #202");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #203");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #204");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #205");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #206");
	  }else{
		strcat(instruction, ", #207");
	  }
    break;
    case 'd':
    if(caracter4 == '0'){
		strcat(instruction, ", #208");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #209");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #210");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #211");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #212");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #213");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #214");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #215");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #216");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #217");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #218");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #219");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #220");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #221");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #222");
	  }else{
		strcat(instruction, ", #223");
	  }
    break;
    case 'e':
    if(caracter4 == '0'){
		strcat(instruction, ", #224");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #225");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #226");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #227");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #228");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #229");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #230");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #231");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #232");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #233");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #234");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #235");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #236");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #237");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #238");
	  }else{
		strcat(instruction, ", #239");
	  }
    break;
    case 'f':
    if(caracter4 == '0'){
		strcat(instruction, ", #240");
	  }else if(caracter4 == '1'){
		strcat(instruction, ", #241");
	  }else if(caracter4 == '2'){
		strcat(instruction, ", #242");
	  }else if(caracter4 == '3'){
		strcat(instruction, ", #243");
	  }else if(caracter4 == '4'){
		strcat(instruction, ", #244");
	  }else if(caracter4 == '5'){
		strcat(instruction, ", #245");
	  }else if(caracter4 == '6'){
		strcat(instruction, ", #246");
	  }else if(caracter4 == '7'){
		strcat(instruction, ", #247");
	  }else if(caracter4 == '8'){
		strcat(instruction, ", #248");
	  }else if(caracter4 == '9'){
		strcat(instruction, ", #249");
	  }else if(caracter4 == 'a'){
		strcat(instruction, ", #250");
	  }else if(caracter4 == 'b'){
		strcat(instruction, ", #251");
	  }else if(caracter4 == 'c'){
		strcat(instruction, ", #252");
	  }else if(caracter4 == 'd'){
		strcat(instruction, ", #253");
	  }else if(caracter4 == 'e'){
		strcat(instruction, ", #254");
	  }else{
		strcat(instruction, ", #255");
	  }
    break;
  }
}

void printMem(FILE *f,  char* instruction){

  	f = fopen("code.txt","a");

  	if(f == 0)
		printf("Não foi possivel escrever o arquivo!");

  	fprintf(f,"%s   ", instruction);
  	fclose(f);
}

/*char* lerLinha(FILE *entrada) {
	char* conteudo[5];
	char c;
  	entrada = fopen("entrada.txt", "r");
  	if(entrada == 0){
		printf("nao abriu");
		exit(EXIT_FAILURE);
	}
	int i=0;
	while (!feof(entrada)){
        fscanf(entrada,"%c",&c);
		if(c == '\n') break;
        *conteudo[i] = c;
		i++;
    }
	*conteudo[i+1] = '\0';
	fclose(entrada);
	return *conteudo;
}*/

void instructionDecoder(char* opcode){

	FILE* saida;
	char* ptr;
	long int intInstruction;
	char instruction[30];
	char buffer[4];
	int aux;
	scanf("%[^\n]", opcode);
	printMem(saida, opcode); //escreve no arquivo o numero hexa
	intInstruction = strtol(opcode, &ptr, 16); //string to int
	switch (intInstruction >> 12 & 0xF){
	case 3:
		if((intInstruction >> 11) & 0x1) {
			strcpy(instruction, "sub");
		}
		else {
			strcpy(instruction, "add");
		}
		strcat(instruction, " r");
		aux = (intInstruction >> 8) & 0x7; //descobrindo qual register r0-r7
		sprintf(buffer, "%d", aux);  //int to int
		strcat(instruction, buffer); 
		strcat(instruction, ", #");
		aux = (intInstruction & 0xFF); //imediato
		sprintf(buffer, "%d", aux);
		strcat(instruction, buffer);
        printIntruction(saida, instruction); //escreve no arquivo
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
		printIntruction(saida, instruction);
		break;
	default:
		break;
	}
	printf("%s\n", instruction);
	//printf("%x\n", aux);
	//sprintf(buffer, "%d", aux);
	//printf("%s", buffer);

}

/*char*  itoa ( int value, char * str ) {
    char temp;
    int i =0;
    while (value > 0) {
        int digito = value % 10;

        str[i] = digito + '0';
        value /= 10;
        i++;
    }
   i = 0;
   int j = strlen(str) - 1;

   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
    return str;
}*/