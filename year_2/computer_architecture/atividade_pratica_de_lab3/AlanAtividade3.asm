inicio:
 	addi $s0,$zero,0  #adiciono o valor zero ao registrador contador
 	addi $s1,$zero,20 #adiciona o valor final de i do somatorio
 	j loop            #pula para o loop
 loop:
 	addi $s0,$s0,1    #adiciona 1 a registrador de contador
 	sll $t0,$s0,2     #executa o shift, igual a multiplicar por 4
 	addi $t0,$t0,2    #adiciona dois ao resultado do shift
 	add $s2,$s2,$t0   #salva o valor de $t0 em $s2 
 	bne $s0,$s1 loop  #se for igual ao tamanho de $s1 para o loop
