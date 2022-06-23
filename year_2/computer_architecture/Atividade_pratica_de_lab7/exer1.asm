.data 
Mat: .space 48 #3x3*4(interio)
vet1: .space 12
vet2: .space 16
Ent1: .asciiz "Insira o valor["
Ent2: .asciiz"]["
Ent3: .asciiz"]:"
Sai1: .asciiz "["
Sai2: .asciiz " ]"
Sai3: .asciiz ","

.text
main: 	la $a0,Mat
	li $a1,4
	li $a2,3
	jal leitura
	move $t8,$v0
	la $a0, vet1
	li $a1,3
	li $a2,1
	jal leitura
	move $t9,$v0
	jal multiplica
	jal impressao
	li $v0,10
	syscall
	
indice:
	mul $v0,$t0,$a2
	add $v0,$v0,$t1
	sll $v0,$v0,2
	add $v0,$v0,$a3
	jr $ra
	
leitura:
	subi $sp,$sp,4
	sw $ra,($sp)
	move $a3,$a0
l:	la $a0,Ent1
	li $v0,4
	syscall
	move $a0,$t0
	li $v0,1
	syscall
	la $a0,Ent2
	li $v0,4
	syscall
	move $a0,$t1
	li $v0,1
	syscall
	la $a0,Ent3
	li $v0,4
	syscall
	li $v0,5
	syscall
	move $t2,$v0
	jal indice
	sw $t2,($v0)
	addi $t1,$t1,1
	blt $t1,$a2,l
	li $t1,0
	addi $t0,$t0,1
	blt $t0,$a1,l
	li $t0,0
	lw $ra,($sp)
	addi $sp,$sp,4
	move $v0,$a3
	jr $ra
		

multiplica: 
	move $t0, $t8 #move $t0 pra $t8
	move $t1, $t9 #move $t1 pra $t9
	la $t2, vet2 #carrega endereço do resultado em $t2
loop:	lw $s0, ($t0) #carrega valor $t0 em $s0
	lw $s1, ($t1) #carrega valor  $t1 em $s1
	mul $t3, $s0, $s1 # multiplica dos valores e armazenada em $t3
	add $t4, $t4, $t3 #$t4=+$t4
	bgt $t6, 1, next #testa se ja chegou no final da linha
	addi $t0, $t0, 4 #add 4 ao contador
	addi $t1, $t1, 4 #idem
	addi $t6, $t6, 1 #adiciona 1 no contador
	j loop
next:	li $t6, 0 #zera o contador
	sw $t4, ($t2) #armazena o resultado em  $t2
	li $t4, 0 #zera o acumulador em $t4
	move $t1, $t9 #carrega o endereço vetor
	addi $t0, $t0, 4 #aumenta 4 no indice 
	addi $t2, $t2, 4 #aumenta o indice da matrix resultante
	addi $t7, $t7, 1 #soma 1 ao contador de linhas
	blt $t7, 4, loop #testa se ja chegou no fim da matriz
	jr $ra 



impressao:
	la $a0,Sai1
	li $v0,4
	syscall
	li $t0, 0
	la $a1, vet2
impr:	lw $a0, ($a1)
	li $v0, 1
	syscall
	la $a0,Sai3
	li $v0,4
	syscall
	addi $a1, $a1, 4
	addi $t0, $t0, 1
	blt $t0, 4, impr
	la $a0,Sai2
	li $v0,4
	syscall
	jr $ra
	
