.data
buffer: .asciiz " "
space: .asciiz "   "
Arquivo: .asciiz "dados2.txt"
Erro: .asciiz "Arquivo não encontrado!\n"
SomaStr: .asciiz "Soma dos elementos: "
ProdutoStr: .asciiz "Produto dos elementos: "
ParStr: .asciiz "numero de pares: "
ImparStr: .asciiz "numero de impares: "
MenorStr: .asciiz "Menor elementos: "
MaiorStr: .asciiz "Maior elemento: "
CaracStr: .asciiz "numero de caracteres: "

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
	beq $t0, 10, soma
	subi $t0, $t0, 48
	mul $t1, $t1, 10
	add $t1, $t1, $t0
	beq $t8, 0, valoresIniciais
	j leitura
	
valoresIniciais:				#seta valor inicial como maior e menos
	move $s4, $t1			
	move $s5, $t1			
	li $t8, 1			
	li $s1, 1			
	j leitura
	
soma:
	add $s0, $s0, $t1		#adiciona o numero ao somador
	
produto:
	mul $s1, $s1, $t1		#adiciona o numero ao multiplicador

verificaPar:				#verifica se o numero e par
	li $t3, 2
	div $t1, $t3       		
       	mfhi $t4           		
	bne $t4, $zero, aumentaImpar 	
	addi $s2, $s2, 1	
	j maior
             
aumentaImpar: 				#add 1 ao contador de impares
	addi $s3, $s3, 1 		

maior:     				#testa se o numero é maior
	bgt $s4, $t1, menor 		
	move $s4, $t1			
	   
menor:	   				#testa se o numero é menor
	move $t4, $t1
	li $t1, 0				
	beq $t9, 1, fimLeitura2
	blt $s5, $t4, leitura 		
	move $s5, $t4		
	j leitura

fimLeitura:
	li $t9, 1			#verificador2 = 1
	j soma				#faz todas as operações com o ultimo numero

fimLeitura2:
	blt $s5, $t4, return 		#se x menor q y retorna x
	move $s5, $t4			#else return y
	j return
	
abertura:				#abre o arq
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
