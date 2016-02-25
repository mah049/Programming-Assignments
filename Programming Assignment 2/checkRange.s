/*
 *Filename: checkRanges.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description:checks wheter the number is within a valid range
 *Date:1/20/2015
 *
 */

	.global checkRange	!Declares the symbol to be globally visiblie
				!so we cancall this fnunction from other modules
	.section ".text"

/*Function name: checkRange()
 *Function prototype:int checkRange(long number)
 *Description: checks wheter number is in valid range
 *Parameters: long number: the user inputted number
 *	      long minRange: the lowest inclusive allowed
 *	      long maxRange: the largest inclusive allowed
 *Return Value:1 or 0 depenidng on whether it is within the range
 *Register used: i0,i1,i2 for the arguments
 *		 l1,l2,l3 to store the arguments
 *
 */

checkRange:

	save	%sp,-96,%sp	!save caller's window

	mov	%i0,%l0		!move the value to l0
	mov	%i1,%l1		!move the minrange to l1
	mov	%i2,%l2		!move the maxrange to l2

	cmp	%l0,%l1		!compare to minrange
	bl	FALSE		!if it is less than
	nop

	cmp	%l0,%l2		!compare to maxrange
	bg	FALSE		!if it is greater than
	nop
	
	mov	1,%i0		!passed all checks so return 1
	ba	RETURN		!branch always and ret restored
	nop
	
FALSE:
	mov	0,%i0

RETURN:
	ret			!return from subroutine
	restore			!restore caller's window;in "ret" delay slot

