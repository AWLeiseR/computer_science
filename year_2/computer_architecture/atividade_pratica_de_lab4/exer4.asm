#numero inserido  $s1
#multiplicador(1) $s2
#multiplicador(2) $s3
.data 
Ent: .asciiz "Insira um Valor Inteiro:"
naoPrimo: .asciiz "O Numero n�o � primo"
Semi: .asciiz "O numero � semi-primo"

.text
main: 	jal leitura #chama a fun��o de leitura
	jal primo #chama a fun��o primo
	move $s1,$v0 #copia o valor de $v0 para $s1
	jal semi #chama a fun��o semi
	j sair #chama a fun��o de saida


leitura:la $a0,Ent #carrega o endere�o de Ent
	li $v0,4 #carrega o valor 4 $v0
	syscall #chamada o sistema
	li $v0,5 #carrega o valor 5 para o registrador $v0 (leitura de interio)
	syscall #chamada o sistema
	jr $ra #retorna para olocal da chamada da fun��o

primo: li $t2,0	#zera $t2 para ser utilizado novamente
	beq $v0,1,fimloop #caso $v0 seja 1 pula para o final do loop pois nao � um primo
	beq $v0,0,fimloop #caso $v0 seja 0 pula para o final do loop pois nao � um primo
	move $t0,$v0 #copia o valor de $v0 para $t0
loopPrimos:div $v0,$t0 #divide $v0 por $t0
	mfhi $t1 #move o resto da divisao para $t1
	bne $t1,0,ndiv #se $t1 nao for igual 1 pula para ndiv
	addi $t2,$t2,1 # $t2 contador de divisores
ndiv:	sub $t0,$t0,1 #subtrai 1 de $t0
	bne $t0,0,loopPrimos # se $t0 nao for igual a o pula para loopPrimos
	bne $t2,2,nao #se $t2 nao for igual a 2 pula para nao(nao primo)
	beq $t3,1,mover2 #se $t3 nao for igual a 1 pula para mover(move o outro valor para $v0 para reutilizar primos)
	beq $t3,2,imprimir#se $t3 nao for igual a 2 pula para imprimir pois os dois sao primos
nao:	la $a0,naoPrimo # carrega o endere�o de NaoPrimo
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema 
	j sair #chama a funcao de saida
	
fimloop:jr $ra #retorna para o local da chamada da fun��o
	
semi: 	li $s2,2 #carrega $s2 com o valor 2
	li $s3,2 #carrega $s3 com o valor 2
voltaloop:mul $s4,$s2,$s3 #multiplica $s2 por $s3
	blt  $s4,$s1,Menor # se $s4 for menor que $s1 pula para Menor
	bgt $s4,$s1,Maior # se $s4 for maior que $s1 pula para Maior
	beq $s4,$s1,mover #se for igual chama a funcao mover
	j voltaloop #chama a fun��o voltaloop
mover: move $v0,$s2 #move o valor de $s2 para $v0
	li $t3,1 #carrega o valor 1 em %s3
	j primo #chama a fun��o primo
	
mover2: move $v0,$s3 #move o valor de $s3 para $v0
	li $t3,2 #carrega o valor 2 em %s3
	j primo #chama a fun��o primo
	
Maior: addi $s2,$s2,1 #adiciona um em $s2
	li $s3,2 #carrega o valor 2 em %s3
	j voltaloop #chama a fun��o voltaloop
Menor: addi $s3,$s3,1 #adiciona um em $s3
	j voltaloop #chama a fun��o voltaloop
	
imprimir:la $a0,Semi #carrega em $a0 o endere�o de Semi
	li $v0,4 #carrega o valor 4 para o registrador $v0
	syscall #chamada o sistema
	j sair  #chama a fun��o sair

sair: li $v0,10 #carrega o valor 10 no $v0 (fim de programa)
	syscall #chamada o sistema
