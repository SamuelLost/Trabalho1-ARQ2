@========================================================================
@			TRABALHO2 - ASCII TO UART
@ O PROGRAMA LÊ CARACTERES DE UM ARQUIVO DE ENTRADA E CONVERTE EM UART.
@ UART É COMPOSTO PELO BIT DE CONTROLE 0 QUE INDICA QUE A COMUNICAÇÃO FOI
@ INICIADA E O BIT DE CONTROLE 1 NO FINAL, INDICA QUE A COMUNICAÇÃO FOI
@ ENCERRADA. ALÉM DISSO, O BITS SAEM EM ORDEM CONTRÁRIA, OU SEJA, O
@ O CARACTERE 'a' --> 0x61 --> 0110 0001 EM UART FICARIA: 0100001101, 
@ SENDO O BIT 0 E 1 NO FINAL OS BITS DE CONTROLE.
@ A CADEIRA DE CARACTERES DEVE FICAR DENTRO DO ARQUIVO fileASCII.txt E O
@ UART É ESCRITO NO ARQUIVO fileBinario.txt
@========================================================================
.global main
.func main

main:
@Open InputFile
        mov r7, #5      	@open
        mov r2, #0      	@mode
        mov r1, #0      	@flag
        ldr r0, =nomeArquivoInput
        swi #0

        mov r8, r0      	@fd de origem

@Open OutputFile
        mov r7, #5
        ldr r2, =0x1FF  	@mode - como se fosse chmod 777
        ldr r1, =0x241  	@flag
        ldr r0, =nomeArquivoOutput
        swi #0

        mov r9, r0      	@fd de destino

readByte:			@READ fileInput.txt

	ldr r1, =varTemp
	mov r2, #1
        mov r7, #3      	@read
        mov r0, r8      	@fd de origem
        swi #0

        cmp r0, #0      	@LEU ALGUM BYTE? SE NÃO, PULA PARA fim
        ble fim

	eor r4, r4, r4
	eor r5, r5, r5

	ldr r0, =varTemp	@caractere lido
	ldrb r5, [r0]		@armazena o caractere lido em r5
	cmp r5, #0xA		@compara com um espaço
	beq readByte		@se for igual, lê o proximo caractere

	ldr r1, =buffer		@CARREGANDO O ENDEREÇO DE BUFFER

_bin:				@AQUI OCORRE A CONVERSÃO PARA BINÁRIO

	and r4, r5, #1		@AND COM O ULTIMO BIT
	add r4, r4, #'0'	@TRANSFORMANDO EM '0' OU '1'

	strb r4, [r1], #1	@SALVANDO NO ENDEREÇO DE BUFFER
				@COM POSTINDEX

	cmp r5, #0		@QUANDO O NUMERO CHEGAR EM 0
	beq _end		@SALTA PARA O FIM DO LOOP
	lsr r5, r5, #1		@r5 >> 1

	b _bin			@LOOP

_end:


writeByte:
	mov r7, #4		@PRINT DO BIT 0 NO INCIO
	ldr r1, =bitControle0
	mov r2, #1
	mov r0, r9		@FD de fileOutput.txt
	swi #0

	mov r2, #8
        mov r7, #4      	@write
        mov r0, r9      	@fd de destino
	ldr r1, =buffer 	@PRINTAR A STRING COM O BINÁRIO
        swi #0

	mov r7, #4		@PRINT DO BIT 1 NO FINAL
	ldr r1, =bitControle1
	mov r2, #1
	mov r0, r9		@FD de fileOutput.txt
	swi #0

        b readByte		@LÊ OUTRO CARACTERE

fim:

				@CLOSE INPUTFILE
	mov r7, #6
	mov r0, r8
	swi #0

				@CLOSE OUTPUTFILE
	mov r7, #6
	mov r0, r9
	swi #0

        mov r7, #1      	@exit
        mov r0, #0      	@Return 0
        swi #0

.data
.balign 4
buffer:			.skip	8
varTemp:                .byte 	1
bitControle0:		.asciz	"0"
bitControle1:		.asciz	"1"
nomeArquivoInput:       .asciz "fileASCII.txt"
nomeArquivoOutput:      .asciz "fileBinarioUART.txt"
