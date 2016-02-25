/*
 *Filename: sortedMemberCompare.s
 *Author: Mark Huang
 *userid: cs30xcl
 *Description:
 *Date: 2/24/2015
 *
 */

	.global	sortedMemberCompare	!declares the symbol to
					!to be globally visible
	.section ".text"		!text segment begins here

/*Function name: sortedMemberCompare()
 *Function prototype: sortedMemberCompare(const void*p1,const void * p2);
 *Description: compares the sorted members of the structs
 *Parameters: p1:pointer to the string
 *            p2:pointer to sthe string
 *Regisers used: %o0,%o1 for the two pointers
 *		 %l0 for the offset
 */

sortedMemberCompare:

	save	%sp,-96,%sp		!allocates the memory

	set	SORTED_OFFSET,%l0	!gets the offset
	ld	[%l0],%l0

	add	%i0,%l0,%o0		!adds it to the pointer
	add	%i1,%l0,%o1		!adds it to the pointer

	call	strcmp			!compares the sorted
	nop

	mov	%o0,%i0			!gets the ouput

	ret				!restore the register
	restore

