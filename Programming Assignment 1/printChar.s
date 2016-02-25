/*Filename printChar.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description:
 *Date: 1/20/2015
 *
 */
 	.global printChar
	
	.section ".data"	!data segment starts here
fmt:
	.asciz	"%c"		!ascii value of inputted character

	.section ".text"	!text segment starts here
/*
 *Function name:printChar()
 *Function prototype: printChar(char )
 *Description:prints out a specific character
 *Parameters: character
 *Registers used: o0 and o1 to print out character
 */

printChar:

	save	%sp,-96,%sp	!allocates space

	set	fmt,%o0		!put character in o0
	mov	%i0,%o1		
	call 	printf		!call the function
	nop
	
	ret 			!return and restore
	restore
