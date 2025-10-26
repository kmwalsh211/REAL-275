# Program: prime.s
# Purpose: determine if a number is prime
# Author: Kayla Walsh McCarter
# Date: 10/23/2025

.LC0:
    .string "%d is a prime number.\n"
.LC1:
    .string "%d is not a prime number.\n"
.LC2:
    .string "Enter a positive number: \n"
.LC3:
    .string "%d"
    

    .globl	main
main:
    pushl %ebp
    movl %esp,%ebp
    
    pushl $.LC2         	#push string "Enter a positive number" to stack
    call printf          	#print that string
    
    subl $4,%esp         	#allocate space on stack for integer
    leal -4(%ebp),%eax   	#load the address of data item into register
    pushl %eax           	#push address of data item in the register
    pushl $.LC3          	#push format string
    call scanf

    leal -4(%ebp),%eax		#store user input in %eax
    cmpl $2,(%eax)		#compare it to 2
    jl .false			#if its less than 2, jump to false
    je .true
    movl $2,%esi		#esi = i = 2

.loop:
    
    movl -4(%ebp),%ebx		#store user input in %ebx
    
    movl %ebx,%eax
    cltd
    divl %esi			#divide number by i : result in %eax, R in %edx
    
    cmpl $0,%edx		#compare edx to 0
    je .false			#if remainder is 0, jump to false. It had no remainer,
    				#so number is divisible by something other than itself and 1
    
    addl $1,%esi		#i++
    cmpl %ebx,%esi		#compare i to number
    jl .loop			#if i < number, jump to loop
    jmp .true			#if i !< number, jump to true (all cases passed)
    
.true:
    leal -4(%ebp),%eax
    pushl (%eax)
    pushl $.LC0
    call printf
    jmp .done
    
.false:
    leal -4(%ebp),%eax
    pushl (%eax)
    pushl $.LC1
    call printf
    jmp .done

.done:
    leave	 	  	#restore the current activation
    ret			  	#return to caller
