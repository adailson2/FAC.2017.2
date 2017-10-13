.data
	insira_real:	.asciiz "\nInsira um numero real: "
	text1:		.asciiz "\nO arcseno de "
	text2:		.asciiz " é "
	text3:		.asciiz "."
	text4:		.asciiz " Usamos 10 termos da serie."
.text

__start:
	jal	ler_real		# jump to ler_real and save position to $ra
	
	jal	calc_arcsen		# jump to calc_arcsen and save position to $ra
	
	jal	imprime_saida		# jump to imprime_saida and save position to $ra
	
__end:
	li  $v0, 10			# system call code for end program
	syscall				# call operation system

# scanf("%f", &num1);
ler_real:
	# Print input messeger
	li	$v0, 4			# system call code for print string in $a0
	la	$a0, insira_real	# load address of string to be printed into $a0
	syscall				# call operation system

	# User input value
	li	$v0, 6			# system call code for read float = 6
	syscall				# call operation system
	
	# Move value to s1
	mov.s	$f20, $f0		# move value from $f0 (function return) to $f20
    
	jr	$ra			# jump to addres in $ra and save position to $ra

calc_arcsen:
	mov.s	$f4, $f20		# move from $f20 to temporary $f4
	mov.s	$f22, $f20		# move from $f20 to result $f22
	
	addi	$t1, $zero, 0		# adding 0 to t1 (iterator register)
	
	
	addi	$t2, $zero, 3000	# adding 3000 to loop into t2
	
	loop:
		addi	$t1, $t1, 1		# $t1 = $t1 + 1
		mtc1	$t1, $f2		# integer t1 arrives in coprocessor $f1
		cvt.s.w	$f6, $f2		# convert t1 to float into $f6
		
		mul.s	$f8, $f20, $f20		# $f8 = $f20 * $f20
		
		# $f10 = 2*$f6
		addi	$t3, $zero, 2		# $t3 = 2
		mtc1	$t3, $f2		# integer 2 arrives in coprocessor $f1
		cvt.s.w	$f16, $f2		# convert 2 to 2.0 into $f16
		mul.s	$f10, $f16, $f6		# $f10 = $f16 * $f6
		
		# $f10 = $f10-1
		addi	$t3, $zero, 1		# $t3 = -1
		mtc1	$t3, $f2		# integer -1 arrives in coprocessor $f1
		cvt.s.w	$f16, $f2		# convert -1 to -1.0 into $f16
		sub.s	$f10, $f10, $f16	# $f10 = $f10 - $f16
	
		mul.s	$f10, $f10, $f10	# $f10 = $f10 * $f10
		
		mul.s	$f8, $f8, $f10		# $f8 = $f8 * $f10
		
		# $f16 = 2*$f6
		addi	$t3, $zero, 2		# $t3 = 2
		mtc1	$t3, $f2		# integer 2 arrives in coprocessor $f1
		cvt.s.w	$f16, $f2		# convert 2 to 2.0 into $f16
		
		mul.s	$f16, $f16, $f6		# $16 = $f16 * f6
		
		# $f18 = (2*$f6) = $f16
        	# $f18 = $f18 + 1
        	addi	$t3, $zero, 1		# $t3 = 1
        	mtc1	$t3, $f2		# integer 1 arrives in coprocessor $f1
		cvt.s.w	$f18, $f2		# convert 1 to 1.0 into $f16
		
		add.s	$f18, $f18, $f16	# $f18 = $f16 + 1.0
		
		mul.s	$f10, $f16, $f18	# $f10 = $f16 * $f18
		
		div.s	$f8, $f8, $f10		# $f8 = $f8 + $f10
		
		mul.s	$f4, $f4, $f8		# $f4 = $f4 + $f8
		
		add.s	$f22, $f22, $f4		# $f22 = $f22 + $f4
		
		beq	$t1, $t2, end_loop	# if t1 equals 3000 ends loop
		
		j	loop			# jump to continue loop
		
	end_loop:
	
