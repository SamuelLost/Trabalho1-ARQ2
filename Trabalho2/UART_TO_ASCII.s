.global main
.func main

main:
@-------------------------------------------------------------------
@    Abrindo arquivo de entrada
@-------------------------------------------------------------------
        mov r7, #5              @open 
        mov r2, #0              @mode
        mov r1, #0              @flag
        ldr r0, =inputFileName
        swi #0
        mov r8, r0              @file description of inputFile
@-------------------------------------------------------------------
@    Abrindo arquivo de saída
@-------------------------------------------------------------------
        mov r7, #5
        ldr r2, =0x1FF          @mode - permissão total
        ldr r1, =0x241          @flag   create and trunc
        ldr r0, =outputFilename
        swi #0
        mov r9, r0              @file description do outputFile
@-------------------------------------------------------------------
@    Realizando a leitura byte po byte do arquivo de entrada
@-------------------------------------------------------------------
        mov r2, #1              @quantidade de byte
        ldr r1, =varTemp        @vatTemp vai armazenar o byte lido
lerNovoByte:
        mov r6, #0              @contador              
        ldr r13, =myBinario     @myBinario será responsavel por armazenar o asci em binário
        
        mov r7, #3              @read
        mov r0, r8              @fd de origem
        swi #0
        
        cmp r0, #0              @É o fim do arquivo ?
        ble fim
       
        @Verificar se tem mais algum char no arquivo
        ldr r10, [r1]           @r1 contém o valor obtido do arquivo
        cmp r10, #0xA          
        beq lerNovoByte
        b verificarBitControle
@-------------------------------------------------------------------
@    Copiando cada bit para myBinario
@-------------------------------------------------------------------
iniciarTransmissao:
        add r6, r6, #1          @incrementando o contado
        cmp r6, #9              @verifico se o contador é igual a 9
        beq realizarRotacao
        
        mov r7, #3              @read
        mov r0, r8              @fd de origem
        swi #0
        
        @passando para myBinario
        ldrb r3, [r1]
        strb r3, [r13]
        add r13, r13, #1
        b iniciarTransmissao
@-------------------------------------------------------------------
@    Verifica se estou no inicio o no fim da transmissão 
@-------------------------------------------------------------------
verificarBitControle:
        @Verifico se o bit de controle é 1
        ldr r12, [r1]           @r1 contém o valor obtido do arquivo
        cmp r12, #0x31          @0x31 -> '1'
        beq lerNovoByte
        @verifico se o bit de controle é 0
        cmp r6, #0
        beq iniciarTransmissao

@-------------------------------------------------------------------
@    Realizando a inversão para a sequencia binária correta
@    EX: Recebo 10000110 e converto para 01100001(a)
@-------------------------------------------------------------------
realizarRotacao:
        ldr r6, =myBinario      @contém o binário no formato do protoco UART
        ldr r7, =myBinarioRot   @vai armazenar o binário do ASCII correto
        mov r11, #7             @contador 
loopRotacao:
        ldrb r3, [r6, r11]      @pego o valor de myBinario.
        strb r3, [r7]           @copio para myBinarioRot
        add r7, r7, #1          @incremento o ponteito de myBinario
        cmp r11, #0             @cheguei no fim de MyBinario ?
        beq converterToAscii    
        sub r11, r11, #1        @decremento o contador
        b loopRotacao           
        
@-------------------------------------------------------------------
@    Realiza a conversão do binário para seu respectivo caracter
@    EX: Recebo 01100001 e converto para "a".
@-------------------------------------------------------------------
converterToAscii:
        ldr r6, =myBinarioRot     @myBinario contém o binário do ascii. Ex: 01100001
        mov r10, #0               @contador
        mov r11, #0               @r11 vai armazenar o caracter ascii.
        b loop
loop:
        @Pegando 1 bit de myBinario
        ldrb r13, [r6], #1
        
        sub r13, r13, #48         @ convertendo '0' or '1' to 0 or 1 to a bit
        lsl r11, r11, #1          @ byte<<1
        add r11, r11, r13         @ byte+=bit
        
        add r10, r10, #1          @incrementando contador
        cmp r10, #8               @verifico se cheguei no 8 bit
        beq writeByteToFileDesti
        b loop
@-------------------------------------------------------------------
@    Realiza a escrita do caracter no arquivo de saída
@-------------------------------------------------------------------
writeByteToFileDesti:
        ldr r10, =valueChar       @valueChar é uma auxiliar  
        strb r11, [r10]           @armazenando o caracter em r10
        
        mov r1, r10               @arg da system call
        mov r7, #4                @write
        mov r0, r9                @fd de destino
        swi #0
        b lerNovoByte

@-------------------------------------------------------------------
@    Fim do programa. Fechando cada arquivo aberto e realizando uma
@    system call exit.
@-------------------------------------------------------------------
fim:
        @close fileOrigem
        mov r7, #6                @close
        mov r0, r8                @r8 contém fd do arquivo de entrada
        swi #0
        
        @close fileDest
        mov r7, #6                @close
        mov r0, r9                @r9 contém fd do arquivo de entrada
        swi #0
        
        @exit
        mov r7, #1      @exit
        mov r0, #0      @Return 0
        swi #0

.data
.balign 4
inputFileName:       .asciz "fileBinarioUART.txt"
outputFilename:      .asciz "fileOutASCII.txt"
varTemp:                .BYTE 2
myBinario:              .skip 50
myBinarioRot:           .skip 50
valueChar:              .BYTE 2