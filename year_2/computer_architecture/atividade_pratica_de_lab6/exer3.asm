.data
str1: .space 100
ent1: .asciiz "insira uma String: "

.text

Main:	la $a0,ent1
	la $a1,str1
	jal leitura
	la $s1,str1
	jal soma
	li $v0,4
	syscall
	li $v0,10
	syscall

leitura:
	li $v0,4 
	syscall
	move $a0,$a1
	li $a1,100
	li $v0,8
	syscall
	jr $ra

	
soma:	move $t1,$s1
loop:	lb $t0,($t1)
	bge $t0,119,final
	beq $t0,87,final
	beq $t0,88,final
	beq $t0,89,final
	beq $t0,90,final
	addi $t0,$t0,4
	sb $t0,($t1)
final:	addi $t1,$t1,1
	lb $s1,($t1)
	bne $s1,10,loop
	jr $ra

