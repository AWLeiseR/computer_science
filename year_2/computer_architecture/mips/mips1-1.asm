.data
Vet:	.space 12 #3x1 inteiros
Res:	.space 16 #4x1 inteiros
Ent1:	.asciiz "Insira o os indices i e j da matriz:\n"
Ent2:	.asciiz "Insira os "
Ent3:	.asciiz " elementos da matriz\n"
Ent4:	.asciiz "\nLinhas nulas: \n"
Ent5:	.asciiz "Colunas Nulas: "

.text
main:	jal leTamanho
	mul $a0, $s0, $s1
	sll $a0, $a0, 2
	jal malloc
	move $s2, $v0
	move $a0, $s2
	move $a1, $s0
	move $a2, $s1
	jal leitura
	move $a0, $s2
	jal escrita
	move $a0, $s2
	jal linColNulas
	li $v0, 10
	syscall
	
leTamanho:
	la $a0, Ent1
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s0, $v0
	li $v0, 5
	syscall
	move $s1, $v0
	jr $ra	
	
malloc:
	li $v0, 9
	syscall
	jr $ra
	
indice:
	mul $v0, $t0, $a2
	add $v0, $v0, $t1
	sll $v0, $v0, 2
	add $v0, $v0, $a3
	jr $ra
	
leitura:
	mul $t0, $a1, $a2
	add $t1, $zero, $zero
	subi $sp, $sp, 4 #espaço para 1 int na stack
	sw $ra, ($sp)
	move $a3, $a0
	la $a0, Ent2
	li $v0, 4
	syscall
	move $a0, $t0
	li $v0, 1
	syscall
	la $a0, Ent3
	li $v0, 4
	syscall
	add $t0, $zero, $zero
le:	li $v0, 5
	syscall
	move $t2, $v0
	jal indice
	sw $t2, ($v0)
	addi $t1, $t1, 1
	blt $t1, $a2, le
	li $t1, 0
	addi $t0, $t0, 1
	blt $t0, $a1, le
	li $t0, 0
	la $a0, 10	#ASCII para nova linha
	li $v0, 11
	syscall
	lw $ra ($sp)
	addi $sp, $sp, 4
	move $v0, $a3
	jr $ra
	
escrita:
	subi $sp, $sp, 4
	sw $ra, ($sp)
	move $a3, $a0
e:	move $t7, $v0
	jal indice
	lw $a0, ($v0)
	li $v0, 1
	syscall
	la $a0, 32
	li $v0, 11
	syscall
	addi $t1, $t1, 1
	blt $t1, $a2, e
	la $a0, 10	#ASCII para '\n'
	li $v0, 11
	syscall
	li $t1, 0
	addi $t0, $t0, 1
	blt $t0, $a1, e
	li $t0, 0
	lw $ra, ($sp)
	addi $sp, $sp, 4
	move $v0, $a3
	jr $ra

linColNulas:
	