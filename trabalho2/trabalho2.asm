#	Adailson Pinho dos Santos - 13/0140724
#	Vitor Nere Araújo Ribeiro - 13/0137413
.data
	insira_primo:	.asciiz "\nInsira um numero primo: "
	insira_inteiro:	.asciiz "Insira um numero inteiro: "  
	text_erro:	.asciiz "\nO modulo nao e primo.\n"
	text_inverso:	.asciiz "\nO inverso multiplicativo e: "
	text_ponto:	.asciiz	".\n"
.text

__start:
	jal	ler_inteiro			# jump to ler_inteiro and save position to $ra
    
	jal	eh_primo			# jump to eh_primo and save position to $ra
    
	slti	$t0, $s3, 1			# if $s3 < 1 then $t0 = 1 (not prime) else $t0 = 0 (prime)
    
	beq	$t0, $zero, j_calc_inverso	# if $t0 != $zero then calc_inverso else imprime_erro
    
	bne	$t0, $zero, imprime_erro	# jump to imprime_erro
    
	j_calc_inverso:
		jal	calc_inverso		# jump and link to calc_inverso
    
		jal	imprime_saida		# jump and link to imprime_saida

	finalizar:
		li  $v0, 10			# system call code for end program
		syscall				# call operation system


# scanf("%d", &num1);
# scanf("%d", &num2);
ler_inteiro:
	# Print input messeger
	li	$v0, 4			# system call code for print string in $a0
	la	$a0, insira_primo	# load address of string to be printed into $a0
	syscall				# call operation system

	# User input value
	li	$v0, 5			# system call code for read integer = 5
	syscall

	# Move value to t0
	move	$s1, $v0		# move value to from $v0 to $t0 in wich is used to be print integer

	# Print input messeger
	li	$v0, 4			# system call code for print string in $a0
	la	$a0, insira_inteiro	# load address of string to be printed into $a0
	syscall				# call operation system

	# User input value
	li	$v0, 5			# system call code for read integer = 5
	syscall

	# Move value to t0
	move	$s2, $v0		# move value to from $v0 to $t0 in wich is used to be print integer
    
	jr	$ra			# jump to $ra and save position to $ra
    

#int eh_primo(int p) {
#    if(p < 3 && p >= 1) 
#      return 1; // 
#    else if(p<1)
#        return 0;
#    else {
#        i = p-2;
#        do {
#            if(p%i == 0)
#                return 0;
#
#            i = i-2;    
#        } while(i != 1);
#    }
#
#    return 1;
#}
eh_primo:
	slti	$s0, $s1, 1				# if $s1 < 1 then $s0 = 1 else $s0 = 0
    
	bne	$s0, $zero, nao_eh_primo		# if $s0 != $zero then go to the nao_eh_primo
    
	slti	$s0, $s1, 3				# if $s1 < 3 then $s0 = 1 else $s0 = 0
    
	bne	$s0, $zero, nao_eh_primo		# if $s0 != $zero then go to the nao_eh_primo
    
	addi	$a0, $s1, -2				# $a0 = s2 - 2
	loop_eh_primo:
		div	$s1,$a0				# hi = remainder of $s1 / $a0
		mfhi	$t0				# move hi to $t0
		beq	$t0, $zero, nao_eh_primo	# if $t0 == $t1 then go to the nao_eh_primo
    
		addi	$a0, $a0, -2			# $a0 = $a0 - 2
		slti	$s0, $a0, 2			# if $a0 < 3 then $s0 = 1 else $s0 = 0
        
		bne	$s0, $zero, retorna_eh_primo	# if $s0 !=zerot1 then target

		j loop_eh_primo

	nao_eh_primo:
		addi	$s3, $zero, 0			# set $s3 = 0 (false)
		jr	$ra				# jump to $ra and save position to $ra

	retorna_eh_primo:
		addi	$s3, $zero, 1			# set $s3 = 1 (true)
		jr	$ra				# jump to $ra and save position to $ra
    
#int inverso(int num1, int num2) {
#    int i = num1 - 1;
#    int multi, mod;
#
#    do {
#        multi = num2 * i;
#        mod = multi % num1;
#        if(mod == 1) {
#            return i;
#        }
#
#        i--;
#    } while(i != 0);
#}
calc_inverso:
	addi	$a0, $s1, -1				# $a0 = $s1 - 1
	loop_calc_inverso:
		mult	$s2, $a0			# $$s2 * $a0 = Hi and Lo registers
		mflo	$a1				# copy Lo to $a1
		div	$a1, $s1			# $a1 / $s1
		mfhi	$a2					# $a2 = $a1 mod $t1
		addi	$a3, $zero, 1			# $a3 = 0 + 1
		beq	$a2, $a3, retorna_inverso	# if $a2 == $t1 then target
        
		addi	$a0, $a0, -1			# $a0 = $a0 - 1
		j	loop_calc_inverso		# jump to loop_calc_inverso
	retorna_inverso:
		move	$s4, $a0			# $s4 = $a0
		jr	$ra				# jump to $ra and save position to $ra

# if(eh_primo(num1) != 1)
#        printf("O modulo nao e primo.\n");
imprime_erro:
	li	$v0, 4		# system call code for print string in $a0
	la	$a0, text_erro	# load address of string to be printed into $a0
	syscall			# call operation system
	j	finalizar	# Jump to finalizar

# printf("O inverso multiplicativo%d.\n", res);
imprime_saida:
	li	$v0, 4			# system call code for print string in $a0
	la	$a0, text_inverso	# load address of string to be printed into $a0
	syscall				# call operation system

	li	$v0, 1			# system call code for print integer = 1
	move	$a0, $s4		# move value to from $s4 to $a0 in wich is used to be print integer
	syscall				# call operation
    
	li	$v0, 4			# system call code for print string in $a0
	la	$a0, text_ponto		# load address of string to be printed into $a0
	syscall				# call operation system

	jr	$ra			# jump to $ra and save position to $ra
