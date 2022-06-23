.data
vetor: .word 1 5 -10 15 27 30 32 10 -90 100




.text

jal ordenar	#funcao que ordena elementos de um vetor
li $v0, 10 	#finaliza
syscall




ordenar:
li $t0, 10			#numero de valores do vetor (n)
subi $t0, $t0, 1		# n = n-1, porque substituicao ocorre entre as posicoes n e n+1 (evita acessar posicao inexistente do vetor) 
li $t1, 0			#contador de iteracao (i)
la $t2, vetor			#endereco do vetor
ordenarLoop:
lw $t3, ($t2)			#le numero do vetor
addi $t2, $t2, 4			#aumenta offset do endereco do vetor
lw $t4, ($t2)			#le numero do vetor
bgt $t3, $t4, ordenarTrocar	#troca os valores caso t3 > t4
				#Else: (caso t3 e t4 ja estejam ordenados)
addi $t1, $t1, 1			#aumenta contador de iteracoes (i)
#addi $t2, $t2, 4		#aumenta offset do vetor
blt $t1, $t0, ordenarLoop	#retorna ao loop enquanto i < n
jr $ra				#retorna p/  main quando ler os ultimos dois valores e eles ja estiverem ordenados

ordenarTrocar:
sw $t3, ($t2)			#posicao de t4 do vetor recebe valor de t3
subi $t2, $t2, 4		#diminui offset do vetor (volta da posicao de t4 para posicao de t3)
sw $t4, ($t2)			#posicao de t3 do vetor recebe valor de t4
j ordenar			#retorna para funcao de ordenacao (comeca as comparacoes novamente)







