.data
ent1:	.asciiz "insira o numero de alunos:\n"
Ent2:	.asciiz "insira as 3 notas do aluno:\n"
"
Sai1: .asciiz "alunos aprovados: "
Sai2: .asciiz "alunos reprovados: "
Sai3: .asciiz "media da classe: "
Sai4: .asciiz "media do aluno: "
.text
#$s1 linhas
#$s0 colunas
#$s2 enederço do inicio da matriz
#$s3 cont aprovados
#$s4 cont reprovados
#$f2 varivale de soma
#$f4 media aluno
#$f6 media classe

main:	jal leituraTam
	li $s1, 3
	mul $a0, $s0, $s1
	sll $a0, $a0, 8
	jal malloc
	move $s2, $v0	
	move $a0, $s2	
	move $a1, $s0	
	move $a2, $s1
	jal leitura
	move $a1, $s0	
	move $a2, $s1
	move $a0, $s2
	jal calcula
	li $v0,10
	syscall
	
leituraTam:	
	la $a0, ent1
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $s0, $v0		
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
	subi $sp, $sp, 4 
	sw $ra, ($sp)
	move $a3, $a0
	la $a0, Ent2
	li $v0, 4
	syscall
	add $t0, $zero, $zero
le:	li $v0, 6
	syscall
	mov.s $f2, $f0
	jal indice
	s.s $f2, ($v0)
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
	
calcula:
	#move $t0, $ra
	subi $sp, $sp, 4 
	sw $ra, ($sp)
	li $t0,0
	li $t1,0
	li $t2,0
	move $a3, $s2	
loop:	jal indice
	l.s $f0,($v0)
	add.s $f1,$f1,$f0
	addi $t1, $t1, 1
	bne $t1, $a2, loop
	add.s $f12,$f1,$f10
	li $v0,2
	syscall
	addi $t2, $t2, 1
	addi $t0, $t0, 1
	li $t1, 0
	bne $t0, $a1, loop
	jr $ra