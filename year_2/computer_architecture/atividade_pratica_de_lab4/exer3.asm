#maior                $s1
#menor                $s2
#primos               $s3
#contador(qtd de num) $s4
#soma Par             $s5
#soma Impar           $s6
#numeros amigos       $s7
#numero perfeitos     $s0

.data
linha:.asciiz "\n"
Ent: .asciiz "Insira um Valor Inteiro:"
Res0: .asciiz "Maior valor:"
Res1: .asciiz "Menor valor:"
Res2: .asciiz "Primos:"
Res3: .asciiz "Soma dos numeros Pares:"
Res4: .asciiz "Soma dos numeros Impares:"
Res5: .asciiz "Inteiros Perfeitos"
Res6: .asciiz  "Inteiros amigos:"

.text 

main:  	addi $s3,$zero,0 #zera os registradores que serao utilizados
	addi $s4,$zero,9 #|
	addi $t0,$zero,0 #|
	addi $s0,$zero,0 #|
	addi $s7,$zero,0 #|
	move $zero,$s5   #|
	move $zero,$s6   #|
	jal leitura #chama a função leitura
	jal primo #chama a função primo (verificas se é primo)
	jal par #chama a função par (verificas se é par)
	jal perfeito #chama a função perfeito (verificas se é perfeito)
	jal amigo #chama função de amigo (verificas se é amigo)
	move $s1,$v0 #move o valor lido para $s1 (maior)
	move $s2,$v0 #move o valor lido para $s1 (menor)
	jal loop #vai para o loop
	#chamar syscall
loop:	jal leitura #chama a função leitura
	jal primo #chama a função primo (verificas se é primo)
	jal par #chama a função par (verificas se é par)
	jal perfeito #chama a função perfeito (verificas se é perfeito)
	jal amigo #chama função de amigo (verificas se é amigo)
	move $a0,$v0 #move o valor lido para $a0
	move $a1,$s1 #move o maior valor lido para $a1
	jal maior #chama a função maior
	move $s1,$v0 #move o valor maior para $s1
	move $a1,$s2 #move o menor valor lido para $a1
	jal menor #chama a função menor
	move $s2,$v0 #move o menor valor lido para $a2
	subi $s4,$s4,1 #subtrai 1 de $s4 (contador de leitura)
	bne $s4,$zero,loop #se o contador for igual a zero vai para a funçao de impressao
	jal imprimir #chama a função de impressao
	j sair #chama a função de saida
	

leitura:la $a0,Ent #carrega o endereço de Ent
	li $v0,4 #carrega o valor 4 $v0
	syscall #chamada o sistema
	li $v0,5 #carrega o valor 5 para o registrador $v0 (leitura de interio)
	syscall #chamada o sistema
	jr $ra #retorna para olocal da chamada da função
	
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
loopPrimos:div $v0,$t0 #divide $v0 por $t0
	mfhi $t1 #move o resto da divisao para $t1
	bne $t1,0,ndiv #se $t1 nao for igual 1 pula para ndiv
	addi $t2,$t2,1 # $t2 contador de divisores
ndiv:	sub $t0,$t0,1 #subtrai 1 de $t0
	bne $t0,0,loopPrimos #se $t0 nao for igual 0 pula para loopPrimos
	bne $t2,2,fimloop #se $t2 nao for igual 2 pula para fimloop
	addi $s3,$s3,1 #adiciona1 no registrador $s3
fimloop:li $t2,0 #zera os registradores para seerem utilizados novamente
	jr $ra #retorna para olocal da chamada da função
	
imprimir: la $a0,Res0 # carrega o endereço de Res0
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$s1 #copia o valor de $s1 para $a0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	la $a0,Res1 # carrega o endereço de Res1
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$s2 #copia o valor de $s2 para $a0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	la $a0,Res2 # carrega o endereço de Res2
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$s3 #copia o valor de $s3 para $a0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	la $a0,Res3 # carrega o endereço de Res3
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$s5 #copia o valor de $s15para $a0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	la $a0,Res4 # carrega o endereço de Res4
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$s6 #copia o valor de $s6 para $a0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	la $a0,Res5 # carrega o endereço de Res5
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$s0 #copia o valor de $s0 para $a0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	la $a0,Res6 # carrega o endereço de Res6
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$s7 #copia o valor de $s7 para $a0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	jr $ra #retorna para olocal da chamada da função
	
