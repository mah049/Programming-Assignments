/*
 *Filename: isOdd.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: determines wheter the inputted number is odd
 *Date:1/20/2015
 *
 */

	.global isOdd		!Declares the symbol to be globally visiblie
				!so we cancall this fnunction from other modules
	.section ".text"

	FACTOR = 2		!we mod by this number

/*
 *Function name: isOdd()
 *Function prototype: int isOdd(long number)
 *Description: determines whether the inputted number is odd
 *Parameters: long number: the user inputted number
 *Return Value: 1 or 0 depedning on whether it is odd or not
 *Register Used: %i0 the argument and the returned
 *		 %o0,%o1 used to call .rem
 *
 */

isOdd:
	save	%sp, -96, %sp	!save caller's window

	mov	%i0,%o0		!move the input to o0
	mov	FACTOR,%o1	! move factor to o1
	call	.rem		!call the mod
	nop

	mov	%o0,%i0		!mov the result to output

	ret			!return from subroutine
	restore			!restore caller's window;in "ret"delay slot

	

