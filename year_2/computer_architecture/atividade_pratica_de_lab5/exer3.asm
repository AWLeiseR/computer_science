.data
vet1:.space 60
vet2:.space 28
vet3:.space 28

ent: .asciiz"insira um valor: "

.text
#$t0,$t1,$t5 contadores tamanho
#$t2,$t3 variaveis para percorrer vetor
#$t3 variavel vetA
#$t4 variavel vetB
#$t7 variavel de tamanho (15-7)
#$s0 inicio do vetA
#$s1 inicio do vetB
#$s2 inicio do vetInter
main: 	la $s0,vet1
	la $s1,vet2
	la $s2,vet3
	li $t7,5
	move $a0,$s0
	jal leitura
	li $t7,3
	move $a0,$s1
	jal leitura
	jal inter
	li $v0,10
	syscall
	
leitura:
	move $t1,$a0
	li $t0,0
loopLeitura:
	la $a0,ent
	li $v0,4
	syscall
	li $v0,5
	syscall
	sw $v0,($t1)
	add $t1,$t1,4
	addi $t0,$t0,1
	blt $t0,$t7,loopLeitura	
fimLeitura:
	li $t1,0
	li $t0,0
	li $t7,0
	jr $ra

inter:	move $t2,$s0
	move $t5,$s2
	li $t1,0
	li $t0,0
loopGand:
	move $t3,$s1
	lw $t6,($t2)
	move $s3,$t2
	move $s6,$t1
	j igual
loopPqno:
	lw $t4,($t3)
	add $t3,$t3,4
	addi $t0,$t0,1
	bne $t6,$t4,ne
	sw $t6,($t5)
	add $t5,$t5,4
ne:	
	blt $t0,7,loopPqno
	li $t0,0
	add $t2,$t2,4
	addi $t1,$t1,1
	blt $t1,15,loopGand

igual: 	lw $s4,($t2)
loop:	add $t2,$t2,4
	lw $s5,($t2)
	bne $s4,$s5,igualfim
	add $s3,$s3,4
	addi $t1,$t1,1
	j loopPqno
igualfim:
	addi $t1,$t1,1
	blt $t1,15,loop
	
	move $t1,$s6
	j loopPqno
	