/*
 *Filename:tm_minOffset.c
 *Author: Mark Huang
 *Date: 2/8/2015
 *Userid: cs30xcl
 *Description:This function gets the tm_min offset in the struct
 *
 */

#include <time.h>
#include <stddef.h>

/*
 *Function name: tm_minOffset()
 *FUnction prototype: size_t tm_minOffset();
 *Description: gets the tm_min offset in the struct tm
 *Return Value: None
 */


size_t tm_minOffset(){
  return offsetof(struct tm,tm_min);
}
