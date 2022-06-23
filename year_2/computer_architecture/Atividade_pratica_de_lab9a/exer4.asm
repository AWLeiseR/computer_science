.data
Res1: .asciiz "\n Insira a tamanho do vetor ->   " 
Res2: .asciiz "\n----Insira os elementos do vetor----\n" 
Res3: .asciiz "\n soma maxima: "
Res4: .asciiz "\n\n teste: "
Res5: .asciiz "\nteste2: "
ent: .asciiz "Insira um valor de vet["
ent2: .asciiz "]:"
val: .float 0.0
.align 2
vetX:

.text
main: li $s1, 0 #i
      l.s $f3, -1000#max
      jal leituraNumero
      move $s5, $v0 #numero
      la $a1, vetX 
      move $a3, $a1 #aux posicao vet
      li $t8, 4
      li $t3, 0 #cont
      jal ImprimirRes2
      jal leituraVet
      j somaMax
      li $v0, 10
      syscall
      
somaMax: bge $s1, $s5, ImprimirRes
	 l.s $f6, val #aux soma
	 add $s1, $s1, 1 #i++ 
	 move $a3, $a1 #aux posicao vet
	 add $a3, $a3, $t3 #indo na pos de i atual
	 l.s $f4, ($a3) 
	 c.lt.s   $f5, $f4
	 bc1t trocaSomaMax2
continua3:add.s $f6, $f6, $f4 #add vet[i] na soma aux
	 add $t3, $t3, 4 #add 4 
	 move $t5, $t3 #aux vet[j]
	 move $t6, $a1
	 add $t6, $t6, $t5
	 move $s2, $s1 
	 add $s2, $s2, 1
	 ble $s2, $s5, continuaSoma #j < n
	 j somaMax 
continuaSoma: l.s $f9, ($t6)
	      add.s $f6, $f6, $f9
	      add $s2, $s2, 1
	      add $t6, $t6, 4
	  vai: c.lt.s $f5, $f6
	       bc1t trocaSomaMax
continualoop: ble $s2, $s5,continuaSoma
	      j somaMax

trocaSomaMax: mov.s $f5, $f6
	      j continualoop
	      
trocaSomaMax2:mov.s $f5, $f4 
	      j continua3

ImprimirRes: mov.s $f0, $f5 #imprimir  maior valor
	  la $a0, Res3
	  li $v0,4
	  syscall
	  mov.s $f12,$f0
	  li $v0,2
	  syscall
	  li $v0, 10
	  syscall

ImprimirRes2:mov.s $f0, $f5 #imprime todos os valores
	     la $a0, Res2
	     li $v0,4
	     syscall
	     jr $ra


leituraNumero: la $a0, Res1
	 li $v0, 4
	 syscall
	 li $v0, 5
	 syscall
	 jr $ra


leituraVet: move $t0,$a1
         move $t1, $t0
         li $t2, 0 #zera t2
    loop:la $a0, ent
     	 li $v0, 4
     	 syscall 
     	 move $a0, $t2 
     	 li $v0, 1 
     	 syscall 
     	 la $a0, ent2 
     	 li $v0, 4
     	 syscall 
     	 li $v0, 6
     	 syscall 
     	 s.s $f0, ($t1)
     	 add $t1, $t1, 4
     	 addi $t2, $t2, 1 
     	 blt $t2,  $s5, loop
     	 move $v0, $t0
     	 jr $ra
     	 
escrita: move $t0, $a1
	 move $t1, $t0
	 li $t2, 0
e:       l.s $f12, ($t1)
	 beq $a0, 0, vaiadd 
	 li $v0, 2 
	 syscall 
	 li $a0, 32 
	 li $v0, 11
	 syscall 
vaiadd:  add $t1, $t1, 4
	 addi $t2, $t2, 1
	 blt $t2, $s5, e
	 move $v0, $t0
	 jr $ra
	
