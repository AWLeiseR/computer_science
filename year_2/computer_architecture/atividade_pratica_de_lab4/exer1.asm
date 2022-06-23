#registrador p/ maior $s1
#registrador para menor $s2
#registrador quantidade de impares $s3
#registrador para armazenar o valor lido
#atribuir o primeiro valor lido como maior/menos, e o registrador de impares para zero
#a medida q for lendo os outro valores comparar com o registrador maior e menor, e verificar se é impar
#fazer um loop q ira repetir a lina 6, x9 vezes e apresentar o resultado
#registrador contador $s4

.data
Ent: .asciiz "Insira um Valor:"
Res0: .asciiz "Maior valor:"
Res1: .asciiz "Menor valor:"
Res2: .asciiz "Primos:"

.text 

main:  addi $s3,$zero,0 #zera o registrador $s3
	addi $s4,$zero,9 #define a quantidade de leituras q seram feitas
	addi $t0,$zero,0 #zera registrador $t0
	jal leitura #chama a função de leitura
	jal primo #chama a função de primo
	move $s1,$v0 #define o primeiro numero  o maior 
	move $s2,$v0 #define o primeiro numero  o menor
	jal loop #pula para o loop
	#chamar syscall
loop:	jal leitura #chama a função de leitura
	jal primo #chama a função de primo
	move $a0,$v0
	move $a1,$s1
	jal maior #chama a função maior
	move $s1,$v0
	move $a1,$s2
	jal menor #chama a função menor
	move $s2,$v0
	subi $s4,$s4,1
	bne $s4,$zero,loop #volta para o loop
	jal imprimir #chama a função imprimir
	j sair #chama a função de sair
	

leitura:la $a0,Ent # carrega o endereço de ENT
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chama o sistema
	li $v0,5 #carrega o valor 5 para o registrador $v0
	syscall #chama o sistema
	jr $ra #retorna para a função
	
maior:	bgt $a0,$a1,retA #pula se for menor
	move $v0,$a1 # move $a1 para $v0
	jr $ra #retorna para a função
	
retA:	move $v0,$a0 # move $a0 para $v0
	jr $ra #retorna para a função
	
menor:	blt $a0,$a1,retA #pula se for maior
	move $v0,$a1 # move $a1 para $v0
	jr $ra #retorna para a função
	
primo: 	beq $v0,1,fimloop #caso $v0 seja 1 pula para o final do loop pois nao é um primo
	beq $v0,0,fimloop #caso $v0 seja 0 pula para o final do loop pois nao é um primo
	move $t0,$v0 #copia o valor de $v0 para $t0
loopPrimos:div $v0,$t0
	mfhi $t1 
	bne $t1,0,ndiv
	addi $t2,$t2,1 # $t2 contador de divisores
ndiv:	sub $t0,$t0,1
	bne $t0,0,loopPrimos
	bne $t2,2,fimloop
	addi $s3,$s3,1
fimloop:li $t2,0
	jr $ra #retorna para a função
	
imprimir: la $a0,Res0
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chama o sistema
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	syscall #chama o sistema
	la $a0,Res1
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chama o sistema
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	syscall #chama o sistema
	la $a0,Res2
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chama o sistema
	move $a0,$s3
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	jr $ra #retorna para a função
	
sair: li $v0,10 #carrega o valor 10 no $v0 (fim de programa)
	syscall #chamada o sistema
