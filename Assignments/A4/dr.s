# Program: dr.s
# Purpose: calculate the digital root of a positive number
# Author: Kayla Walsh McCarter
# Date: 10/26/2025

.LC0:
    .string "Enter a positive number: \n"
.LC1:
    .string "%d"
.LC2:
    .string "The digital root of %d is %d.\n"
    
    .globl  main
main:
    pushl   %ebp                #push old %ebp onto the stack
    movl    %esp,%ebp           #set the new base pointer
    
    pushl   $.LC0         	    #push string "Enter a positive number" to stack
    call    printf          	#print that string
    subl    $4,%esp         	#allocate space on stack for the integer
    leal    -4(%ebp),%eax   	#load the desired address of the integer into register
    pushl   %eax           	    #push desired address of the integer to the stack
    pushl   $.LC1          	    #push format string
    call    scanf               #call scanf function and store user input at -4(%ebp)
    
    movl    -4(%ebp),%edx       #store original number in %edx
    movl    %edx,-8(%ebp)       #store copy of original number at -8(%ebp)
    movl    $10,-12(%ebp)       #store immediate 10 at -12(%ebp)
    
# Function: dr
# Recursively calculates the digital root of the integer stored at -8(%ebp)
.dr:
    movl    -8(%ebp),%eax       #move n into %eax
    cmpl    $10,%eax            #compare n to 10
    jl      .done               #if n < 10, jump to done
    
    xorl    %esi,%esi           #set %esi = 0
    movl    -8(%ebp),%ebx       #store n in %ebx
    
# Function: sumOfDigits
# Adds up each digit in the integer at -8(%ebp) and stores the sum at -8(%ebp)
.sumOfDigits:
    movl    %ebx,%eax
    cltd
    divl    -12(%ebp)           #divide n by 10 : result in %eax, remainder in %edx
    
    addl    %edx,%esi           #add remainder to %esi
    movl    %esi,-8(%ebp)       #store %esi (sum of digits so far) in -8(%ebp)
    movl    %eax,%ebx           #store result in %ebx
    
    testl    %ebx,%ebx          #test if %ebx = 0
    je      .dr                 #if %ebx = 0, jump to dr function
    jmp     .sumOfDigits        #if %ebx != 0, continue the loop
    
# Function: done
# Prints the calculated digital root and exits
.done:
    movl    -4(%ebp),%ecx       #move original number into %ecx
    movl    -8(%ebp),%eax       #move dr into %eax
    pushl   %eax                #push %eax (dr)
    pushl   %ecx                #push %ecx (original number)
    pushl   $.LC2               #push string "The digital root of %d is %d.\n"
    call    printf
    
    leave	 	  	            #restore the current activation
    ret			  	            #return to caller
