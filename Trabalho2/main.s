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

        ldr r1, =fieldIN
        ldr r0, [r1]
        ldr r1, =Array
        mov r2, #50
        mov r7, #3
        swi 0

        ldr r1, =size
        str r0, [r1]

.balign 4
fieldIN:                .skip 4
fieldOUT:               .skip 4
Array:                  .skip 50
size:                   .skip 4

fileDestination:        .asciz "file-out.txt"
fileOrigem:             .asciz "file-in.txt"