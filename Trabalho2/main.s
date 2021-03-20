.global main
.func main

main:

@Open FileOrigem
        mov r7, #5
        ldr r0, =fileOrigem
        mov r1, #0
        mov r2, #0
        swi 0

        ldr r1, =fieldIN
        str r0, [r1]

@Open fileDestination
        mov r7, #5
        ldr r0, =fileDestination
        mov r1, #0101
        mov r2, #384
        swi 0

        ldr r1, =fieldOUT
        str r0, [r1]

@read fileOrigem
        ldr r1, =fieldIN
        ldr r0, [r1]
        ldr r1, =Array
        mov r2, #1      @ number of bytes to read
        mov r7, #3      @ system call read
        swi 0           @ read the file to Array

        ldr r1, =size
        str r0, [r1]

        ldr r0, =InString       @r0 points to InString
        ldr r1, =OutString      @r1 points to OutString

_readByte:
        ldrb r2, [r0], #1       @get byte and increment InString

                        @if is eof so goes to write

_storeByte:
        strb r2, [r1], #1
        cmp r2, #0
        bne _readByte
 
.data
.balign 4
fieldIN:                .skip 4
fieldOUT:               .skip 4
Array:                  .skip 50
size:                   .skip 100

InString:               .skip 150
OutString:              .skip 150
fileDestination:        .asciz "file-out.txt"
fileOrigem:             .asciz "file-in.txt"