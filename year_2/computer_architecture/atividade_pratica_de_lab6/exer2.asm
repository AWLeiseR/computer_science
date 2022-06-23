.data
vet: .space 100
entrada: .asciiz "insira uma String: "
.text

Main: 	la $s0, vet
	la $a0, entrada
	jal leitura
	jal maiusculo
	move $a0, $s0
	li $v0, 4
	syscall
	li $v0,10
	syscall
	
leitura:
	li $v0,4
	syscall
	move $a0,$s0
	li $a1,100
	li $v0,8
	syscall
	jr $ra
	
maiusculo:
	move $t1,$s0
loop:	lb $s1,($t1)
	ble $s1,90,final
	subi $s1,$s1,32
	sb $s1,($t1)
final:	addi $t1,$t1,1
	lb $s1,($t1)
	bne $s1, 10,loop
	jr $ra