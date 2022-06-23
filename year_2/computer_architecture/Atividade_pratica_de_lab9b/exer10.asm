.data
Entrada1: .asciiz "digite o valor de A["
Entrada2: .asciiz "]["
Entrada3: .asciiz "]: "
Entrada4: .asciiz  "Digite o n: "
.text
Main:
	jal leitura
	
indice:
	mul $v0, $t0, $a2 	# x = linha * numeroDeColunas
	add $v0, $v0, $t1	# x += coluna
	sll $v0, $v0, 2		# x *= 4
	add $v0, $v0, $a3	# x += A[0][0]
	jr $ra			#retorna para loopMatriz
	
leitura:

	la $a0, Entrada4	# carrega o endereço da string
	li $v0, 4		# carrega o codigo de impressao de strings
	syscall			# imprime a string
	li $v0, 5		# carrega o codigo de leitura de inteiros
	syscall			# le um inteiro
	move $t0, $v0		# aux = linhas
	move $a0, $t0		# carrega o quantos elementos serão alocados
	sll $a0, $a0, 2		# carrega o numero de bytes que serão alocados
	li $v0, 9		# carrega o codigo de alocacao dinamica
	syscall			# aloca
	move $t7, $v0
	move $a3, $t7		# Aaux = endereço de A[0][0]
	move $a1, $t0
	move $a2, $a1
	li $t1, 0
	li $t0, 0


loopMatriz:
	la $a0, Entrada1		# carrega a string a ser impressa
	li $v0, 4			# carrega o código de impressão de strings
	syscall				# imprime a string
	move $a0, $t0			# carrega o número da linha a ser impressa
	li $v0, 1			# carrega o código de impressão de inteiros
	syscall				# imprime o inteiro
	la $a0, Entrada2		# carrega a string a ser impressa
	li $v0, 4			# carrega o código de impressão de strings
	syscall				# imprime a string
	move $a0, $t1			# carrega o número da coluna a ser impressa
	li $v0, 1			# carrega o código de impressão de inteiros
	syscall				# imprime o inteiro
	la $a0, Entrada3		# carrega a string a ser impressa
	li $v0, 4			# carrega o código de impressão de strings
	syscall				# imprime a string
	li $v0, 6			#código de leitura de real
	syscall				# lê um real
	jal indice
	s.s $f0, ($v0)			#salva o valor lido em V[i]
	addi $t1, $t1, 1		# coluna++
	blt $t1, $a2, loopMatriz	# if (coluna < numeroDeColunas) go to loopMatriz
	li $t1, 0			# coluna = 0
	addi $t0, $t0, 1		# linha++
	blt $t0, $a1, loopMatriz	# if (linha < numeroDeLinhas) go to loopMatriz	
	li $t0, 0			# linha = 0
	move $v0, $a3			# retorna o valor de A[0][0] para $v0
	li $t1, 1
	li $t0, 0			# começa em A[0][1]
	
primeiro:				# calcula a matriz de forma que imprima a soma da primeira área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t1, $t1, 1
	blt $t1, $a2, primeiro
	addi $t0, $t0, 1
	move $t1, $t0
	addi $t1, $t1, 1
	blt $t0, $a1, primeiro
	jal impressao			# imprime a soma da area rachurada
	li $t0, 0
	li $t1, 0			# começa em A[0][0]
	subi $t4, $a1, 1
	sub.s $f4, $f4, $f4
	
segundo:				# calcula a matriz de forma que imprima a soma da segunda área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t1, $t1, 1
	blt $t1, $t4, segundo
	addi $t0, $t0, 1
	li $t1, 0
	subi $t4, $t4, 1
	bgt $t4, 0, segundo
	jal impressao			# imprime a soma da area rachurada
	li $t1, 1
	li $t0, 0			# começa em A[0][1]
	subi $t4, $a1, 1
	sub.s $f4, $f4, $f4

terceiro:				# calcula a matriz de forma que imprima a soma da terceira área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t1, $t1, 1
	blt $t1, $t4, terceiro
	addi $t0, $t0, 1
	move $t1, $t0
	addi $t1, $t1, 1
	subi $t4, $t4, 1
	sub $t5, $t4, $t0
	bgt $t5, 1, terceiro
	jal impressao			# imprime a soma da area rachurada
	li $t1, 0
	li $t0, 1			# começa em A[1][0]
	subi $t4, $a1, 1
	sub.s $f4, $f4, $f4
	
