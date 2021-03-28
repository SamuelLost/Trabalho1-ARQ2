@- Crie o arquivo fileInput.txt
@- Coloque o código binário no formato do protocolo UART dentro do arquivo
@- Ao final da sequência, adicione o caracter ")".
@- EX: 0100001101001000110101100011010001001101)
.global main
.func main

main:
@Open FileOrige
        mov r7, #5      @open
        mov r2, #0      @mode
        mov r1, #0      @flag
        ldr r0, =nomeArquivoInput
        swi #0

        mov r8, r0      @fd de origem
@Open fileDest
        mov r7, #5
        ldr r2, =0x1FF          @mode - como se fosse chmod 777
        ldr r1, =0x241          @flag
        ldr r0, =nomeArquivoOutput
        swi #0

        mov r9, r0              @fd de destino

        mov r2, #1              @Quantidade de bytes a ser lido do arquivo
        ldr r1, =varTemp        @Variavel que contém o byte lido
        

readFirstByteFromFileOrigem:
        @contador responsavel por dizer em qual bit estar.
        mov r6, #0              
        @myChar será responsavel por armazenar o asci em binário
        ldr r13, =myChar        
        @System call para verificar os bits de controle
        mov r7, #3              @read
        mov r0, r8              @fd de origem
        swi #0
        @Verificar se tem mais algum char no arquivo
        ldr r10, [r1]           @r1 contém o valor obtido do arquivo
        cmp r10, #0x29          
        beq fim
        b verificarBitControle
iniciarTransmissao:
        add r6, r6, #1
        cmp r6, #9
        beq realizarRotacao
        mov r7, #3              @read
        mov r0, r8              @fd de origem
        swi #0
        
        @passando para myChar
        ldrb r3, [r1]
        strb r3, [r13]
        add r13, r13, #1
        b iniciarTransmissao

verificarBitControle:
        @Verifico se o bit de controle é 1
        ldr r12, [r1]          @r1 contém o valor obtido do arquivo
        cmp r12, #0x31
        beq readFirstByteFromFileOrigem
        @verifico se o bit de controle é 0
        cmp r6, #0
        beq iniciarTransmissao

realizarRotacao:
        ldr r6, =myChar
        ldr r7, =myCharRot
        mov r11, #7     @contador
loopRotacao:
        ldrb r3, [r6, r11]
        strb r3, [r7]
        add r7, r7, #1
        cmp r11, #0
        beq converterToAscii
        sub r11, r11, #1 
        b loopRotacao
        

converterToAscii:
        @Iniciando para a conversão
        ldr r6, =myCharRot     @myChar contém o binário do ascii. Ex: 01100001
        mov r10, #0         @contador
        mov r11, #0         @r11 vai armazenar o caracter ascii.
        b loop
loop:
        @Pegando 1 bit de myChar
        ldrb r13, [r6], #1
        
        sub r13, r13, #48      @ convertendo '0' or '1' to 0 or 1 to a bit
        lsl r11, r11, #1       @ byte<<1
        add r11, r11, r13      @ byte+=bit
        
        add r10, r10, #1       @incrementando contador
        cmp r10, #7            @verifico se cheguei no 8 bit
        beq writeByteToFileDesti
        b loop
        
writeByteToFileDesti:
        ldr r10, =valueChar   @valueChar contém o caracter Ex: 0x61
        strb r11, [r10]
        mov r1, r10
        mov r7, #4            @write
        mov r0, r9            @fd de destino
        swi #0
        b readFirstByteFromFileOrigem

fim:
        mov r7, #1      @exit
        mov r0, #0      @Return 0
        swi #0

.data
.balign 4
nomeArquivoInput:       .asciz "fileInput.txt"
nomeArquivoOutput:      .asciz "fileOutput.txt"
varTemp:                .BYTE 2
myChar:                 .skip 50
myCharRot:              .skip 50
valueChar:              .BYTE 2
