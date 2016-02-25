/*Filename: unitTest_setBCDClock.c
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: Tester for the function setBCDClock
 *tests a variety of possible outputs
 *Date: 2/8/2015
 */

#include <stdio.h>
#include <sys/time.h>

#include "pa2.h"
#include "test.h"

/*tests for setBCDClock*/

void testsetBCDClock() {

  struct tm time;
  unsigned char clock[3];

  /* Test 1 */
  time.tm_hour = 12;
  time.tm_min = 34;
  time.tm_sec = 56;

  setBCDClock(&time, clock);

  /*makes sure the correct values were set*/
  TEST( (clock[0] == 0x12) && (clock[1] == 0x34) && (clock[2] == 0x56) );

}

int main( void ) {

  fprintf(stderr, "Running tests for setBCDClock...\n");
  testsetBCDClock();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}

