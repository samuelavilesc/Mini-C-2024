.data
_a: .word 0
_b: .word 0
_c: .word 0
_d: .word 0
_e: .word 0
$str1: .asciiz "Inicio del programa\n"
$str2: .asciiz "Introduce el valor de \"c\" y de \"d\" :\n"
$str3: .asciiz "Valor de c y de d \n"
$str4: .asciiz "\n"
$str5: .asciiz "\n"
$str6: .asciiz "\n"
$str7: .asciiz "Final"
$str8: .asciiz "\n"
.text
.globl main
main:
li $t0,1
sw $t0,_a
li $t0,2
li $t1,3
mul $t0,$t0,$t1
sw $t0,_b
la $a0,$str1
li $v0,4
syscall
la $a0,$str2
li $v0,4
syscall
li $v0,5
syscall
sw $v0,_c
li $v0,5
syscall
sw $v0,_d
lw $t0,_c
lw $t1,_d
mul $t0,$t0,$t1
lw $t1,_a
lw $t2,_b
add $t1,$t1,$t2
div $t0,$t0,$t1
sw $t0,_e
la $a0,$str3
li $v0,4
syscall
lw $t0,_c
li $v0,1
move $a0,$t0
syscall
la $a0,$str4
li $v0,4
syscall
lw $t0,_d
li $v0,1
move $a0,$t0
syscall
la $a0,$str5
li $v0,4
syscall
lw $t0,_e
li $v0,1
move $a0,$t0
syscall
la $a0,$str6
li $v0,4
syscall
la $a0,$str7
li $v0,4
syscall
la $a0,$str8
li $v0,4
syscall
li $t0,1
sw $t0,_c
etiq1:
lw $t0,_c
li $t1,10
beq $t0,$t1,etiq2
lw $t2,_c
li $v0,1
move $a0,$t2
syscall
addi $t0,$t0,1
sw $t0,_c
b etiq1
etiq2:
li $v0, 10
syscall
