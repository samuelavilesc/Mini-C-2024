.data
_c: .word 0
_b: .word 0
_a: .word 0
$str1: .asciiz "Hola mundo\n"
$str2: .asciiz "\n"
$str3: .asciiz "a"
$str4: .asciiz "b"
.text
.globl main
main:
li $t1,1
neg $t1,$t1
lw $t2,_b
add $t1,$t1,$t2
sw $t1,_a
li $v0,4
la $a0,$str1
syscall
li $t1,42
li $v0,1
move $a0,$t1
syscall
li $v0,4
la $a0,$str2
syscall
lw $t1,_a
beqz $t1,etiq1
li $v0,4
la $a0,$str3
syscall
b etiq2
etiq1:
li $v0,4
la $a0,$str4
syscall
etiq2:
li $v0, 10
syscall
