/*
 *Filename:parseStartTime.c
 *Author: Mark Huang
 *Date: 2/8/2015
 *Userid: cs30xcl
 *Description:modifies the tm struct to contain the sec, hours,min
 *assuming that the char * in time given is valid input
 *
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "pa2.h"

/*
 *Function name: parseStartTime
 *FUnction prototype: unsigned long parseStartTime(struct tm *tmpPtr, const char*time);
 *Description: parses the time inputted and stores it into the struct tm
 *Parameters: 
 *           arg1: struct to store hours min and sec
 *           arg2: time that holds the user inputted values
 *Return Value: if error then returns the value of that error
 */

unsigned long parseStartTime( struct tm *tmpPtr, const char*time){
  
  /*size of the local array declared*/ 
  char localArray[BUFSIZ];
  /*makes sure there is null */
  (void)memset(localArray,NULL,sizeof(localArray));
  /*char pointer to loop through the char*time*/
  char * pointer;
  /*end of the char* inputted*/
  char * endptr;
  /*front of the char * inputted*/
  char * frontptr;
  /*values of hour min and sec*/
  long hour,min,sec;
  /*error checking*/
  int value = 0;
  /*counters*/
  int counter = 0;
  /*errno error checking*/
  errno = 0;
  
  /*copies the char * to local array*/
  (void)strncpy(localArray,time,strlen(time));
  /*looks for the :*/
  pointer = strchr(time,':');
  /*looks for the next :*/
  while(pointer){
    pointer = strchr(++pointer,':');  /*increments the pointer first and then strchr first in constrast to incrementing it afterwards*/
    counter++;
  }
  /*makes sure there are the right number of :*/
  if(counter != REQ_SEPARATORS){
    return ERR_TIME_FORMAT;
  }
  /*looks for the :*/
  pointer = strchr(localArray,':');
  /*makes that pointer null*/
  *pointer = NULL;
  /*the hour is up the that first :*/
  hour = strtol(localArray, &endptr,BASE);
  /*if there was an issue parsing*/
  if(*endptr!=NULL||errno!=0){
    value = value | ERR_HR_VALUE;
    errno=0;
  }
  /*if it is not within the valid range*/
  if(!checkRange(hour,MIN_HR,MAX_HR)){
    value = value | ERR_HR_RANGE;
  }
  
  /*ones after the pointer*/
  frontptr = ++pointer;
  /*looks for next :*/
  pointer = strchr(frontptr,':');
  /*sets it to null*/
  *pointer = NULL;
  /*parses the minutes*/
  min = strtol(frontptr, &endptr, BASE);
  /*if there was an issue parsing*/
  if(*endptr!=NULL||errno!=0){
    value = value | ERR_MIN_VALUE;
    errno = 0;
  }
  /*if it is not within the given range*/
  if(!checkRange(min,MIN_MIN,MAX_MIN)){
    value = value | ERR_MIN_RANGE;
  }

  /*parses the seconds*/
  sec = strtol(++pointer,&endptr,BASE);
  /*if there was an issue parsing*/
  if(*endptr!=NULL||errno!=0){
    value= value | ERR_SEC_VALUE;
    errno = 0;
  }
  /*if it is not within the range*/
  if(!checkRange(sec,MIN_SEC,MAX_SEC)){
    value = value | ERR_SEC_RANGE;
  }
  
  /*sets the tm struct*/
  tmpPtr->tm_hour=hour;
  tmpPtr->tm_min=min;
  tmpPtr->tm_sec=sec;
  
  return value;

}
