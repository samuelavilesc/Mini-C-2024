.data
_a: .word 0
_b: .word 0
_c: .word 0
_d: .word 0
_e: .word 0
$str1: .asciiz "Inicio del programa\n"
$str2: .asciiz "Introduce el valor de \"c\":\n"
$str3: .asciiz "\"c\" no era nulo."
$str4: .asciiz "\n"
$str5: .asciiz "\"c\" si era nulo."
$str6: .asciiz "\n"
$str7: .asciiz "Valores de d hasta que valga 0\n"
$str8: .asciiz "\"d\" vale"
$str9: .asciiz "\n"
$str10: .asciiz "Valores de e hasta que valga 0\n"
$str11: .asciiz "\"e\" vale"
$str12: .asciiz "\n"
$str13: .asciiz "Valores de c hasta que valga 10\n"
$str14: .asciiz "\"c\" vale"
$str15: .asciiz "\n"
$str16: .asciiz "Final"
$str17: .asciiz "\n"
.text
.globl main
main:
li $t0,1
sw $t0,_a
li $t0,2
li $t1,3
mul $t0,$t0,$t1
sw $t0,_b
li $t0,5
li $t1,2
add $t0,$t0,$t1
sw $t0,_d
li $t0,9
li $t1,3
div $t0,$t0,$t1
sw $t0,_e
la $a0,$str1
li $v0,4
syscall
la $a0,$str2
li $v0,4
syscall
li $v0,5
syscall
sw $v0,_c
lw $t0,_c
li $t1,0
sne $t0,$t0,$t1
beqz $t0,etiq1
la $a0,$str3
li $v0,4
syscall
la $a0,$str4
li $v0,4
syscall
b etiq2
etiq1:
la $a0,$str5
li $v0,4
syscall
la $a0,$str6
li $v0,4
syscall
etiq2:
la $a0,$str7
li $v0,4
syscall
etiq3:
lw $t0,_d
li $t1,0
sne $t0,$t0,$t1
beqz $t0,etiq4
la $a0,$str8
li $v0,4
syscall
lw $t1,_d
li $v0,1
move $a0,$t1
syscall
la $a0,$str9
li $v0,4
syscall
lw $t1,_d
li $t2,1
sub $t1,$t1,$t2
sw $t1,_d
b etiq3
etiq4:
la $a0,$str10
li $v0,4
syscall
etiq5:
la $a0,$str11
li $v0,4
syscall
lw $t0,_e
li $v0,1
move $a0,$t0
syscall
la $a0,$str12
li $v0,4
syscall
lw $t0,_e
li $t1,1
sub $t0,$t0,$t1
sw $t0,_e
lw $t0,_e
li $t1,0
sgt $t0,$t0,$t1
bnez $t0,etiq5
la $a0,$str13
li $v0,4
syscall
li $t0,1
sw $t0,_c
etiq6:
lw $t1,_c
li $t2,10
slt $t1,$t1,$t2
beqz $t1,etiq7
la $a0,$str14
li $v0,4
syscall
lw $t3,_c
li $v0,1
move $a0,$t3
syscall
la $a0,$str15
li $v0,4
syscall
li $t2,2
add $t0,$t0,$t2
sw $t0,_c
b etiq6
etiq7:
la $a0,$str16
li $v0,4
syscall
la $a0,$str17
li $v0,4
syscall
li $v0, 10
syscall