quarto:					# calcula a matriz de forma que imprima a soma da quarta área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t0, $t0, 1
	blt $t0, $t4, quarto
	addi $t1, $t1, 1
	move $t0, $t1
	addi $t0, $t0, 1
	subi $t4, $t4, 1
	sub $t5, $t4, $t1
	bgt $t5, 1, quarto
	jal impressao			# imprime a soma da area rachurada
	li $t1, 0
	li $t0, 1			# começa em A[1][0]
	subi $t4, $a1, 1
	sub.s $f4, $f4, $f4
	
quinto:					# calcula a matriz de forma que imprima a soma da quinta área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t0, $t0, 1
	blt $t0, $t4, quinto
	addi $t1, $t1, 1
	move $t0, $t1
	addi $t0, $t0, 1
	subi $t4, $t4, 1
	sub $t5, $t4, $t1
	bgt $t5, 1, quinto
	li $t0, 1
	subi $t1, $a1, 1
	li $t4, 0			# começa em A[1][n-1]
	
quinto2:
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t0, $t0, 1
	blt $t0, $t1, quinto2
	subi $t1, $t1, 1
	move $t0, $t1
	addi $t0, $t0, 1
	addi $t4, $t4, 1
	sub $t5, $t1, $t4
	bgt $t5, 1, quinto2
	jal impressao			# imprime a soma da area rachurada
	li $t1, 1
	li $t0, 0			# começa em A[0][1]
	subi $t4, $a1, 1
	sub.s $f4, $f4, $f4
	
sexto:					# calcula a matriz de forma que imprima a soma da sexta área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t1, $t1, 1
	blt $t1, $t4, sexto
	addi $t0, $t0, 1
	move $t1, $t0
	addi $t1, $t1, 1
	subi $t4, $t4, 1
	sub $t5, $t4, $t0
	bgt $t5, 1, sexto
	li $t1, 1
	subi $t0, $a1, 1
	li $t4, 0			# começa em A[n-1][1]
	
sexto2:
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t1, $t1, 1
	blt $t1, $t0, sexto2
	addi $t4, $t4, 1
	move $t1, $t4
	addi $t1, $t1, 1
	subi $t0, $t0, 1
	sub $t5, $t0, $t4
	bgt $t5, 1, sexto2
	jal impressao			# imprime a soma da area rachurada
	li $t1, 1
	li $t0, 0			# começa em A[0][1]
	subi $t4, $a1, 1
	sub.s $f4, $f4, $f4
	
setimo:					# calcula a matriz de forma que imprima a soma da setima área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t1, $t1, 1
	blt $t1, $t4, setimo
	addi $t0, $t0, 1
	move $t1, $t0
	addi $t1, $t1, 1
	subi $t4, $t4, 1
	sub $t5, $t4, $t0
	bgt $t5, 1, setimo
	li $t1, 0
	li $t0, 1			# começa em A[1][0]
	subi $t4, $a1, 1

setimo2:
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t0, $t0, 1
	blt $t0, $t4, setimo2
	addi $t1, $t1, 1
	move $t0, $t1
	addi $t0, $t0, 1
	subi $t4, $t4, 1
	sub $t5, $t4, $t1
	bgt $t5, 1, setimo2
	jal impressao			# imprime a soma da area rachurada
	li $t1, 0
	li $t0, 1			# começa em A[1][0]
	subi $t4, $a1, 1
	sub.s $f4, $f4, $f4
	
oitavo:					# calcula a matriz de forma que imprima a soma da oitava área rachurada
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t0, $t0, 1
	blt $t0, $t4, oitavo
	addi $t1, $t1, 1
	move $t0, $t1
	addi $t0, $t0, 1
	subi $t4, $t4, 1
	sub $t5, $t4, $t1
	bgt $t5, 1, oitavo
	li $t1, 1
	subi $t0, $a1, 1
	li $t4, 0			# começa em A[n-1][1]
	
oitavo2:
	jal indice
	l.s $f2, ($v0)
	add.s $f4, $f4, $f2
	addi $t1, $t1, 1
	blt $t1, $t0, oitavo2
	addi $t4, $t4, 1
	move $t1, $t4
	addi $t1, $t1, 1
	subi $t0, $t0, 1
	sub $t5, $t0, $t4
	bgt $t5, 1, oitavo2
	jal impressao			# imprime a soma da area rachurada
	li $v0, 10
	syscall

impressao:				# imprime o calculo da soma de uma área rachurada
	mov.s $f12, $f4
	li $v0, 2
	syscall
	la $a0, 10
	li $v0, 11
	syscall
	jr $ra