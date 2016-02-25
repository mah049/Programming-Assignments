/*
 *Filename: setBCDClock.s
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: sets the BCD clock
 *Date:1/20/2015
 */

	.global setBCDClock	!Declares the symbol to be globally visiblie
				!so we can call this fnunction from other 
				!modules
	.section ".text"	!The text segment begins here
	
/*
 *Function name: setBCDClock()
 *FUnction prototype: setBCDClock(const struct tm* tmpPtr, unsigned char clock[]);
 *Description: sets the BCDclock
 *Parameters:tmpPtr: struct to input the values of clock into
 	     clock: clock to be inputted
 *Return Value: None
 *Registers used:%i0,%i1 are used as the num and base
 *		%l1,%l0,%l2 are used to hold num base and counter
 *		%o0,%o0 arguments used for checkRange and .div
 */

!mask 
TENMASK = 10
!value of the shift
SHIFTVAL = 4

setBCDClock:

	save	%sp,-96,%sp		!allocates the memory

	call	tm_hourOffset		!call tm_hour offest
	nop

	mov	%o0,%l0			!move that value into local 0
	
	call	tm_minOffset		!gets the min offset
	nop

	mov	%o0,%l1			!moves that value into l1
	
	call	tm_secOffset		!gets the seconds offset
	nop

	mov	%o0,%l2			!moves that value into l2
	
	add	%i0,%l0,%l0		!adds the offset	
	add	%i0,%l1,%l1		!adds the offset
	add	%i0,%l2,%l2		!adds the offset

	ld	[%l0],%l0		!dereferences and l0
	ld	[%l1],%l1		!dereferences and l1
	ld	[%l2],%l2		!deferences and l2
	
	!hours
	mov	%l0,%o0			!move the hours to ouput o
	mov	TENMASK,%o1		!call the mask div
	call	.div
	nop

	mov	%o0,%o3			!tens into o3 

	mov	%l0,%o0			
	mov	TENMASK,%o1
	call	.rem
	nop
	
	sll	%o3,SHIFTVAL,%o3	!gets the ones and stores into o3
	or	%o3,%o0,%l0

	stb	%l0,[%i1]		!stores the bytes

	!minutes
	mov	%l1,%o0			!gets the 10's value of the minutes
	mov	TENMASK,%o1
	call	.div
	nop

	mov	%o0,%o3

	mov	%l1,%o0			!gets the 1's value of the minutes
	mov	TENMASK,%o1
	call	.rem
	nop

	sll	%o3,SHIFTVAL,%o3	!prepares it to be stored
	or	%o3,%o0,%l1

	stb	%l1,[%i1 +1]		!stores the minutes into the array

	!seconds
	mov	%l2,%o0			!gets he 10's values of the sceonds
	mov	TENMASK,%o1
	call	.div
	nop

	mov	%o0,%o3			!moves into o3
	
	mov	%l2,%o0			!gets the 1's value of the seconds
	mov	TENMASK,%o1
	call	.rem
	nop

	sll	%o3,SHIFTVAL,%o3	!prepares it to be stored
	or	%o3,%o0,%l2

	stb	%l2,[%i1 + 2]		!stores it into the clock array
	
	ret				!return and restore the registers
	restore
