/*
 *Filename: main.c
 *Author:Mark Huang
 *Userid: cs30xcl
 *Description:Checks for errors in arguments provided to run the BCDclock
 *If all the error checking is passed it prints out a visual represent
 *ation of the BCD clock.
 *Date:2/8/2015
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "pa2.h"
#include "pa2_strings.h"

/*size of the clock array*/
#define CLOCKSIZE 3

int main(int argc, char *argv[]){
  
  long int arg1;         /*arg1 is used for the ticks*/ 
  char * endptr;         /*errorchecking*/
  struct timeval tv;     /*holds the value of current time*/
  struct tm time;        /*struct that holds the time*/
  struct tm *timePtr;    /*utilized to get the current time*/
  int errorChecking=0;   /*determines if there is an error*/
  int parseReturn;       /*what parsing returns*/
  int numOfTicks=0;      /*num of ticks specified*/
  int counter=0;         /*counter for ticks*/
  unsigned char clock[CLOCKSIZE];     /*size of the clock*/
  
  /*error check for when there is too many args*/
  if(argc > MAX_ARGS){
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }
  
  /*error check for when the argument is more than or equal to two*/
  if(argc>=2){
    /*if the user inputs --help pring the usage info*/
    if(strcmp(argv[1],STR_HELP)==0){
      usage(argv[0]);
      exit(EXIT_SUCCESS);
    }
    else{
      /*get the number of ticks from argv[1] and set it to numofTicks*/
      arg1 = strtol(argv[1],&endptr,BASE);
      numOfTicks=arg1;
      /*if tick cannot be converted*/
      if(errno!=0){
        (void)fprintf(stderr,STR_ERR_TICK_VALUE);
        errorChecking=1;
      
      }
      /*if tick is not an integer*/
      else if(*endptr!=NULL){
        (void)fprintf(stderr,STR_ERR_TICK_VALUE);
        errorChecking=1;
       
      }
      /*if it is not within the specified range*/
      if(checkRange(arg1,MIN_TICKS,MAX_TICKS)==0){
        (void)fprintf(stderr,STR_ERR_TICK_RANGE,MIN_TICKS,MAX_TICKS);
        errorChecking=1;
      }
    }
  }

  /*if there is the right amount of arguments*/
  if(argc == 3){
    /*parses the argument*/
    parseReturn = parseStartTime(&time,argv[2]);
    /*makes sure the time format is right*/
    if(parseReturn & ERR_TIME_FORMAT){
      (void)fprintf(stderr,STR_ERR_TIME_FORMAT);
      errorChecking=1;
    }
    /*makes sure the hr value valid*/
    if(parseReturn & ERR_HR_VALUE){
      (void)fprintf(stderr,STR_ERR_HR_VALUE);
      errorChecking=1;
    }
    /*makes sure the hr value is in the valid range*/
    if(parseReturn & ERR_HR_RANGE){
      (void)fprintf(stderr,STR_ERR_HR_RANGE,MIN_HR,MAX_HR);
      errorChecking=1;
    }
    /*makes sure the min is valid*/
    if(parseReturn & ERR_MIN_VALUE){
      (void)fprintf(stderr,STR_ERR_MIN_VALUE);
      errorChecking=1;
    }
    /*makes sure the min value is valid*/
    if(parseReturn & ERR_MIN_RANGE){
      (void)fprintf(stderr,STR_ERR_MIN_RANGE,MIN_MIN,MAX_MIN);
      errorChecking=1;
    }
    /*makes sure the sec value is valid*/
    if(parseReturn & ERR_SEC_VALUE){
      (void)fprintf(stderr,STR_ERR_SEC_VALUE);
      errorChecking=1;
    }
    /*makes sure the second range value is valid*/
    if(parseReturn & ERR_SEC_RANGE){
      (void)fprintf(stderr,STR_ERR_SEC_RANGE,MIN_SEC,MAX_SEC);
      errorChecking=1;
    }
  }
  
  /*if errors along the way print a usage message*/
  if(errorChecking){
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  /*if there is only one argument get the current time and print it*/
  if(argc == 1){
    (void)pa2gettimeofday(&tv,NULL);
    timePtr=localtime(&tv.tv_sec);
    (void)printf(asctime(timePtr));
    (void)printf("\n");
    numOfTicks=DEF_TICKS;
  }
  
  /*if only the tick get that time of day and print it*/
  if(argc == 2){
    (void)pa2gettimeofday(&tv,NULL);
    timePtr=localtime(&tv.tv_sec);
    (void)printf(asctime(timePtr));
    (void)printf("\n");

  }
  
  /*increment the number of ticks*/
  numOfTicks++;
  /*if less than two arguments it is current time*/
  if(argc <= 2){
    setBCDClock(timePtr,clock);
  }
  /*user inputted time*/
  else{
    setBCDClock(&time,clock);
  }
  
  /*display the clock and update it given the number of ticks*/
  for(counter=0;counter<numOfTicks;counter++){
    displayBCDClock(clock);
    (void)printf("\n");
    updateBCDClock(clock);
  }
  return 0;
}
