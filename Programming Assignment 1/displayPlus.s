/*
 *Filename: DisplayPlus.s
 *Author:Mark Huang
 *Userid: cs30xcl
 *Description: produces a plus visual in the terminal
 *Date:1/27/2015
 *
 */

 	.global displayPlus	!Declares the symbol to be globally visible

 	.section ".text"
	
	NL = '\n'		!new line character
	DEFAULT_BASE=10		!default base is 10
	DIVISOR=2		!dvisior to check odd
	ZERO=0			!comparion 

/*
 *Function name: displayPlus()
 *Function prototype: displayPlus(long size, long plusChar, long fillerChar
 long borderChar)
 *Description: prints out avisual of characters that displays a plus
 *Parameters: long size: the size of the visual
 	      long plusChar: the asciivalue of char
	      long fillerChar: ascii value of char
	      long borderChar: ascii value of char
 *Return Value:none
 *
 *
 */

displayPlus:
	save	%sp,-96,%sp

	!get the border_thickness which is numOfDigits(size,DEFAULT_BASE)
	mov	%i0,%o0
	mov	DEFAULT_BASE,%o1
	call	numOfDigits
	nop

	mov	%o0,%l0		!local register for border thickness
	
	mov	DIVISOR,%o0	!calls the multiplication function
	mov	%l0,%o1
	call	.mul
	nop

	mov	%o0,%l1
	add	%l1,%i0,%l1	!local register 1 is now total_width

	mov	%i0,%o0
	mov	DIVISOR,%o1
	call	.div
	nop

	mov	%o0,%l2		!local register 2 is now horizontal pplus pos
	mov	%l2,%l3		!local register 3 is now vertical plus pos

	!print the top border
	
	mov	0,%l4		!mov the comparison
	cmp	%l4,%l0
	bge	endouter
	nop

outer:
	mov	0,%l5
	cmp	%l5,%l1
	bge	endinner
	nop

inner:
	mov	%i3,%o0		!move the top border character in
	call	printChar
	nop

	inc	%l5		!increments
	cmp	%l5,%l1
	bl	inner		!if less than loop again
	nop

endinner:

	mov	NL,%o0		!call new line
	call	printChar
	nop

	inc	%l4
	cmp	%l4,%l0
	bl	outer
	nop

endouter:

	
	!print the top half of the plus
	clr	%l4
	cmp	%l4,%l3		!compare to vertical plus pos
	bge	end
	nop

outer1:

	clr	%l5		!resets the inner loops
	clr	%o2
	clr	%o3
	
inner1:
	cmp	%l5,%l0		!compare border thickness
	bge	inner2
	nop

	mov	%i3,%o0		!print the fill char
	call 	printChar
	nop

	inc	%l5
	cmp	%l5,%l0
	bl	inner1		!loop again
	nop


inner2:
	cmp	%o2,%i0		!compare to size
	bge	inner3
	nop

	cmp	%o2,%l2		!if it is equal to
	be	equal
	nop

	cmp	%o2,%l2		!if it is not equal
	bne	else
	nop


inner3:
	cmp	%o3,%l0		!compare 
	bge	endinner1
	nop

	mov	%i3,%o0		!print filler char
	call	printChar
	nop

	inc	%o3		!increment the loop
	cmp	%o3,%l0
	bl	inner3		!if less than loop again
	nop
	

endinner1:
	mov	NL,%o0		!add in a new line character
	call	printChar
	nop

	inc	%l4
	cmp	%l4,%l3
	bl	outer1		!continue looping
	nop

	ba 	end		!branch always if its greater than that ends
	nop

equal:
	inc	%o2		!increments	
	mov	%i1,%o0		!move the characters into place
	call	printChar
	nop

	ba	inner2		!loops back
	nop
else:
	inc	%o2		!increments
	mov	%i2,%o0		!move the characters into place
	call 	printChar
	nop
	ba	inner2		!loops back
	nop
end:

	!print the horizontal plus of the plus

	clr	%l4
	cmp	%l4,%l0		!compare to the border thickness
	bge	endloop4
	nop
inner4:
	
	mov	%i3,%o0		!print the border Character
	call	printChar
	nop

	inc	%l4
	cmp	%l4,%l0		!llops the border character
	bl	inner4
	nop

endloop4:

	!plus characters

	clr	%l4
	cmp	%l4,%i0		!compare to size
	bge	endLoop5
	nop

inner5:
	mov	%i1,%o0		!prints the right border
	call	printChar
	nop

	inc	%l4
	cmp	%l4,%i0
	bl	inner5		!loops the right border
	nop

endLoop5:

	!print right border

	clr	%l4
	cmp	%l4,%l0
	bge	endLoop6
	nop

inner6:
	mov	%i3,%o0		!prints out the specified character
	call	printChar
	nop

	inc	%l4
	cmp	%l4,%l0		!loops through the inner
	bl	inner6
	nop

endLoop6:

	mov	NL,%o0		!prints out the new line character
	call	printChar
	nop
	

	clr	%l4
	cmp	%l4,%l3		!compare to vertical plus pos
	bge	end
	nop

bouter1:
!print the bottom half of the plus
	clr	%l5
	clr	%o2
	clr	%o3
binner1:
	cmp	%l5,%l0		!compare border thickness
	bge	inner2
	nop

	mov	%i3,%o0		!move the character into the output
	call 	printChar
	nop

	inc	%l5		
	cmp	%l5,%l0
	bl	binner1		!continue looping
	nop


binner2:
	cmp	%o2,%i0		!compare to size
	bge	binner3
	nop

	cmp	%o2,%l2
	be	bequal		! branch if equal to and increment
	nop

	cmp	%o2,%l2
	bne	belse		!branch if no equal to and inrement
	nop


binner3:
	cmp	%o3,%l0		!compare the outer loop 
	bge	bendinner1
	nop

	mov	%i3,%o0		!move the character to the output
	call	printChar
	nop

	inc	%o3
	cmp	%o3,%l0
	bl	binner3
	nop
	

bendinner1:
	mov	NL,%o0		!add in a new line character
	call	printChar
	nop

	inc	%l4
	cmp	%l4,%l3
	bl	bouter1		!continue loping
	nop

	ba 	bend		!end the loop
	nop

bequal:
	inc	%o2		!increments
	mov	%i1,%o0
	call	printChar
	nop

	ba	binner2		!resets back to the loop
	nop
belse:
	inc	%o2
	mov	%i2,%o0		!prints and increments the loop
	call 	printChar
	nop
	ba	binner2		!resets back to the loop
	nop
bend:

	!print the top border
	
	mov	0,%l4		!comparison for the outer loop
	cmp	%l4,%l0
	bge	endouter10
	nop

outer10:
	mov	0,%l5		
	cmp	%l5,%l1		!compares the values of total width
	bge	endinner10
	nop

inner10:
	mov	%i3,%o0		!moves the borderChar into o0
	call	printChar
	nop

	inc	%l5		!increments to keep the loop going
	cmp	%l5,%l1
	bl	inner10
	nop

endinner10:

	mov	NL,%o0		!end of 1 inner loop so call new line
	call	printChar
	nop

	inc	%l4
	cmp	%l4,%l0		!continue looping by incrementing
	bl	outer10
	nop

endouter10:

	ret			!return and restore the window
	restore








	


	




