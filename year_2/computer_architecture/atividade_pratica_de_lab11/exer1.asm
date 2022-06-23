.data
Arq: .asciiz "teste.txt"
Msg: .asciiz "Escrevendo em um arquivo"
.text
#$t0 contador de caracteres
#$s0 num de caracteres

Escrita:
	la $a0,Arq
	li $a1,1
	li $v0,13 #codigo de leitura de arq
	syscall
	move $a0,$v0
	li $v0,15
	la $a1,Msg
	li $a2,24
	syscall
	li $v0,16
	syscall
	li $v0,10
	syscall
	
contagem:
	li $v0,14
	syscall
	addi $t0,$t0,1
	blt  $t0,$s0,contagem
	beq $v0,fim
fimCont:	jr $ra
	
fim:	subi $t0,$t0,1
	b fimCont 