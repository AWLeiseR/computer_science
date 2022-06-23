.data
Out1:	.asciiz "Insira o grau (radiandos): "
Out2:	.asciiz "Insira o um inteiro: "
Out3:	.asciiz "O cos d x é aproximadamente: "
Doubn1:	.double -1.0
Doub0:	.double 0.0
Doub1:	.double 1.0
Doub2:	.double 2.0
a:	.double 7.0
aa:	.double 5.0

.text
main:
	andi $sp, $sp, 0xfffffff8	#alinha a stack para 8 bytes
	jal leNumeros
	jal calculaCos
	jal imprimeCos
	j end
	
imprimeCos:
	la $a0, Out3
	li $v0, 4
	syscall
	mov.d $f12, $f24
	li $v0, 3
	syscall
	jr $ra
	
calculaCos:	#$f20 = X, $f22 = N (numero de iterações)
	move $a0, $ra
	jal fStart
	l.d $f24, Doub0		#$f24 = cos(x)
calculaCosLoop:
	mov.d $f12, $f20
	l.d $f4, Doub2
	mul.d $f14, $f22, $f4
	jal potencia	#potencia(X^(2N)
	mov.d $f6, $f0
	l.d $f4, Doub2
	mul.d $f12, $f22, $f4
	jal fatorial	#fatorial(2N)
	mov.d $f8, $f0
	div.d $f6, $f6, $f8	#$f6(divRes) = potRes/patRes
	l.d $f12, Doubn1
	mov.d $f14, $f22
	jal potencia	#potencia(-1^N)
	mul.d $f4, $f0, $f6	#$f4 = divRes*(+-1)
	add.d $f24, $f24, $f4	#soma = soma + $f4
	l.d $f4, Doub1
	sub.d $f22, $f22, $f4	#N--
	l.d $f4, Doub0
	c.lt.d $f22, $f4	#if N>=0 than return
	bc1f calculaCosLoop
	j return
	
fatorial:	#f12!
	move $a0, $ra
	jal fStart
	subi $sp, $sp, 8
	s.d $f12, ($sp)	#armazena N na stack
	l.d $f4, Doub1
	c.le.d $f12, $f4	#if N<=1
	bc1t returnDouble1Fact	#return 1
	l.d $f4, Doub1
	sub.d $f12, $f12, $f4
	jal fatorial	#fatorial(N-1)
	l.d $f4, ($sp)
	mul.d $f0, $f0, $f4	#$f0 = N*(N-1)
	addi $sp, $sp, 8	#atualiza a stack
	j return
potencia:	#f12^f14 (x^t), f14 deve ser um inteiro
	move $a0, $ra	
	jal fStart
	l.d $f4, Doub0	
	c.le.d $f14, $f4	#if t<=0
	bc1t returnDouble1	#return 1
	l.d $f4, Doub1
	sub.d $f14, $f14, $f4
	jal potencia	#potencia(x-1)
	mul.d $f0, $f0, $f12
	j return	#return x*(x-1)
returnDouble1Fact:
	addi $sp, $sp, 8	#atualiza a stack
returnDouble1:	
	l.d $f0, Doub1	#return 1
	j return
	
leNumeros:	#lê X e N, e os armazena em $20 e $22, respectivamente
	move $a0, $ra
	jal fStart
	la $a0, Out1
	li $v0, 4
	syscall
	li $v0, 7
	syscall
	mov.d $f20, $f0
	la $a0, Out2
	li $v0, 4
	syscall
	li $v0, 7
	syscall
	mov.d $f22, $f0
	j return 
	
malloc:	#aloca a quantidade de bytes em $a0, e retorna o endereço em $v0
	li $v0, 9
	syscall
	jr $ra
fStart:	#armazena $a0 na stack
	subi $sp, $sp, 8
	sw $a0, ($sp)
	jr $ra
return:	#retorna para o $ra armazenado na stack
	lw $ra, ($sp)
	addi $sp, $sp, 8
	jr $ra
end:	#finaliza o programa
	li $v0, 10
	syscall
