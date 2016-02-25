/*
 *Filename:tm_secOffset.c
 *Author: Mark Huang
 *Date: 2/8/2015
 *Userid: cs30xcl
 *Description:This function gets the tm_sec offset in the struct
 *
 */


#include <time.h>
#include <stddef.h>


/*
 *Function name: tm_secOffset()
 *FUnction prototype: size_t tm_secOffset();
 *Description: gets the tm_sec offset in the struct tm
 *Return Value: None
 */


size_t tm_secOffset(){
  return offsetof(struct tm, tm_sec);
}
