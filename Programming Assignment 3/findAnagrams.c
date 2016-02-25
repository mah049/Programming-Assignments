/*
 *Filename:findAnagrams.c
 *Author: Mark Huang
 *Date: 2/23/2015
 *Userid: cs30xcl
 *Description:finds the number of anagrams in a given anagram
 *
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "pa3.h"
#include "pa3_strings.h"

/*
 *Function name: findAnagrams()
 *FUnction prototype: int findAnagrams(const struct anagramInfo
                      ,struct anagramMatches *matches);
 *Description: finds the number of anagrams in a given anagram
 *Parameters: 
 *           info: struct to store anagramInfo
 *           matches: holds the list of anagrams matches
 *Return Value: number of anagrams
 */

int findAnagrams( const struct anagramInfo *info, 
                 struct anagramMatches * matches){

  /*new line pointer*/
  char * nlPtr;
  /*character in lower case*/
  char lowercase;
  /*counter used to loop through sorted member*/
  int counter = 0;
  /*counts how many anagrams there are*/
  int anagramCounter = 0;
  /*anagram pointer match that contains the word to search*/
  struct anagram * match;
  /*offset for looping through structs*/
  int offset = 1;

  /*find the new line*/
  nlPtr = strchr(matches->word.word,'\n');
  /*dereferences the new line pointer and puts a null terminator*/
  if(nlPtr!=NULL){
    *nlPtr = '\0';
  }
  
  /*converts all the letters to lower case*/
  while(matches->word.word[counter]){
    lowercase = tolower(matches->word.word[counter]);
    /*stores it into the sorted member of word*/
    matches->word.sorted[counter] = lowercase;
    counter++;
  }
  /*alphabetizes the sorted member*/
  qsort(matches->word.sorted,strlen(matches->word.sorted),
                                 sizeof(char),charCompare);
  
  /*finds a random pointer to the anagram that matches*/
  match = (struct anagram *)bsearch(&(matches->word),info->anagramPtr,
        info->numOfAnagrams,sizeof(struct anagram),sortedMemberCompare);
  
  /*if there are no matches set the first and last to be null and return 0*/
  if(match==NULL){
    matches->first = NULL;
    matches->last = NULL;
    return 0;
  }

  /*loops trhough the anagramPtr until it hits the end*/
  while(match >= info->anagramPtr)
  {
    /*if there is a match move the first anagram pointer down*/
    if(strcmp(matches->word.sorted, match->sorted) == 0)
    {
      matches->first = match;
    }
    /*decrement the pointer*/
    match--;
  }
  /*increment the pointer*/
  match++;

  /*loops through to the right until it hits the end*/
  while(match <= (info->anagramPtr)+(info->numOfAnagrams)-offset)
  {
    /*if there is a match make the last one a match and increment
    anagramCounter*/
    if(strcmp(matches->word.sorted, match->sorted) == 0)
    {
      matches->last = match;
      anagramCounter++;
    }
    /*increment the pointer*/
    match++;
  }
  
  /*return how many anagrams found*/
  return anagramCounter;


}
