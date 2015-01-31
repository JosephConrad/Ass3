@Konrad Lisiecki 291649
.text
.global changeColour

.balign 4

changeColour:                       @ w r2 trzymam i
    mul r1, r2, r1                  @ mnoze x*y
    mov r2, #0   

FOR_LOOP:                           @ r0 - adres, r1 - x, r2 - y

    cmp r2, r1
    beq KONIEC

    ldrb r3, [r0]                   @ pobranie skladowej do zmiany
    mov r4, #77
    mul r3, r4, r3

    ldrb r4, [r0, #+1]
    mov r5, #151 
    mla r4, r5, r4, r3

    ldrb r5, [r0, #+2] 
    mov r6, #28 
    mla r5, r6, r5, r4 

 
    mov r3, r5, asr #8              @ r3 = r5/r4

    strb r3, [r0]
    mov r4, #1
    strb r3, [r0,+r4]
    mov r4, #2 
    strb r3, [r0,+r4]

    mov r6, #3
    add r0, r6, r0
    
    add r2, r2, #1
    b FOR_LOOP

KONIEC:
    bx lr      