# if nececessary round the final value
round:
	addi	$t3, $zero, 100		# $t3 = 100
        mtc1	$t3, $f2		# integer 100 arrives in coprocessor $f2
        cvt.s.w	$f16, $f2		# convert 100 to 100.0 into $f16
       	
        mul.s	$f6, $f22, $f16		# $f22 * 100.0
        cvt.w.s $f0, $f6		# ignore the remainder of $f22
        cvt.s.w	$f6, $f0		# convert to float ($f22.0) = $f6.0
        
        addi	$t3, $zero, 10		# $t3 = 10
        mtc1	$t3, $f2		# integer 10 arrives in coprocessor $f2
        cvt.s.w	$f18, $f2		# convert 10 to 10.0 into $f16
        
        sub.s	$f8, $f22, $f6		# pick the remainder of $f22
        mul.s	$f10, $f8, $f18		# f8 * 10
 
        # Verify if final value is negative
        addi	$t3, $zero, 0		# $t3 = 0
        mtc1	$t3, $f2		# integer 0 arrives in coprocessor $f2
        cvt.s.w	$f8, $f2		# convert 0 to 0.0 into $f16
        
        c.lt.s	$f6, $f8		# if $f10 < 0
        bc1f	positivo		# jump to positivo if $f10 > 0
        
        # round negative value
        addi	$t3, $zero, -5		# $t3 = -5
        mtc1	$t3, $f2		# integer -5 arrives in coprocessor $f2
        cvt.s.w	$f8, $f2		# convert -5 to -5.0 into $f16
        
        c.lt.s	$f10, $f8		# if $f10 < -5.0
        bc1t	continua		# jump to continua if $f10 > -5.0
        
        # else round the final value to up (or down in this case)
        addi	$t3, $zero, -1		# $t3 = -1
        mtc1	$t3, $f2		# integer -1 arrives in coprocessor $f2
        cvt.s.w	$f8, $f2		# convert -1 to -1.0 into $f16
        
        add.s	$f6, $f6, $f8		# $f6 = $f6 - 1.0
       	j continua			# jump to continua
        
        # round positive value
        positivo:
        addi	$t3, $zero, 5		# $t3 = 5
        mtc1	$t3, $f2		# integer 5 arrives in coprocessor $f2
        cvt.s.w	$f8, $f2		# convert 5 to 5.0 into $f16
        
        c.lt.s	$f10, $f8		# if $f10 < 5.0
        bc1f	continua		# jump to continua if $f10 < 5
        
        # else round the final value to up
        addi	$t3, $zero, 1		# $t3 = 1
        mtc1	$t3, $f2		# integer 1 arrives in coprocessor $f2
        cvt.s.w	$f8, $f2		# convert 1 to 1.0 into $f16
        
        add.s	$f6, $f6, $f8		# $ff6 = $f6 + 1.0
       	
       	continua:	
	
	div.s $f22, $f6, $f16		# f22 = $f18 / 100
	
	jr	$ra			# jump to addres in $ra and save position to $ra
		
		

imprime_saida:
	li	$v0, 4			# system call code for print string in $a0
	la	$a0, text1		# load address of string to be printed into $a0
	syscall				# call operation system

	li	$v0, 2			# system call code for print float = 2
	mov.s	$f12, $f20		# move value to from $f20 to $f12 in wich is used to be print integer
	syscall				# call operation system

	li	$v0, 4			# system call code for print string in $a0
	la	$a0, text2		# load address of string to be printed into $a0
	syscall				# call operation system

	li	$v0, 2			# system call code for print float = 2
	mov.s	$f12, $f22		# move value to from $f22 to $f12 in wich is used to be print integer
	syscall				# call operation
    
	li	$v0, 4			# system call code for print string in $a0
	la	$a0, text3		# load address of string to be printed into $a0
	syscall				# call operation system

	li	$v0, 4			# system call code for print string in $a0
	la	$a0, text4		# load address of string to be printed into $a0
	syscall				# call operation system
		
	jr	$ra			# jump to addres in $ra and save position to $ra
