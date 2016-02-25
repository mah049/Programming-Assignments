/*
 *Filename:updateBCDClock.c
 *Author: Mark Huang
 *Date: 2/8/2015
 *Userid: cs30xcl
 *Description: This function increments the clock taking into
 *account when it reaches 59 seconds 59 minutes and 23 hours
 *
 */

/*
 *Call updateBCDValue which takes in 4 BCD bits passed in the first 
 */
#include <stdio.h>
#include "pa2.h" 

/*shift increment*/
#define SHIFTINCREMENT 4
/*corner case checking*/
#define HEX_FOUR 0x4

/*
 *Function name: updateBCDClock
 *FUnction prototype: void updateBCDClock(unsigned char clock[]);
 *Description: displays the BCD clock using printChar and characters
 *Parameters: 
 *           arg1:unsigned char clock[]
 *           modify the clock and has hours min and sec
 *Return Value: None
 */

void updateBCDClock( unsigned char clock[] ){
  
  /*lower bits of the char*/
  unsigned char lowerbits;
  /*upper bits of the char*/
  unsigned char upperbits;
   
   /*seconds*/
   /*checks to see if you can increment it by 1*/
   lowerbits=clock[SEC_INDEX]&LOWERBITMASK;
   lowerbits=updateBCDValue(lowerbits,MAX_ONES_SEC);
   /*if you can increment it by 1*/
   if(lowerbits){
     clock[SEC_INDEX]+=0x1;
     return;
   }
   /*else you clear the space*/
   else{
     clock[SEC_INDEX]&=UPPERBITMASK;
   }

   /*checks to see if you can increment by 1*/
   upperbits=(clock[SEC_INDEX]&UPPERBITMASK)>>SHIFTINCREMENT;
   upperbits=updateBCDValue(upperbits,MAX_TENS_SEC);
   /*if you can increment it by 1*/
   if(upperbits){
     clock[SEC_INDEX]+=0x10;
     return;
   }
   /*else you clear the space*/
   else{
     clock[SEC_INDEX]&=LOWERBITMASK;
   }

  /*minutes*/
  /*checks to see if you can increment it by 1*/
   lowerbits=clock[MIN_INDEX]&LOWERBITMASK;
   lowerbits=updateBCDValue(lowerbits,MAX_ONES_MIN);
   /*if you can increment it by 1*/
   if(lowerbits){
     clock[MIN_INDEX]+=0x1;
     return;
   }
   /*else you clear it making it 0*/
   else{
     clock[MIN_INDEX]&=UPPERBITMASK;
   }
   
   /*checks to see if you can increment it by 1*/
   upperbits=(clock[MIN_INDEX]&UPPERBITMASK)>>SHIFTINCREMENT;
   upperbits=updateBCDValue(upperbits,MAX_TENS_MIN);
   /*if you can increment it by 1*/
   if(upperbits){
     clock[MIN_INDEX]+=0x10;
     return;
   }
   /*else you clear it making it 0*/
   else{
     clock[MIN_INDEX]&=LOWERBITMASK;
   }

  /*hour loop*/
  /*checks to see if you can increment it by 1*/
  lowerbits=clock[HR_INDEX]&LOWERBITMASK;
  lowerbits=updateBCDValue(lowerbits,MAX_ONES_HR);
  /*if you can increment it by 1*/
  if(lowerbits==HEX_FOUR){
    upperbits=(clock[HR_INDEX]&UPPERBITMASK)>>SHIFTINCREMENT;
    upperbits=updateBCDValue(upperbits,MAX_TENS_HR);
    /*corner case for 23:59:59*/
    if(upperbits==0){
      clock[HR_INDEX]=0x0;
      return;
    }
  }
 /*increment it by 1*/
  if(lowerbits){
    clock[HR_INDEX]+=0x1;
    return;
  }
  else{
    clock[HR_INDEX]&=UPPERBITMASK;
  }

  /*checks to see if you can increment it by 1*/
  upperbits=(clock[HR_INDEX]&UPPERBITMASK)>>SHIFTINCREMENT;
  upperbits=updateBCDValue(upperbits,MAX_TENS_HR);
  /*if you can increment it by 1*/
  if(upperbits){
    clock[HR_INDEX]+=0x10;
    return;
  }
  /*else you clear the space*/
  else{
    clock[HR_INDEX]&=LOWERBITMASK;
  }

}
