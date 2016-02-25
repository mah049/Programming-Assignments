/*
 *Filename: pa0.h
 *Author: Mark Huang
 *Userid: cs30xcl
 *Description: Function protoypes and defines for PA0
 *Date: 1/10/2015
 *Sources of Help: Handout
 *
 */

 #ifndef PA0_H
 #define PA0_H

 #define EXPECTED_ARGS 2

 /*User-defined types used in PA0*/

 struct DueDate {
   const char *month;
   unsigned int day;
   unsigned int year;
 };

 /* Function prototypes for the C and assembly routines used in PA0 */

 void printDueDate( const struct DueDate *dueDate);
 void printWelcome( const char*string);

 int squareNum( int num );

 #endif /* PA0_H */

