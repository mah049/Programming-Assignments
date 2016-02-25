/*
 *Filename:displayBCDClock.c
 *Author: Mark Huang
 *Date: 2/8/2015
 *Userid: cs30xcl
 *Description: This function takes a unsigned char clock
 *and converts the clock into a binary visual representation
 *of the clock
 *
 */

#include <stdio.h>

#include "pa2.h"
#include "pa2_strings.h"

/*FOURBITS used to loop through the NIBBLE*/ 
#define FOURBITS 4 
/*THREEBITS used to loob through a hours mins and seconds*/
#define THREEBITS 3

/*
 *Function name: displayBCDClock
 *FUnction prototype: void displayBCDClock(const unsigned char clock[]);
 *Description: displays the BCD clock using printChar and characters
 *Parameters: 
 *           arg1: const unsigned char clock[]
 *           does not modify the clock and has hours min and sec
 *Return Value: None
 */

void displayBCDClock( const unsigned char clock[]){
  /*mask used to determine value of bit*/
  long TENSMASK = 0x80;
  /*mask used to determine value of bit*/
  long ONESMASK = 0x08;
  /*loop through the for loop*/
  int counter;
  int index;
  
  /*loops through ever nibble in minutes hours and seconds*/
  for(counter=0;counter<FOURBITS;counter++){
    for(index=0; index<THREEBITS; index++){
      /*if there is a 1 bit there*/
      if(clock[index]&TENSMASK){
        printChar('0');
      }
      /*else print 0*/
      else{
        printChar('.');
      }
      /*if there is a one bit there*/
      if(clock[index]&ONESMASK){
        printChar('0');
        printChar(' ');
      }
      else{
        printChar('.');
        printChar(' ');
      }
    }
    /*increment the mask to move to next bit*/
    TENSMASK=TENSMASK>>1;
    ONESMASK=ONESMASK>>1;
    /*new line character*/
    printChar('\n'); 
  }
  /*when finished display the BCD Time*/
  for(counter=0; counter<THREEBITS;counter++){ 
    (void)printf(STR_BCD_TIME,clock[counter]);
  }

  /*new line character*/
  printChar('\n');
}
