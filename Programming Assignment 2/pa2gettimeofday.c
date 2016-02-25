/*
 *Filename: pa2gettimeofday.c
 *Author: Mark Huang
 *Date: 2/9/2015
 *Userid: cs30xcl
 *Description: gets the current time of day
 *
 */

#include <stdio.h>
#include <sys/time.h>

/*
 *Function name: pa2gettimeofday
 *FUnction prototype: int pa2gettimeofday(struct timeval *tp, void *p);
 *Description: gets the current time of day
 *Parameters: 
 *           arg1: struct timeval *tp
 *           stores the values into the timeval struct
 *           arg2: for error checking
 *Return Value: None
 */

int pa2gettimeofday( struct timeval *tp, void *p ) {
  return gettimeofday( tp, p );
}

