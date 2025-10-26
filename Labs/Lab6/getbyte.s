# Program: getbyte.s
# Purpose: Extracts byte n from a 4-byte word x
# Author: Kayla Walsh McCarter
# Date: 10/9/2025

.LCO:
	.string "Byte %d of %X is %X\n"

	.globl	main
main:
	pushl	%ebp		# save frame pointer
	movl	%esp,%ebp	# adjust stack pointer

	movl	$0x12345678,%edx		#set edx=x where x is 0x12345678
	movl	%edx,%eax		#set eax=edx	eax will be our answer
	movl	$2,%ebx			#set ebx=n where n is 1
	movl	$8,%ecx		#set ecx=8	ecx is what we'll shift by
	imull	%ebx,%ecx	#multiply ebx=n by ecx=8 to get ecx=n*8
	shrl	%ecx,%eax	#shift eax=x by ecx=n*8 to get byte n to lsbyte
	andl	$0xFF,%eax	#0xFF & %eax=shifted x to mask all but lsbyte

	pushl	%eax		#push eax (answer) to stack
	pushl	%edx		#push edx (original x) to stack
	pushl	%ebx		#push ebx (n) to stack
	pushl	$.LCO		#push the string to  stack
	call	printf		#calls the printf function

	leave			# restore the current activation
	ret			# return to caller
