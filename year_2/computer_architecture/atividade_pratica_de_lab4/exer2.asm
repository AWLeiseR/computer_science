.data
Ent: .asciiz "Insira um Valor:"
Res: .asciiz "Maior valor:"

.text 
Main: jal leitura #chama a função leitura
	move $s0,$v0 #copia o valor de $v0(valor lido) para $s0
	jal leitura #chama a função leitura
	move $s1,$v0 #copia o valor de $v0(valor lido) para $s1
	move $a0,$s0 #copia o valor de $s0 para $a0
	move $a1,$s1 #copia o valor de $s1 para $a1
	jal maior #chama a função maior
	move $a0,$v0  #copia o valor de $v0(valor lido) para $a0
	jal imprimir #chama a função imprimir
	j sair #chama a função sair
	
leitura:la $a0,Ent # carrega o endereço de Ent
	li $v0,4 #carrega o valor 4 para o registrador $v0 (impressao de string)
	syscall #chama o sistema
	li $v0,5 #carrega o valor 5 para o registrador $v0 (leitura de interio)
	syscall #chama o sistema
	jr $ra #retorna para a função
	
maior:bgt $a0,$a1,retA #se $a1 for maior que $a0 pula para retA
	move $v0,$a1 #copia o valor de $v0 para $a1
	jr $ra #retorna para olocal da chamada da função
	
retA:move $v0,$a0 #copia o valor de $v0 para $a0
	jr $ra #retorna para olocal da chamada da função
	
imprimir:move $t0,$a0 #copia o valor de $a0 para $t0
	la $a0, Res  # carrega o endereço de Res
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	move $a0,$t0 #copia o valor de $a0 para $t0
	li $v0,1 #carrega o valor 1 para o registrador $v0 (impressao de inteiro)
	syscall #chamada o sistema
	jr $ra #retorna para olocal da chamada da função
	
sair: li $v0,10 #carrega o valor 10 no $v0 (fim de programa)
	syscall #chamada o sistema
