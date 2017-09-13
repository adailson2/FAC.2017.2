.data
     text:  .asciiz "Insira um número primo: "
     text2:  .asciiz "Insira um número inteiro: "
.text

ler_inteiro:
    # Print input messeger
    li $v0, 4           # system call code for print string in $a0
    la $a0, text        # load address of string to be printed into $a0
    syscall             # call operation system

    # User input value
    li $v0, 5           # system call code for read integer = 5
    syscall

    # Move value to t0
    move $t0, $v0       # move value to from $v0 to $t0 in wich is used to be print integer

    # Print input messeger
    li $v0, 4           # system call code for print string in $a0
    la $a0, text2        # load address of string to be printed into $a0
    syscall             # call operation system

    # User input value
    li $v0, 5           # system call code for read integer = 5
    syscall

    # Move value to t0
    move $t1, $v0       # move value to from $v0 to $t0 in wich is used to be print integer
    
    # End program
    li $v0, 10          # system call code for terminate program = 10
    syscall             # call operation

eh_primo:
    
calc_inverso:


imprime_erro:

imprime_saida:

    # Print value
    li $v0, 1           # system call code for print integer = 1
    move $a0, $t0       # move value to from $t0 to $a0 in wich is used to be print integer
    syscall             # call operation
