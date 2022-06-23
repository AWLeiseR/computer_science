.data
Vet:	.space 12 #3x1 inteiros
Res:	.space 16 #4x1 inteiros
Ent1:	.asciiz "Insira o os indices i e j da matriz:\n"
Ent2:	.asciiz "Insira os "
Ent3:	.asciiz " elementos da matriz\n"
Ent4:	.asciiz "\nLinhas nulas: \n"
Ent5:	.asciiz "Colunas Nulas: "
Naum: .asciiz"É matriz permutação"
#t3 somador linha

.text
main:	add $t3,$zero,0   #zera o registrador t3
	jal leTamanho     #função que pega o tamanho p/ malloc
	mul $a0, $s0, $s1 #multiplica linha por coluna
	sll $a0, $a0, 2   #NO IDEIA
	jal malloc        #chama função de alocamento
	move $s2, $v0
	move $a0, $s2
	move $a1, $s0
	move $a2, $s1
	jal leitura      #função d leitura
	move $a0, $s2
	jal verifica     #função de verificação se é matriz premutação
	move $a0, $s2
	li $v0, 10
	syscall
	
leTamanho:
	la $a0, Ent1
	li $v0, 4
	syscall
	li $v0, 5 #leitura de inteiro
	syscall
	move $s0, $v0 #move o resultado para $s0
	li $v0, 5 #leitura de inteiro
	syscall
	move $s1, $v0 #move o resultado para $s
	jr $ra	
	
malloc:
	li $v0, 9 #atribui 9(codigo p/ alocação) para $v0
	syscall
	jr $ra
	
indice:	#função que corrige o indice
	mul $v0, $t0, $a2
	add $v0, $v0, $t1
	sll $v0, $v0, 2
	add $v0, $v0, $a3
	jr $ra
	
leitura:
	mul $t0, $a1, $a2
	add $t1, $zero, $zero
	subi $sp, $sp, 4 #espaço para 1 int na stack
	sw $ra, ($sp)
	move $a3, $a0
	la $a0, Ent2 #impressao das strings
	li $v0, 4    
	syscall
	move $a0, $t0
	li $v0, 1
	syscall
	la $a0, Ent3
	li $v0, 4
	syscall
	add $t0, $zero, $zero
le:	li $v0, 5
	syscall
	move $t2, $v0
	jal indice
	sw $t2, ($v0)
	addi $t1, $t1, 1
	blt $t1, $a2, le
	li $t1, 0
	addi $t0, $t0, 1
	blt $t0, $a1, le
	li $t0, 0
	la $a0, 10	#ASCII para nova linha
	li $v0, 11
	syscall
	lw $ra ($sp)
	addi $sp, $sp, 4
	move $v0, $a3
	jr $ra
	
verifica:
	subi $sp, $sp, 4
	sw $ra, ($sp)
	move $a3, $a0
e:	move $t7, $v0 #loop que percorre linhas
	jal indice
	lw $a0,($v0)
	add $t3,$t3,$a0 #pega o valor do elemento e soma com o valor de $t3
	addi $t1, $t1, 1 #adiciona um no indice da linha
	blt $t1, $a2, e #teste para ver se acabou a linha
	bgt $t3,1,fim #se a soma da linha maior q um pula para o fim
	move $t3,$zero #zera o somador
	li $t1, 0	#zera indice
	addi $t0, $t0, 1	#add no indice de coluna
	blt $t0, $a1, e#teste fim da coluna
i:	move $t7, $v0  #loop que percorre colunas
	jal indice
	lw $a0,($v0)
	add $t3,$t3,$a0#pega o valor do elemento e soma com o valor de $t3
	addi $t0, $t0, 1#adiciona um no indice da linha
	blt $t0, $a1, i#teste para ver se acabou a coluna
	bgt $t3,1,fim#se a soma da linha maior q um pula para o fim
	move $t3,$zero#zera o somador
	addi $t1, $t1, 1#add 1 ao indice da linha
	blt $t1, $a2, i#testa se acabou a linha
	li $t1, 0#zera indice
	la $a0, Naum #caso seja matriz permutação imprimi a mensagem naum
	li $v0, 4
	syscall
fim:	li $t0, 0
	lw $ra, ($sp)
	addi $sp, $sp, 4
	move $v0, $a3
	jr $ra
