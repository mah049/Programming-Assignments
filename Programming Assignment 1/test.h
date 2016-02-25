/*
 *Filename: test.h
 *Author: Mark huang
 *userid: cs30xcl
 *Date: 1/27/2015
 *Descritipn: testers
 */

#ifndef TEST

#include <stdio.h>

#define TEST(EX) (void)((EX) || \
(fprintf( stderr, "FAIL: %s File: %s Line: %d\n" , #EX, __FILE__, __LINE__)))

#endif
