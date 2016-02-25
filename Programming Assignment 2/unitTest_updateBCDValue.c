/*Filename: updateBCDValue.c
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: Tester for the function parseStartTime
 *tests a variety of possible outputs
 *Date: 2/8/2015
 */

#include <stdio.h>

#include "pa2.h"
#include "test.h"

void testupdateBCDValue() {
 
  /*tests to makes sure it increments properly*/
  TEST( updateBCDValue(1, 10) == 2 );
  TEST( updateBCDValue(2,10) == 2);

  /*tests when it fails*/
  TEST( updateBCDValue(2,2)== 0);
}

int main( void ) {

  fprintf(stderr, "Running tests for updateBCDValue...\n");
  testupdateBCDValue();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}

