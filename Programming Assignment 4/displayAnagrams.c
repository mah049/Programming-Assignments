/*
 *Filename:displayAanagrams.c
 *Author: Mark Huang
 *Date: 2/24/2015
 *Userid: cs30xcl
 *Description: displays the anagram from the structanagramMatches
 *it must travers using pointers the entire list of sorted words
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pa3.h"
#include "pa3_strings.h"

/*
 *Function name: displayAnagrams
 *FUnction prototype: void displayAnagrams(int count, struct
 *                    anagramMatches * matches);
 *Description: displays the anagrams found in the strings
 *Parameters: 
 *           count: num of anagrams found
 *           matches: contains info of what user is looking for 
 *            and list of anagram pointers
 *Return Value: None
 */

 void displayAnagrams(int count, struct anagramMatches * matches){
   /*struct anagram pointer that used to iterate*/
   struct anagram * printer;
   /*gets the number of printed*/
   int printed = 0;
   /*if there are no anagrams*/
   if(count == 0){
     (void)fprintf(stdout,STR_NO_ANAGRAMS_FOUND);
     return;
   }
   /*if there is one anagram make sure it is not the same thing*/
   if(count == 1){
     if(strcmp(matches->word.word,matches->first->word)==0){
       (void)fprintf(stdout,STR_NO_ANAGRAMS_FOUND);
       return;
     }
   }

   /*if the count is greater than 1*/
   (void)fprintf(stdout,STR_ANAGRAMS_FOUND);
   /*make it the first struct anagram pointer*/
   printer = matches->first;
   /*loop thorugh all the structs until it hits the last*/
   while(printer<= matches->last){
     /*if they are not the same word print and increment*/
     if(strcmp(printer->word,matches->word.word)!=0){
       (void)printf(" %s",printer->word);
       printed++;
     }
     /*once the number of anagrams have been reached*/
     if(count == printed){
       break;
     }
     /*increment the pointer*/
     printer++;
   }
   /*printa  new line character*/
   (void)fprintf(stdout,STR_NEW_LINE);
   return;
 }
