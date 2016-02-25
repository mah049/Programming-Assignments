/*
 *Filename: anagramCompare.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: compares two anagrams and returns < > = 0
 *Date: 2/24/2015
 *
 */
	.global anagramCompare		!declares the symbol to be 
					!globally visible

	.section ".text"		!text segment begins here

/*
 *FunctionName : anagramCompare()
 *Function prototype: int anagramCompare(const void *p1, const void *p2);
 *Description: compares two anagrams and returns cvalues
 *based on the return value of strcmp
 *Parameters: p1: the first pointer to compare
 *            p2: the second pointer to compare
 *Return value: int based on what happeneds < > = 0
 *Registers used: %l0,%l1,%o0,%o1,%i0 for a variety of variables
 *and arguemnts
 *
 */

anagramCompare:
	
	save	%sp,-96,%sp		!saves space 
	
	set	WORD_OFFSET,%l0		!gets the wordoffset 
	ld	[%l0],%l0		!dereferences ands tores value

	set	SORTED_OFFSET,%l1	!gets the sortedoffset
	ld	[%l1],%l1		!dereferences and stores the value

	add	%i0,%l1,%o0		!add the pointer offsets
	add	%i1,%l1,%o1		!add the pointer offsets

	call	strcmp			!compare the stirngs
	nop

	cmp	%o0,0			!compare to see if it is 0
	be	EQUAL
	nop

	mov	%o0,%i0			!mov that value to return 
	ba	END
	nop

EQUAL:
	add	%i0,%l0,%o0		!if it's equal compare the word
	add	%i1,%l0,%o1		!compare the word

	call	strcmp
	nop

	mov	%o0,%i0			!gets the output

END:
	ret
	restore				!restores the register
	

