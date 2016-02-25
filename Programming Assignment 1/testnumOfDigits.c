/*Filename: testnumOfDigits.c
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: Tester for the function numOfDigits
 *tests a variety of possible outputs
 *Date: 1/20/2015
 */

#include "pa1.h"
#include "test.h"
#include <stdio.h>

void testnumOfDigits(){
  
  printf( "Testing testnumOfDigits()\n" );
  
  /*if the num is 0*/
  TEST( numOfDigits(0,10) == 1 );

  /*Random tests for the */
  TEST( numOfDigits(1000,10)==4);
  TEST( numOfDigits(10,10)==2);
  TEST( numOfDigits(100,10)==3);

  /*Base 8*/
  TEST( numOfDigits(580,8) == 4);

  /*Base 16*/
  TEST( numOfDigits(580,16) == 3);

  /*if the base is out of bounds*/
  TEST( numOfDigits(100,1) == -1);
  TEST( numOfDigits(100,100) == -1);
  

}
int main(){

  testnumOfDigits();
  return 0;
}

