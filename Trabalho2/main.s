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
        ldr r2, =0x1FF  @mode - como se fosse chmod 777
        ldr r1, =0x241  @flag
        ldr r0, =nomeArquivoOutput
        swi #0

        mov r9, r0      @fd de destino

        mov r2, #1
        ldr r1, =varTemp

readByteFromFileOrigem:
        mov r7, #3      @read
        mov r0, r8      @fd de origem
        swi #0
        cmp r0, #0      @É o fim do arquivo ?
        ble fim
writeByteToFileDesti:
        mov r7, #4      @write
        mov r0, r9      @fd de destino
        swi #0
        b readByteFromFileOrigem
fim:
        mov r7, #1      @exit
        mov r0, #0      @Return 0
        swi #0

.data
.balign 4
varTemp:                .BYTE 1
nomeArquivoInput:       .asciz "fileInput.txt"
nomeArquivoOutput:      .asciz "fileOutput.txt"