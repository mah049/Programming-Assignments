/*Filename: charCompare.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: compares two characters
 *Date: 2/24/2015
 *
 */

	.global charCompare		!declares the symbol to be globally
					!visible

	.section ".text"		!text segment begins here

/*
 *FunctionName : charCompare()
 *Function prototype: int charCompare(const void *p1, const void *p2);
 *Description: compares two chars and returns cvalues
 *based on the return value of strcmp
 *Parameters: p1: the first pointer to compare
 *            p2: the second pointer to compare
 *Return value: int based on what happeneds < > = 0
 *Registers used: %o0o1, because it is a leaf subroutine
 *and arguemnts
 *
 */

charCompare:
	
	ldub	[%o0],%o0		!load unsigned byte
	ldub	[%o1],%o1		!load unsigned byte

	sub	%o0,%o1,%o0		!gets the difference and returns 
					!its value

	retl				!return from leaf subroutine
	nop
	
	


