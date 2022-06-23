.data
Mat:	.space 48
MatRot:	.space 48
MatTam:	.word 3
Out1:	.asciiz "Insira os 9 elementos da matriz:\n"
Out2:	.asciiz "A matriz gira "

.text
main:
	jal leMat
	jal imprime
	#giram 90º
	la $s3, Mat
	la $s2, MatRot
	jal rotacionaMat
	la $a0, Out2
	li $v0, 4
	syscall
	li $a0, 90
	li $v0, 1
	syscall
	la $a3, MatRot
	jal imprime
	#gira 90º
	la $s3, MatRot
	la $s2, Mat
	jal rotacionaMat
	la $a0, Out2
	li $v0, 4
	syscall
	li $a0, 180
	li $v0, 1
	syscall
	la $3, Mat
	jal imprime
	#gira 90º 
	la $s3, Mat
	la $s2, MatRot
	jal rotacionaMat
	la $a0, Out2
	li $v0, 4
	syscall
	li $a0, 270
	li $v0, 1
	syscall
	la $3, MatRot
	jal imprime
	
	j fim
#funcao gira 90º para a direita
#$s3 matriz para ser rotacionada
#$s2 matriz destino
rotacionaMat:	
	move $a0, $ra
	jal fStart
	li $s0, 0
	li $s1, 0
	lw $a2, MatTam
rotacionaMatLoop:
	move $a0, $s0
	move $a1, $s1
	move $a3, $s3
	jal matIndex
	lw $t0, ($v0)
	subi $t9, $a2, 1
	beqz $s0, rotacionaMatLoopCaso1		
	beq $s1, $t9, rotacionaMatLoopCaso2	
	beq $s0, $t9, rotacionaMatLoopCaso3	
	beqz $s1, rotacionaMatLoopCaso4		
	j rotacionaMatLoopEscreve		
rotacionaMatLoopCaso1:
	sub $t1, $t9, $s1	#movimentos horizontais
	sub $t2, $t9, $t1	#movimentos verticais 
	add $a0, $s0, $t2
	add $a1, $s1, $t1
	j rotacionaMatLoopEscreve
rotacionaMatLoopCaso2:
	move $t1, $s0		#movimentos horizontais 
	sub $t2, $t9, $t1	#movimentos verticais
	add $a0, $s0, $t2
	sub $a1, $s1, $t1
	j rotacionaMatLoopEscreve
rotacionaMatLoopCaso3:
	move $t1, $s1		
	sub $t2, $t9, $t1	
	sub $a0, $s0, $t2
	sub $a1, $s1, $t1
	j rotacionaMatLoopEscreve
rotacionaMatLoopCaso4:
	move $t1, $s0		
	sub $t2, $t9, $t1	
	sub $a0, $s0, $t2
	add $a1, $s1, $t1
	j rotacionaMatLoopEscreve
rotacionaMatLoopEscreve:
	move $a3, $s2
	jal matIndex
	sw $t0, ($v0)
	addi $s1, $s1, 1
	blt $s1, $a2, rotacionaMatLoop
	li $s1, 0
	addi $s0, $s0, 1
	blt $s0, $a2, rotacionaMatLoop
	j return
#funcao Imprime a matriz
#$a3 matriz impressa
imprime:
	move $a0, $ra
	jal fStart
	li $a0, 10
	li $v0, 11
	syscall
	li $t0, 0
	li $t1, 0
	lw $a2, MatTam
imprimeLoop:
	move $a0, $t0
	move $a1, $t1
	jal matIndex
	lw $a0, ($v0)
	li $v0, 1
	syscall
	li $a0, 32
	li $v0, 11
	syscall
	addi $t1, $t1, 1
	blt $t1, $a2, imprimeLoop
	li $a0, 10
	li $v0, 11
	syscall
	li $t1, 0
	addi $t0, $t0, 1
	blt $t0, $a2, imprimeLoop
	j return
	
leMat:		
	move $a0, $ra
	jal fStart
	la $a0, Out1
	li $v0, 4
	syscall
	li $a0, 0
	li $a1, 0
	lw $a2, MatTam
	la $a3, Mat
leMatLoop:
	li $v0, 5
	syscall
	move $t0, $v0
	jal matIndex
	sw $t0, ($v0)
	addi $a1, $a1, 1
	blt $a1, $a2, leMatLoop
	li $a1, 0
	addi $a0, $a0, 1
	blt $a0, $a2, leMatLoop
	j return

malloc:	
	li $v0, 9
	syscall
	jr $ra
fStart:	
	subi $sp, $sp, 4
	sw $a0, ($sp)
	jr $ra
return:	
	lw $ra, ($sp)
	addi $sp, $sp, 4
	jr $ra
matIndex:	
		t
	mul $v0, $a0, $a2
	add $v0, $v0, $a1
	sll $v0, $v0, 2
	add $v0, $v0, $a3
	jr $ra
fim:
	li $v0, 10
	syscall
