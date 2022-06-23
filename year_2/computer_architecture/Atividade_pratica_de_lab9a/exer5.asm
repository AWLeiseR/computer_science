.data
ent1: .asciiz "\nInsira o CPF: "
str1: .space 12
const: .word 1
res1: .asciiz "CPF valido\n"
res2: .asciiz "CPF invalido\n"
teste: .asciiz "\n Teste"
barra_n: .asciiz "\n"
.text
main:	la $a0, ent1 #lendo a String
	la $a1, str1
	la $s1, str1
	li $a2, 1 #cont letras
	jal leitura
	la $a1, str1
	la $s1, str1
	la $s2, str1
 	li $s5, 0
	li $s6, 0
	li $s7, 0
	j validarEntrada
parar:  bne $s5, 11, rer2
	move $s1, $a1
	li $t7, 11 #aux div
        li $t9, 10 #aux mult
        li $t8, 0 #soma total
        j converter
	
validarEntrada:
	lb  $t1, ($s1)
	bge $t1, 48, contadorEnt#checa se é realmente um numero  
	beq $t1, 45, contadorEnt 
continua:
	addi $s1, $s1, 1 
	add $s7, $s7, 1
	bge $s7, 11, parar
	j validarEntrada

contadorEnt:
	ble $t1, 57, contadorEnt2 
	j continua

contadorEnt2: 
	add $s5, $s5, 1
	j continua
	
converter:
	lb $t1, ($s1)      #carrega o char no t1
	blt $t1, 48, erro  
	bgt $t1, 57, erro  
	addi $t1, $t1, -48  #converte para decimal
	mul $t1, $t9, $t1 #mult
	add $t8, $t8, $t1 #add soma total
	sub $t9, $t9, 1
	beq $t9, $a2, validar
	addi $s1, $s1, 1
	j converter
	
validar: 
	div $t8, $t7
	mfhi $t9
	sub $t9, $t7, $t9
	bgt $t9, 9, converter2
	j converter3

converter2:
	li $a2, 2
	li $t2, 0
	li $t7, 11 #aux div
        li $t9, 11 #aux mult
        li $t8, 0 #zera variavel de soma total
        move $s1, $s2
conta:	lb $t1, ($s1)      1
	blt $t1, 48, erro2  
	bgt $t1, 57, erro2 
	addi $t1, $t1, -48  #converte em um valor decimal
	mul $t1, $t9, $t1 #mult
	add $t8, $t8, $t1 #add soma total
	sub $t9, $t9, 1
	beq $t9, $a2, validar2
	addi $s1, $s1, 1
	j conta
	
converter3:
	li $a2, 2
	move $t2, $t9
	move $t3, $t9
	mul  $t3, $t3, 2
	li $t7, 11 #aux div
        li $t9, 11 #aux mult
        li $t8, 0 # soma total
        move $s1, $s2
conta2:	lb $t1, ($s1)      
	blt $t1, 48, erro3 
	bgt $t1, 57, erro3 
	addi $t1, $t1, -48  
	mul $t1, $t9, $t1 
	add $t8, $t8, $t1 
	sub $t9, $t9, 1
	beq $t9, $a2, validar2
	addi $s1, $s1, 1
	j conta2
	
compOK:
	beq $t3, $t5, rer1
	j rer2

compOK2:
	beq $t9, $t5, rer1
	j rer2

validar2: 
	add $t8, $t8, $t3
	div $t8, $t7
	mfhi $t9
	sub $t9, $t7, $t9
	lb $t4, 10($a1)
	addi $t4, $t4, -48  
	lb $t5, 11($a1)
	addi $t5, $t5, -48  
	beq $t2, $t4, compOK2
	j rer2
rer1: 
	la $a0, res1
	li $v0, 4
	syscall
	li $v0, 10
	syscall
	
rer2: 
	la $a0, res2
	li $v0, 4
	syscall
	li $v0, 10
	syscall
	
erro:
	addi $s1, $s1, 1
	j converter
	
erro2:
	addi $s1, $s1, 1
	j converter2
	
erro3:
	addi $s1, $s1, 1
	j converter3


leitura: li $v0, 4
         syscall  
         move $a0, $a1
         li $a1, 15 
         li $v0, 8
         syscall
         jr $ra
