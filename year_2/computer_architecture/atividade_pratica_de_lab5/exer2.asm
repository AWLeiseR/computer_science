.data
vet1:.space 40
vet2:.space 40

ent: .asciiz"insira um valor: "
pares: .asciiz "soma pares: "
impares: .asciiz " soma impares: "

.text
#$s0 inicio do vetA
#$s1 inicio do vetB
#$s2 soma posição pares de vetA
#$s3 soma posição pares de vetB
#$t0 variavel para o tamanho (10)
#t1 varivale de leitura
#$t2 varival para divisor
#$t3variavel para o load word
#$t4 const 2


main: 	la $s0,vet1 #salva o ponto inicial dos vetores e define um registrador como constante
	la $s1,vet2
	li $t4,2
	move $a0,$s0
	jal leitura
	move $a0,$s1
	jal leitura
	move $a0,$s0 
	jal levetorA 
	move $a0,$s1
	jal levetorB
	la $a0,pares 
	li $v0,4 #codigo de impressao de string
	syscall
	move $a0,$s2
	li $v0,1
	syscall
	la $a0,impares 
	li $v0,4 #codigo de impressao de string
	syscall
	move $a0,$s3
	li $v0,1
	syscall
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
	blt $t0,10,loopLeitura	
fimLeitura:
	jr $ra

levetorA: #escanea o vetor A, e em suas posicoes pares ele soma o valor dessa posiçao ao registrador $s2
	move $t1,$a0
	li $t0,0
loopScanA:
	lw $t3,($t1)
	div $t0,$t4
	mfhi $t2
	bnez $t2,ra
	add $s2,$s2,$t3
ra:	add $t1,$t1,4
	addi $t0,$t0,1
	blt $t0,10,loopScanA
fimA:  	li $t0,0
	li $t1,0
	li $t3,0
	jr $ra

levetorB: #escanea o vetor B, e em suas posicoes pares ele soma o valor dessa posiçao ao registrador $s3
	move $t1,$a0
	li $t0,0
loopScanB:
	lw $t3,($t1)
	div $t0,$t4
	mfhi $t2
	beqz $t2,rb
	add $s3,$s3,$t3
rb:	add $t1,$t1,4
	addi $t0,$t0,1
	blt $t0,10,loopScanB
fimB:  	li $t0,0
	li $t1,0
	li $t3,0
	jr $ra
	
