/*
 *Filename: numOfDigits.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description:
 *Date:1/20/2015
 */

	.global numOfDigits	!Declares the symbol to be globally visiblie
				!so we can call this fnunction from other 
				!modules
	.section ".text"	!The text segment begins here
	
	MIN_BASE = 2
	MAX_BASE = 36

/*
 *Function name: numOfDigits()
 *FUnction prototype: int numOfDigits(long number, int base);
 *Description: counts the num of digits given the specific base
 *Parameters:long number: the user inputted number
 	     int base: the base used b the user
 *Return Value: THe number of digits
 *Registers used:%i0,%i1 are used as the num and base
 *		%l1,%l0,%l2 are used to hold num base and counter
 *		%o0,%o0 arguments used for checkRange and .div
 */

numOfDigits:
	
	save	%sp,-96,%sp	!save caller's window
	
	cmp	%i0,0		!compare the num to 0
	be	SPECIAL		!if it is 0 return 1

	mov	%i0,%l0		!set num to l0
	mov	%i1,%l1		!set the base to l1
	mov 	0,%l2		!set the counter to l2


	mov	%i1,%o0		!move the base to o0
	mov	MIN_BASE,%o1	!move the minbase to o1
	mov	MAX_BASE,%o2	!move the maxbase to o2

	call	checkRange	!call check range
	nop

	cmp	%o0,0		!for check range 
	be	CANNOT		!if equal to 0 branch
	nop


loop:
	
	mov	%l0,%o0		!move the num to output 0
	mov	%l1,%o1		!move the base to output 1
	call	.div		!call div
	nop

	mov	%o0,%l0		!move the division to l0

	inc	%l2		!increment the counter

	cmp	%l0,0		!l0 holds the number	
	bne	loop		!not equal to 0 branch
	nop
	
	cmp	%l0,0		!if num equals 0
	be	end_loop	!if equal end_loop
	nop

CANNOT:
	mov	-1,%i0		!make the output -1
	ba	EXIT		!brnach always exit
	nop

end_loop:
	mov	%l2,%i0		!move the output 
	ba	EXIT		!ba exit
	nop

SPECIAL:
	mov	1,%i0		!move the output
	ba	EXIT		!branch 
	nop

EXIT:
	ret			!return from subroutine
	restore			!restore caller's window;in "ret" delay slot

