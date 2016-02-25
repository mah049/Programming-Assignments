/*
 *Filename:usage.c
 *Author: Mark Huang
 *Date: 2/8/2015
 *Userid: cs30xcl
 *Description:This function prints out the usage message
 *
 */

#include <stdio.h>
#include <errno.h>

#include "pa2.h"
#include "pa2_strings.h"

/*
 *Function name: usage()
 *FUnction prototype: usage(const char *programName);
 *Description: prints out the usage info given the program name
 *as one of the values
 *Return Value: None
 */


void usage( const char *programName){

    (void)fprintf(stderr,STR_USAGE,programName,MIN_TICKS,MAX_TICKS,MIN_HR,
    MAX_HR,MIN_MIN,MAX_MIN,MIN_SEC,MAX_SEC);
}
