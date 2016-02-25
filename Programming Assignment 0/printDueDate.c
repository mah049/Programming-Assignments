/*
 *Filename: printDueDate.c
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: Example C routine to print out the due date info
 *(month day, year) using a pointer to a structure.
 *Called from main()
 *Date: 1/10/2015
 *Sources of Help: Handout
 */

 #include <stdio.h>
 #include "pa0_strings.h"
 #include "pa0.h"

 /*
  *Function name: printDueDate()
  *Function prototype:
  *  void printDueDate( const struct DueDate *dueDate );
  *Description: prints to stdout the month, day, and year members of a
  *struct DueDate node.
  *Parameters:
  *   arg1: struct DueDate * dueDate -- pointer to the 
  *   DueDate struct which should be printed.
  *Side Effects: Outputs the due date of the assignment
  *Error Conditions: Checks to make sure arg1 is not NULL.
  *   No checks to ensure struct data are correct type/values.
  *Return Value: None.
  */

  void
  printDueDate( const struct DueDate *dueDate ) {
    if( dueDate != NULL)
      (void) printf( STR_DUEDATE, dueDate->month, dueDate->day, dueDate->year);
  }