par:	addi $a0,$zero,2 #adiciona o valor 2 em $a0	
	div $v0,$a0 #divide $vo por $a0
	mfhi $t1 #move o resto da divisao para $t1
	bne $t1,$zero,impar #se o restor($t1) nao for igual a 0 pula para impar
	add $s5,$s5,$v0 #se for igual a zero adiciona o valor de $v0 em $s5
	jr $ra #retorna para olocal da chamada da função
	
impar: add $s6,$s6,$v0 #adiciona o valor de $v0 em $s6
	jr $ra #retorna para olocal da chamada da função
	
perfeito:beq $v0,1,fimloop2 #se $v0 for igual a 1 pula para fimloop2
	beq $v0,0,fimloop2 #se $v0 for igual a 0 pula para fimloop2
	move $t0,$v0 #copia $v0 para $t0
loopPerfeito:div $v0,$t0 #divide $v0 por $t0
	mfhi $t1 #move o resto da divisao para $t1
	bne $t1,0,ndiv2 #se o restor($t1) nao for igual a 0 pula para ndiv2
	add $t2,$t2,$t0 # $t2 somador de divisores
ndiv2:	sub $t0,$t0,1 #subtrai 1 de $t0
	bne $t0,0,loopPerfeito #se $t0 nao for igual a 0 pula para loopPerfeito
	mul $t3,$v0,2 #multiplica $v0 por dois e armazena e $t3
	bne $t2,$t3,fimloop2 #se $t2 nao for igual a $t3 pula para fimloop2
	addi $s0,$s0,1 #adiciona 1 em $s0
fimloop2:li $t2,0 #zera o registrador para ser reutilizado
	jr $ra #retorna para olocal da chamada da função

amigo:beq $v0,1,fimloop3 #se $v0 for igual a 1 pula para fimloop3
	beq $v0,0,fimloop3 #se $v0 for igual a 0 pula para fimloop3
	move $t0,$v0 #copia $v0 para $t0
loopAmigo:div $v0,$t0 #divide $v0 por $t0
	mfhi $t1 #move o resto da divisao para $t1
	bne $t1,0,ndiv3 #se $t1 nao for igual a 0 pula para ndiv3
	add $t2,$t2,$t0 # $t2 somador de divisores
ndiv3:	subi $t0,$t0,1 #subtrai 1 de $t0
	bne $t0,0,loopAmigo #se $t0 nao for igual a 0 pula para loopAmigo
	sub $t2,$t2,$v0 #subtrai $v0 de $t2
amigo2:	move $t3,$t2 #move $t2 para $t3
loopAmigo2:div $t2,$t3 #divide o $t2 pelo $t3
	mfhi $t1 #move o resto da divisao para $t1
	bne $t1,0,ndiv4 # se %t1 nao for igual a 0 pula para ndiv4
	add $t4,$t4,$t3 # $t4 somador de divisores
ndiv4:	subi $t3,$t3,1 #subtrai 1 de $t3
	bne $t3,0,loopAmigo2 #se $t3 for igual a 0 pula para loopAmigo2
	sub $t4,$t4,$t2 #subtrai $t2 de $t4
	bne $t4,$v0,fimloop3 #se $t4 for igual a $v0 pula para fimloop3
	addi $s7,$s7,1	#adiciona 1 em $s7
fimloop3:li $t2,0 #zera os registradores para seerem utilizados novamente
	li $t4,0 # idem
	jr $ra #retorna para olocal da chamada da função
	
sair: li $v0,10 #carrega o valor 10 no $v0 (fim de programa)
	syscall #chamada o sistema
