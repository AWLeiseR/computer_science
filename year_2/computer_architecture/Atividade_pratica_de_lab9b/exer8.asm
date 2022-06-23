.data
text1: .asciiz "Insira o valor de n: "
text2: .asciiz "Insira o valor de p: "
output: .asciiz "Resultado: "

.text

main:
     jal leitura 
     jal calculo 
     li $v0, 10 
     syscall 


leitura:
    
    la $a0, text1 
    li $v0, 4 
    syscall 
    li $v0, 5 
    syscall 
    move $a2, $v0 
    la $a0, text2
    li $v0, 4 
    syscall 
    li $v0, 5 
    syscall 
    move $a1, $v0 
    move $a0, $a2 
    
    jr $ra 
    
#funcao de arranjo
calculo:

    sub $a3, $a0, $a1 #$a3 diferença de N e P 
    blez $a3, fail #teste se é possivel fazer o calculo
    move $t2, $a0  # t2 recebe N
loop:
    sub $a0, $a0, 1 # a0 recebe N - 1
    beq $a3, $a0, final #se $a0 == $a3, fim
    mul $t2, $t2, $a0 # senao multiplica o acumulador em $t2 com $a0 (res = res * (($a0) -1)))
    j loop 
    
fail:
    li $t2, -1 
      
final:

    la $a0, output 
    li $v0, 4 
    syscall 
    move $a0, $t2 
    li $v0, 1 
    syscall 
    jr $ra 
    
    
    
