/*Filename:pa1.h
 *Author:Mark Huang
 *Date: 1/27/2015
 *Userid: cs30xcl
 *description: pa1 file
 */

#ifndef PA1_H
#define PA1_H

/*
 * User input
 */
#define DEFAULT_BASE 10 /* Exepected base for the user argument input */

#define EXPECTED_ARGS 4 /* Arg1: Height of the plus         */
                        /* Arg2: ASCII character for plus   */
                        /* Arg3: ASCII character for fill   */
                        /* Arg4: ASCII character for border */

/*
 * Plus display settings
 */
#define PLUS_SIZE_MIN      3 /* Must be odd for proper vertical center */
#define PLUS_SIZE_MAX   5001
#define PLUS_CHAR_MIN     32 /* Printable ASCII character range */
#define PLUS_CHAR_MAX    126
#define FILL_CHAR_MIN     32
#define FILL_CHAR_MAX    126
#define BORDER_CHAR_MIN   32
#define BORDER_CHAR_MAX  126

/* Local function prototypes for PA1 (written in Assembly or C) */
int  checkRange(long value, long minRange, long maxRange);
void displayPlus(long size, long plusChar, long fillerChar, long borderChar);
int  isOdd(long value);

/*
 * int  numOfDigits(long num, int base);
 * void printChar(char ch);
 *
 * Only called from an Assembly routine. Not needed in any C routine.
 * Would get a lint message about function declared but not used.
 */

#endif /* PA1_H */
