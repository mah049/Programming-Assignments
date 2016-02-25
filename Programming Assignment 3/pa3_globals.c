/*
 * Filename: globals.c
 * Author: Mark Huang
 * Userid: cs30xcl
 * Description: Strings used in pa3
 */

/*
 * C Standard Library headers
 */
#include <stddef.h> /* size_t */
#include <stdio.h>  /* stderr */

/*
 * Assignment headers
 */
#include "pa3.h"

/*
 * Used for accessing stderr from your assembly files
 */
FILE *stdError = stderr;

/* 
 * Used in usage.s
 */
const char *STR_USAGE = "\nUsage: %s dictionary_file\n\n";

/*
 * anagramCompare.s sortedMemberCompare.s global offsets
 */
const size_t WORD_OFFSET = offsetof(struct anagram, word);
const size_t SORTED_OFFSET = offsetof(struct anagram, sorted);

