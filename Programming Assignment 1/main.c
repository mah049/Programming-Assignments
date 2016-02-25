/*
 *Filename:main.c
 *Author:Mark Huang
 *Date:1/27/2015
 *Userid:cs30xcl
 *Description: this program creates a display plus program
 *that error checks and takes in inputs given by the user
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/* Local headers use double quotes " " */
#include "pa1.h"
#include "pa1_strings.h"

int main(int argc, char *argv[]){
  
  /*check is there is a valid number of arguments*/
  if(argc != 5){
    (void)fprintf(stderr,USAGE_STR,argv[0],3,5001,32,126,32,126,32,126);
    exit(EXIT_FAILURE);
  }

  /*check if the arguments can be converted to long int*/
  long hasError=0;
  /*determines for special case if the integer is out of range*/
  long intError=0;
  /*arguments for the values entered by the user*/
  long int arg1,arg2,arg3,arg4;
  /*char pointer used for strtol*/
  char * endptr;
  
  /*tests for argument 1*/
  /*gets the long integer value*/
  arg1=strtol(argv[1],&endptr,10);
  
  /*if cannot be converted*/
    if(errno!=0){
      intError=1;
    }
    
    /*if it is not an integer*/
    if(*endptr!=NULL){
      (void)fprintf(stderr,INTEGER_ERR_STR,argv[1]);
      intError=1;
      hasError=1;
    }

    /*makes sure that it does not repeat tests*/
    if(intError==0){
      /*makes sure it is odd*/
      if(!isOdd(arg1)){
        (void)fprintf(stderr,SIZE_ODD_INTEGER_ERR_STR,arg1);
        hasError=1;
      }
      /*makes sure it is within the range*/
      if(checkRange(arg1,PLUS_SIZE_MIN,PLUS_SIZE_MAX)==0){
        (void)fprintf(stderr,SIZE_RANGE_ERR_STR,arg1,3,5001);
        hasError=1;
      }
    }
  
  /*tests for argument 2*/
  arg2=strtol(argv[2],&endptr,10);
    /*if it cannot be converted*/
    if(errno!=0){
      intError=1;
    }

    /*if it is not an integer*/
    if(*endptr!=NULL){
      (void)fprintf(stderr,INTEGER_ERR_STR,argv[2]);
      intError=1;
      hasError=1;
    }
    
    /*makes sure not to repeat test*/
    if(intError==0){
      /*makes sure it is within the range*/
      if(checkRange(arg2,PLUS_CHAR_MIN,PLUS_CHAR_MAX)==0){
        (void)fprintf(stderr,PLUS_CHAR_RANGE_ERR_STR,arg2,32,126);
        hasError=1;
      }
    }
  
  /*tests for argument 3*/
  arg3=strtol(argv[3],&endptr,10);
    /*makes sure it can be converted*/
    if(errno!=0){
      intError=1;
    }
    
    /*makes sure it is a valid int*/
    if(*endptr!=NULL){
      (void)fprintf(stderr,INTEGER_ERR_STR,argv[3]);
      intError=1;
      hasError=1;
    }

    /*makes sure not to repeat tests*/
    if(intError==0){
      /*makes sure it is within range*/
      if(checkRange(arg3,FILL_CHAR_MIN,FILL_CHAR_MAX)==0){
        (void)fprintf(stderr,FILL_CHAR_RANGE_ERR_STR,arg3,32,126);
        hasError=1;
      
      }
    }

  /*tests for argument 4*/
  arg4=strtol(argv[4],&endptr,10);
    /*makes sure it can be converted*/
    if(errno!=0){
      intError=1;
    }
    /*makes sure it is an integer*/
    if(*endptr!=NULL){
      (void)fprintf(stderr,INTEGER_ERR_STR,argv[4]);
      intError=1;
      hasError=1;
    }

    /*makes sure not to repeat tests*/
    if(intError==0){
      /*makes sure the range is within*/
      if(checkRange(arg4,BORDER_CHAR_MIN,BORDER_CHAR_MAX)==0){
        (void)fprintf(stderr,BORDER_CHAR_RANGE_ERR_STR,arg4,32,126);
        hasError=1;
      }
    }
    if(errno!=0){
      perror(NULL);
      (void)fprintf(stderr,USAGE_STR,"./pa1",3,5001,32,126,32,126,32,126);
      exit(EXIT_FAILURE);
    }
 
  /*checks for unique input*/
  if(intError==0){
    if(arg2==arg3){
      (void)fprintf(stderr,PLUS_CHAR_FILL_CHAR_ERR_STR,arg2,arg3);
      hasError=1;
    }


    if(arg2==arg4){
      (void)fprintf(stderr,PLUS_CHAR_BORDER_CHAR_ERR_STR,arg2,arg4);
      hasError=1;
    }

    if(arg3==arg4){
      (void)fprintf(stderr,FILL_CHAR_BORDER_CHAR_ERR_STR,arg3,arg4);
      hasError=1;
    }
  }

  /*if there is error in the inputs*/
  if(hasError==1){
    (void)fprintf(stderr,USAGE_STR,"./pa1",3,5001,32,126,32,126,32,126);
    exit(EXIT_FAILURE);
  }
  
  displayPlus(arg1,arg2,arg3,arg4);
  return 0;
}
