.data
Mat:	.space 36 #3x3 inteiros

.text
main:	add $t0, $zero, $zero
	add $t1, $zero, $zero
	la $a0, Mat
	li $a1, 3
	li $a2, 3
	jal leitura
	move $a0, $v0
	jal escrita
	li $v0, 10
	syscall
	
indice:
	mul $v0, $t0, $a2
	add $v0, $v0, $t1
	sll $v0, $v0, 2
	add $v0, $v0, $a3
	jr $ra
	
leitura:
	subi $sp, $sp, 4 #espaço para 1 int na stack
	sw $ra, ($sp)
	move $a3, $a0
le:	li $v0, 5
	syscall
	move $t2, $v0
	jal indice
	sw $t2, ($v0)
	addi $t1, $t1, 1
	#la $a0, 32
	#li $v0, 11
	#syscall
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
e:	jal indice
	lw $a0, ($v0)
	li $v0, 1
	syscall
	la $a0, 32
	li $v0, 11
	syscall
	addi $t1, $t1, 1
	blt $t1, $a2, e
	la $a0, 10	#ASCII para \n
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
	