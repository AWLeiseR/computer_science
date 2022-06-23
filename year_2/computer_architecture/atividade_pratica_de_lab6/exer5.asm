.data
vet: .space 100
ent1: .asciiz "insira uma String: "
ent2: .asciiz "insira um caractere: "
ent3: .asciiz " insira uma posição: "
saida: .asciiz"caractere nao encontrado"
saida2: .asciiz"caractere encontrado na posição: "
.text

# $s0 vet
# $s2 caractere
# $s3 posicao
# $s4 contador

Main: 	li $s4,0
	la $s0, vet
	la $a0, ent1
	jal leitura
	jal procura
	li $v0,10
	syscall
	
leitura:
	li $v0,4
	syscall
	move $a0,$s0
	li $a1,100
	li $v0,8
	syscall
	la $a0,ent2
	li $v0,4
	syscall
	li $v0,12
	syscall
	move $s2,$v0
	la $a0,ent3
	li $v0,4
	syscall
	li $v0,5
	syscall
	move $s3,$v0
	jr $ra
	
procura:
	move $t1,$s0
loop:	lb $t0,($t1)
	blt $s4,$s3,final
	beq $t0,$s2,outs
	sb $t0,($t1)
final:	addi $t1,$t1,1
	lb $t0,($t1)
	addi $s4,$s4,1
	bne $t0,10,loop
	
outn:	la $a0,saida
	li $v0,4
	syscall
	jr $ra
	
outs:	la $a0,saida2
	li $v0,4
	syscall
	move $a0,$s4
	li $v0,1
	syscall
	jr $ra
		
