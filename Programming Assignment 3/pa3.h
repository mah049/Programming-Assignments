/*
 * Filename: pa3.h
 * Author: TODO: Enter your name
 * Userid: TODO: Enter your cs30x login id
 * Description: Strings used in pa3
 */

#ifndef PA3_H
#define PA3_H

/*
 * C standard library headers
 */
#include <stdio.h>  /* stderr */
#include <stddef.h> /* size_t definition */

/*
 * Program argument checking
 */
#define EXPECTED_ARGS 2

/*
 * Structure definitions
 */
#define SIZE 80 /* buffer size for word and sorted anagram members. */

/*
 * Create one anagram struct per word in dictionary file
 */
struct anagram {
  char word[SIZE];   /* Original word from dictionary */
  char sorted[SIZE]; /* word converted to lowercase and sorted */
};

/*
 * The anagramInfo struct holds the number of anagrams loaded from the
 * dictionary file and a pointer to an array of anagram structures
 * sorted in ascending order
 */
struct anagramInfo {
  struct anagram *anagramPtr; /* Pointer to a dynamically allocated array of
                               * sorted struct anagram objects */
  size_t numOfAnagrams;       /* number of anagrams in anagramPtr */
};

/*
 * When the user enters a word to search for anagrams, store the word in the 
 * anagram word member. Then copy the string to the sorted memeber and convert
 * it to lowercase for searching
 */
struct anagramMatches {
  struct anagram  word;  /* The word entered by the user */
  struct anagram* first; /* First matching anagram */
  struct anagram* last;  /* Last matching anagram */
};

/*
 * C function prototypes you will write
 */
int
makeAnagramTable(const char* filename, struct anagramInfo* info);

int
findAnagrams(const struct anagramInfo *info, struct anagramMatches *matches);

void
displayAnagrams(int count, struct anagramMatches *matches);

/*
 * Assembly function prototypes you will write
 */
int
charCompare(const void *ptr1, const void *ptr2);

int
sortedMemberCompare(const void *p1, const void *p2);

int
anagramCompare(const void *p1, const void *p2);

void
usage(const char* filename);

#endif /* PA3_H */

