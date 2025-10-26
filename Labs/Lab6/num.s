	.LC0:
		.string	"x = %d y = %d\n"

		.globl	main
	main:
		pushl	%ebp		# save frame pointer
		movl	%esp,%ebp	# adjust stack pointer

		movl	$10,%eax	#set eax=10
		movl	$20,%ebx	#set ebx=20
		pushl	%ebx		#push ebx to top of stack
		pushl 	%eax		#push eax to top of stack
		pushl	$.LC0		#push the value of .LCO to top of stack
		call	printf		#calls the printf function

		leave			# restore the current activation
		ret			# return to caller
