/*
 *Filename: pa2.h
 *Author:Mark Huang
 *Userid: cs30xcl
 *Description:Contains all the constants and function headers
 *Date:2/8/2015
 *
 */

#ifndef PA2_H
#define PA2_H

#include <time.h>  /* for struct timeval and struct tm (below) */

#define MAX_ARGS 3

#define MIN_HR 0
#define MAX_HR 23
#define MIN_MIN 0
#define MAX_MIN 59
#define MIN_SEC 0
#define MAX_SEC 59

#define MAX_ONES_SEC 9
#define MAX_TENS_SEC 5

#define MAX_ONES_MIN 9
#define MAX_TENS_MIN 5

#define MAX_ONES_HR 9
#define MAX_TENS_HR 2

#define HR_INDEX 0
#define MIN_INDEX 1
#define SEC_INDEX 2

#define BASE 10

#define MIN_TICKS 0
#define MAX_TICKS 61
#define DEF_TICKS 10

#define REQ_SEPARATORS 2

/*
 * Create any bit masks you need in here
 */
#define UPPERBITMASK 0xF0
#define LOWERBITMASK 0x0F

/*
 * parseStartTime errors
 */

/* Check for the following errors IN THIS ORDER! */
#define ERR_TIME_FORMAT  0x1 /* invalid start time string */
#define ERR_HR_VALUE     0x2 /* hour value invalid */
#define ERR_HR_RANGE     0x4 /* hour value out of range */
#define ERR_MIN_VALUE    0x8 /* min value invalid */
#define ERR_MIN_RANGE   0x10 /* min value out of range */
#define ERR_SEC_VALUE   0x20 /* sec value invalid */
#define ERR_SEC_RANGE   0x40 /* sec value out of range */

/* C routines */
void updateBCDClock( unsigned char clock[] );
void displayBCDClock( const unsigned char clock[] );
int pa2gettimeofday( struct timeval *tp, void *p );
void usage( const char *programName );
unsigned long parseStartTime( struct tm *tmPtr, const char *time );

/*
 * C routines only used in Assembly routines:
 *
 * size_t tm_hourOffset();
 * size_t tm_minOffset();
 * size_t tm_secOffset();
 */

/* Assembly routines */
int checkRange( long value, long minRange, long maxRange );
void setBCDClock( const struct tm *tmPtr, unsigned char clock[] );
unsigned char updateBCDValue( unsigned char BCDbits,
                              const unsigned int maxValue );
void printChar( char ch );

#endif /* PA2_H */

