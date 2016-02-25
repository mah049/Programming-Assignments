/*Author: Mark Huang
 *Date: 2/24/2015
 *Userid: cs30xcl
 *Description: This is a program that seraches for anagrams 
 *given a user inputted word from the file that the user 
 *inputs
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pa3.h"
#include "pa3_strings.h"

int main( int argc, char *argv[]){
   
   /*errorchecking for makeAnagramTable*/
   int errorCheck = 0;
   /*number of anagrams found by findanagrams*/
   int numOfAnagrams = 0;
   /*struct anagram info for arguments*/
   struct anagramInfo info;
   /*struct anagrammatches for arguments*/
   struct anagramMatches matches;
   /*zero fill the nested struct anagram member*/
   (void)memset(&(matches.word),0,sizeof(struct anagram));
 
   /*error check for if there are not enough or too many args*/
   if( argc != EXPECTED_ARGS ){
     /*print the usage message and exit*/
     usage(argv[0]);
     exit(EXIT_FAILURE);
   }

   /*creates an anagram table and stores the info*/
   errorCheck = makeAnagramTable(argv[1],&info);
   
   /*if an error is returned then perror print usage and exit*/
   if(errorCheck != 0){
     /*makeAnagramTable failed*/
     perror(STR_ERR_MAKE_ANAGRAM_TABLE);
     usage(argv[0]);
     exit(EXIT_FAILURE);
   }

   /*display the str_serach string to stdout*/
   (void)fprintf(stdout,STR_SEARCH);
   /*wordInput is what the user inputs*/
   char wordInput[SIZE];
   /*gets the words inputted by the user*/
   while(fgets(wordInput,SIZE,stdin)){
     /*stores it into the anagramMatches struct*/
     (void)strcpy(matches.word.word,wordInput);
     /*number of anagrams found*/
     numOfAnagrams = findAnagrams(&info,&matches);
     /*displays each anagram*/
     displayAnagrams(numOfAnagrams,&matches);
     /*zero fill the structure*/
     (void)memset(&(matches.word),0,sizeof(struct anagram));
     /*print the search message*/
     (void)fprintf(stdout,STR_SEARCH);

   }

   /*if what the user inputted is not valid*/
   if(wordInput == NULL){
     /*free the memory and exit*/
     free(info.anagramPtr);
     (void)fprintf(stdout,STR_NEW_LINE);
     exit(EXIT_SUCCESS);
   }

   return 0;

 }


