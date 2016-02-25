/*Filename: testisOdd.c
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description
 *Date:
 *Sources of Help:
 */

#include "pa1.h"
#include "test.h"
#include <stdio.h>

void testisOdd(){
  
  printf( "Testing testisOdd()\n" );
  
  TEST( isOdd(0) == 0 );
  TEST( isOdd(3) != 0 );
  TEST( isOdd(4) == 0 );
  /*negative input*/
  TEST( isOdd(-2) == 0 );
  TEST( isOdd(-3) != 0 );
  
  printf( "Finished running tests on isOdd()\n" );

}
int main(){

  testisOdd();
  return 0;
}

