.data
_a: .word 0
_b: .word 0
_c: .word 0
$str1: .asciiz "Inicio del programa\n"
$str2: .asciiz "a"
$str3: .asciiz "\n"
$str4: .asciiz "No a y b\n"
$str5: .asciiz "c = "
$str6: .asciiz "\n"
$str7: .asciiz "Final"
$str8: .asciiz "\n"
.text
.globl main
main:
li $t0,0
sw $t0,_a
li $t0,0
sw $t0,_b
li $t0,5
li $t1,2
add $t0,$t0,$t1
li $t1,2
sub $t0,$t0,$t1
sw $t0,_c
la $a0,$str1
li $v0,4
syscall
lw $t0,_a
beqz $t0,etiq5
la $a0,$str2
li $v0,4
syscall
la $a0,$str3
li $v0,4
syscall
b etiq6
etiq5:
lw $t1,_b
beqz $t1,etiq3
la $a0,$str4
li $v0,4
syscall
b etiq4
etiq3:
etiq1:
lw $t2,_c
beqz $t2,etiq2
la $a0,$str5
li $v0,4
syscall
lw $t3,_c
li $v0,1
move $a0,$t3
syscall
la $a0,$str6
li $v0,4
syscall
lw $t3,_c
li $t4,2
sub $t3,$t3,$t4
li $t4,1
add $t3,$t3,$t4
sw $t3,_c
b etiq1
etiq2:
etiq4:
etiq6:
la $a0,$str7
li $v0,4
syscall
la $a0,$str8
li $v0,4
syscall
li $v0, 10
syscall
