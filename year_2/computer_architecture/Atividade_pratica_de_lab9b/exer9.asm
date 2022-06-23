.data
txt1: .asciiz "insira um valor para ser dividido: "
txt2: .asciiz "insira um divisor:"
txt3: .asciiz "o numero de divisoes possiveis:"
txt4: .asciiz "o divisor digitado é 1"
.text
#$s0 numero a ser dividido
#$s1 divisor
#$s2 contador de dividoes
main:	la $a0,txt1
	li $v0,4
	syscall
	jal leitura
	move $t0,$s0
	jal divide
	la $a0,txt3
	li $v0,4
	syscall
	move $a0,$s2
	li $v0,1
	syscall
	li $v0,10
	syscall
	

leitura:	
	li $v0,5
	syscall
	move $s0,$v0
	la $a0,txt2
	li $v0,4
	syscall
	li $v0,5
	syscall
	move $s1,$v0
	jr $ra
#funcao cont divisao
divide:	bgt $s1,$t0,nao
	beq $s1,1,um
loop: 	div $t0,$s1
	mflo $t0
	mfhi $t1
	bnez $t1,fim
	addi $s2,$s2,1
	beqz $t1,loop
fim:	jr $ra
#retorna -1 se nao for possivel dividir 
nao: li $s2,-1
	b fim
um:	la $a0,txt4
	li $v0,4
	syscall
	li $v0,10
	syscall
