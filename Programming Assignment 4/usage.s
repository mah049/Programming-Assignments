/*
 *Filename: usage.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: prints the usage message
 *Date:2/24/2015
 */

	.global usage		!Declares the symbol to be globally visiblie
				!so we can call this fnunction from other 
				!modules
	.section ".text"	!The text segment begins here
	
/*
 *Function name: usage()
 *FUnction prototype: usage(const char* filename);
 *Description: prints out the usage message
 *Parameters:filename: name of the file 
 *Return Value: None
 *Registers used:%o2 holds the argument of the filename
 *               %o1 holds the value of the message
 */


 usage:

 	save	%sp,-96,%sp	!allocates memory	
	
	mov	%i0,%o2		!moves the filename
	set	STR_USAGE,%o1	!gets the message
	ld	[%o1],%o1	!dereferences it
	
	set	stdError,%o0	!gets the place to print
	ld	[%o0],%o0

	call	fprintf		!call fprintf
	nop

	ret 			!restore the register
	restore
