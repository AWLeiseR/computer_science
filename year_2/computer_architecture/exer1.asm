.data
buffer: .asciiz " "
space: .asciiz "\n"
Arquivo: .asciiz "dados1.txt"
Erro: .asciiz "Arquivo nao encontrado!\n"
SomaStr: .asciiz "Soma dos valores: "
ProdutoStr: .asciiz "Produto dos valores: "
ParStr: .asciiz "Qtd de pares: "
ImparStr: .asciiz "Qtd de impares: "
MenorStr: .asciiz "Menor valor: "
MaiorStr: .asciiz "Maior valor: "
CaracStr: .asciiz "Qtd de caracteres: "

.text
main:
	la $a0, Arquivo
	li $a1, 0
	jal abertura
	move $a0, $v0
	la $a1, buffer
	la $a2, 1
	jal leitura
	j escrita
	
leitura:
	li $v0, 14
	syscall
	beqz $v0, fimLeitura
	addi $s6, $s6, 1
	lb $t0, ($a1)
	beq $t0, 13, leitura
	beq $t0, 32, soma
	subi $t0, $t0, 48
	mul $t1, $t1, 10
	add $t1, $t1, $t0
	beq $t8, 0, valoresIniciais
	j leitura
	
valoresIniciais:			#valores iniciais necessários para o funcionamento do programa
	move $s4, $t1			#menor valor = primeiro valor
	move $s5, $t1			#maior valor = primeiro valor
	li $t8, 1			#verificador = 1
	li $s1, 1			#multiplicador = 1
	j leitura
	
soma:
	add $s0, $s0, $t1		#soma o numero ao somador
	
produto:
	mul $s1, $s1, $t1		#multiplica o numero ao multiplicador

verificaPar:
	li $t3, 2
	div $t1, $t3       		# x / 2
       	mfhi $t4           		# $t4 = x % 2
	bne $t4, $zero, aumentaImpar 	#if $t4 == 1 impar
	addi $s2, $s2, 1		#else par += x
	j maior
             
aumentaImpar: 
	addi $s3, $s3, 1 		#impar += x

maior:     
	bgt $s4, $t1, menor 		#if x > y return x
	move $s4, $t1			#else return y
	   
menor:	   
	move $t4, $t1
	li $t1, 0				
	beq $t9, 1, fimLeitura2
	blt $s5, $t4, leitura 		#if x < y return x
	move $s5, $t4			#else return y
	j leitura

fimLeitura:
	li $t9, 1			#verificador2 = 1
	j soma				#faz todas as operações com o ultimo numero

fimLeitura2:
	blt $s5, $t4, return 		#if x < y return x
	move $s5, $t4			#else return y
	j return
	
abertura:
	li $v0, 13
	syscall
	bgez $v0, return
	la $a0, Erro
	li $v0, 4
	syscall
	li $v0, 10
	syscall

return:
	jr $ra
	
escrita:
	la $a0, SomaStr
	li $v0, 4
	syscall
	move $a0, $s0
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	la $a0, ProdutoStr
	li $v0, 4
	syscall
	move $a0, $s1
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	la $a0, ParStr
	li $v0, 4
	syscall
	move $a0, $s2
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	la $a0, ImparStr
	li $v0, 4
	syscall
	move $a0, $s3
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	la $a0, MaiorStr
	li $v0, 4
	syscall
	move $a0, $s4
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	la $a0, MenorStr
	li $v0, 4
	syscall
	move $a0, $s5
	li $v0, 1
	syscall
	la $a0, space
	li $v0, 4
	syscall
	la $a0, CaracStr
	li $v0, 4
	syscall
	move $a0, $s6
	li $v0, 1
	syscall
	li $v0, 16
	move $a0, $s0
	syscall
	li $v0, 10
	syscall
	

