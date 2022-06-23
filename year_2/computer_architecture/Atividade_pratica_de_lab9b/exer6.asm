.data
text1: .asciiz "Insira o valor de n: "
text2: .asciiz "O valor de Fibonacci para o n digitado é: "
text3: .asciiz "O valor de Fibonacci para o n digitado é: 0"

.text

main:
    jal leitura
    move $a0, $v0 #armazena $v0 em $a0
    jal fibonacci 
    move $a1, $v0 #armazena $v0 em $a1
    jal escritaRes 
    li $v0, 10
    syscall

#funcao  le um int n
leitura:
    la $a0, text1 
    li $v0, 4 
    syscall 
    li $v0, 5 
    syscall 
    beq $v0, 0, igualAZero #verifica se o numero inserido � igual a 0
    jr $ra 

#funcao imprime o resultado
escritaRes:
    la $a0, text2 
    li $v0, 4 
    syscall 
    li $v0, 1 
    move $a0, $a1 
    syscall 
    jr $ra 


#funcao recursiva calcula fibonacci
fibonacci:
    addi $sp, $sp, -12 
    sw $ra, 8($sp)    
    sw $s0, 4($sp)     
    sw $s1, 0($sp)     
    move $s0, $a0
    li $v0, 1 
    ble $s0, 0x2, fibonacciExit 
    addi $a0, $s0, -1 
    jal fibonacci 
    move $s1, $v0 
    addi $a0, $s0, -2 
    jal fibonacci 
    add $v0, $s1, $v0

fibonacciExit:
    lw $ra, 8($sp)     
    lw $s0, 4($sp) 
    lw $s1, 0($sp)
    addi $sp, $sp, 12 
    jr $ra #volta para a main

#funcao retorna 0  quando o valor  inserido for 0
igualAZero:
    la $a0, text3
    li $v0, 4 
    syscall 
    li $v0, 10 
    syscall 
