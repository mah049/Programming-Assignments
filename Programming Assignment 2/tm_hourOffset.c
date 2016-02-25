/*
 *Filename:tm_hourOffset.c
 *Author: Mark Huang
 *Date: 2/8/2015
 *Userid: cs30xcl
 *Description:This function gets the tm_hour offset in the struct
 *
 */

#include <time.h>
#include <stddef.h>

/*
 *Function name: tm_hourOffset()
 *FUnction prototype: size_t tm_hourOffset();
 *Description: gets the tm_hour offset in the struct tm
 *Return Value: None
 */

size_t tm_hourOffset(){
  return offsetof(struct tm,tm_hour);
}
