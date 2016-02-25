/*Filename updateBCDValue.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description:checks to see if you can update the bcd value if
 *not return 0
 *Date: 1/20/2015
 *
 */
	
	.global updateBCDValue

	.section ".text"

/*
 *Function name:updateBCDValue()
 *Function prototype: updateBCDValue( value,max)
 *Description:checks to see if you can update the value given a max
 *Registers used: l0 and l1 to store the values and 
 *the points of comparison
 */



updateBCDValue:

	save	%sp,-96,%sp		!allocates space
	
	mov	%i0,%l0			!moves the values into local
	mov	%i1,%l1			!moves the values into local

	inc	%l0			!increments it
	
	cmp	%l0,%l1			!compares if greater than
	bg	ZERO			!branch to zero
	nop
	
	mov	%l0,%i0			!else simply return the value
	ba	END
	nop

ZERO:
	mov	0,%i0			!mov 0 into the output
END:
	ret				!return and restore register
	restore
