.data
str0: .asciiz "insira o tamanho do vetor: "
str1: .asciiz "insira um valor do vet: "
str2: .asciiz "\n"
str3: .asciiz "depois dos primos"
str4: .asciiz " - "
.text

#$s0 tam vetor
#$s1 endereco do vetor
#$s2 par
#$s3 impar
#$s4 num de primos
#$s5 soma total


main:
	la $a0,str0
	li $v0,4
	syscall
	li $v0,5
	syscall
	move $s0,$v0
	mul $a0,$s0,4
	li $v0,9
	syscall
	move $s1,$v0
	jal leitura
	la $a0,str2
	li $v0,4
	syscall	
	jal escrever
	jal ordenar
	la $a0,str2
	li $v0,4
	syscall
	la $a0,str3
	li $v0,4
	syscall
	jal varre
	jal escrever
	li $v0,10
	syscall
	
	
leitura:
	li $t0,0
	move $t1,$s1
le:	la $a0,str1
	li $v0,4
	syscall
	li $v0,5
	syscall
	sw $v0,($t1)
	addi $t0,$t0,1
	add $t1,$t1,4
	blt $t0,$s0,le
	jr $ra
	
varre:
	subi $sp, $sp, 4
	sw $ra, ($sp)
	li $t0,0
	move $t1,$s1
loopVarre:
	lw $a0,($t1)
	add $s5,$s5,$a0
	jal divide
	move $v0,$a0
	jal primo
	addi $t0,$t0,1
	add $t1,$t1,4
	blt $t0,$s0,loopVarre
	lw $ra, ($sp)
	addi $sp, $sp, 4
	jr $ra

escrever:
	li $t0,0
	move $t1,$s1
loop:	la $a0,str4
	li $v0,4
	syscall
	lw $a0,($t1)
	li $v0, 1
	syscall
	addi $t0,$t0,1
	add $t1,$t1,4
	blt $t0,$s0,loop
	jr $ra
	
	#jal ordenacao
	#jal maior
	#jal menor
	#jal maiorPar
	
divide:	
	rem $t3,$a0,2
	beq $t3,0,par
	beq $t3,1,impar
	
par: 	addi $s2,$s2,1 
	jr $ra
	
impar:	addi $s3,$s3,1
	jr $ra

	#jal MenorImpar
	#jal primo
primo:
	beq $v0,1,fimloop #caso $v0 seja 1 pula para o final do loop pois nao é um primo
	beq $v0,0,fimloop #caso $v0 seja 0 pula para o final do loop pois nao é um primo
	move $t4,$v0 #copia o valor de $v0 para $t0
loopPrimos:
	div $v0,$t0
	mfhi $t3 
	bne $t5,0,ndiv
	addi $t2,$t2,1 # $t2 contador de divisores
ndiv:	sub $t4,$t4,1
	bne $t4,0,loopPrimos
	bne $t2,2,fimloop
	addi $s4,$s4,1
fimloop:li $t2,0
	jr $ra #retorna para a função
	
ordenar:
	move $t0, $s0			#numero de valores do vetor (n)
	subi $t0, $t0, 2			# n = n-1, porque substituicao ocorre entre as posicoes n e n+1 
					#(evita acessar posicao inexistente do vetor) 
	li $t1, 0			#contador de iteracao (i)
	move $t2,$s1 			#endereco do vetor
ordenarLoop:
	lw $t3, ($t2)			#le numero do vetor
	addi $t2, $t2, 4			#aumenta offset do endereco do vetor
	lw $t4, ($t2)			#le numero do vetor
	bgt $t3, $t4, ordenarTrocar	#troca os valores caso t3 > t4
				#Else: (caso t3 e t4 ja estejam ordenados)
	addi $t1, $t1, 1			#aumenta contador de iteracoes (i)
	blt $t1, $t0, ordenarLoop	#retorna ao loop enquanto i < n
	jr $ra				#retorna p/  main quando ler os ultimos dois valores e eles ja estiverem ordenados

ordenarTrocar:
	sw $t3, ($t2)			#posicao de t4 do vetor recebe valor de t3
	subi $t2, $t2, 4			#diminui offset do vetor (volta da posicao de t4 para posicao de t3)
	sw $t4, ($t2)			#posicao de t3 do vetor recebe valor de t4
	j ordenar			#retorna para funcao de ordenacao (comeca as comparacoes novamente)
