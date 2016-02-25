/*Filename: unitTest_parseStartTime.c
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: Tester for the function parseStartTime
 *tests a variety of possible outputs
 *Date: 2/8/2015
 */

#include <stdio.h>

#include "pa2.h"
#include "test.h"

/*
 * Tests for the parse time
 */

void testparseStartTime() {
  struct tm tm;

  /*makes sure it returns 0 when there are two colons*/
  /*cases when it passes*/
  TEST( parseStartTime( &tm, "::" ) == 0 );
  TEST( tm.tm_hour == 0 );
  TEST( tm.tm_min == 0 );
  TEST( tm.tm_sec == 0 );

  /*cases when an error message should return*/
  TEST( parseStartTime(&tm, ":::" ) == ERR_TIME_FORMAT );

  TEST( parseStartTime(&tm, "a:a:a" ) ==
    (ERR_HR_VALUE | ERR_MIN_VALUE | ERR_SEC_VALUE) );

}

int main( void ) {

  fprintf(stderr, "Running tests for testparseStartTime...\n");
  testparseStartTime();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}

