#$s1 inicio do vetor
#$t0 inicio temporarios
#$t1 varivael para varrer vetor
#$t2 variavel i
#$s0 inicio novo vetor
#$t4 variavel para verrer novo vetor
#$t5 variavel j
.data
ent: .asciiz "Insira uma valor["
ent2: .asciiz "]:"
.align 2
vet1: .space 60
vet2: .space 60
.text
main: 	la $a0,vet1 #carrega o endereço do vetor como paramtero
	la $t4,vet2
	la $s0,vet2
	jal leitura
	move $a0,$v0 #salva o endereço retornado
	jal levetor
	move $a0,$s0 #move o endereço do vet2 $a0 para se escrito
	jal escrita
	li $v0, 10 #finaliza programa
	syscall
	


leitura: #essa funcao le todos os 15 valores do teclado
	move $t0, $a0 #salva endereço base do vet
	move $t1,$t0 #
	li $t2,0 # i=0
l: 	la $a0,ent 
	li $v0,4 #codigo de impressao de string
	syscall
	move $a0,$t2
	li $v0,1
	syscall 
	la $a0, ent2
	li $v0,4
	syscall
	li $v0,5
	syscall
	sw $v0,($t1)
	add $t1,$t1,4
	addi $t2,$t2,1
	blt $t2,15,l
	move $v0,$t0
	li $t2,0
	jr $ra
	
	
escrita:beq $t5,0,zero #escreve todos os valores que estao no vetor de tamanho $t5
	move $t0,$a0
	move $t1,$t0
	li $t2,0
e:	lw $a0,($t1)
	li $v0,1
	syscall
	li $a0,32
	li $v0,11
	syscall
	add $t1,$t1,4
	addi $t2,$t2,1
	blt $t2,$t5,e
	move $v0,$t0
zero:	jr $ra

	#acabar
	
levetor:move $t0,$a0 #Escanea o vetor fornecido pelo usuario e chama a função primo 
	move $t1,$t0
s:	lw $s2,($t1)
	j primo
voltaprimo:add $t1,$t1,4
	addi $t2,$t2,1
	blt $t2,15,s
	move $v0,$t0
	jr $ra
	
primo: 	beq $s2,1,fimloop #caso $s2 seja 1 pula para o final do loop pois nao é um primo
	beq $s2,0,fimloop #caso $s2 seja 0 pula para o final do loop pois nao é um primo
	move $t6,$s2 #copia o valor de $s2 para $t6
loopPrimos:div $s2,$t6 #divide $s2 por $t6
	mfhi $t7 #move o resto da divisao para $t1
	bne $t7,0,ndiv #se $t7 nao for igual 1 pula para ndiv
	addi $t3,$t3,1 # $t3 contador de divisores
ndiv:	sub $t6,$t6,1 #subtrai 1 de $t6
	bne $t6,0,loopPrimos #se $t6 nao for igual 0 pula para loopPrimos
	bne $t3,2,fimloop #se $t3 nao for igual 2 pula para fimloop
	sw $s2,($t4) #salva o numero no vet2 caso seja primo e soma mais um a $t5 e mais 4 a $t4
	addi $t5,$t5,1
	add $t4,$t4,4
fimloop:li $t3,0
	j voltaprimo #retorna para olocal da chamada da função
