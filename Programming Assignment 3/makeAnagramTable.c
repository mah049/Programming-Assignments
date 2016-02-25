/*
 *Filename:makeAnagramTable.c
 *Date:2/18/2105
 *Userid: cs30xcl
 *Description: makes a anagram array and stores it into struct anagramInfo
 *it sorts the sorted member and it sorted the entire array struct first 
 *based on the sorted member
 *
 */

#include <errno.h>
#include <stdio.h>  /* printf*/
#include <stdlib.h> /*malloc,free*/
#include <errno.h>
#include <string.h>
#include <ctype.h> /*tolower*/

#include "pa3.h"
#include "pa3_strings.h"


/*
 *Function name: makeAnagramTable
 *Function prototype: int makeAnagramTable(const char*filename, 
 *struct anagramInfo* info)
 *Parameters:filename:file we are reading from
 *           info:the struct anagraminfo we store into
 *ReturnValue: int based on whether it was succesfull or not 
 *             returns 0 if successful
 *
 */

int makeAnagramTable(const char* filename, struct anagramInfo* info){
  
  /*file pointer we are reading from*/
  FILE * aFile;
  /*old anagram pointer*/
  struct anagram * old;
  /*used for when reallocing a new struct anagram pointer*/
  struct anagram * new;
  /*points to the new line character*/
  char * nlPtr;
  /*array of wordHOlder size*/
  char wordHolder[SIZE];
  /*counter to loop through the sorted member*/
  int counter = 0;
  /*how much to increase for reallocing*/
  int reallocCounter = 2;
  /*reallocoffset to get the index value*/
  int reallocOffset = 2;
  /*lower case character*/
  char lowercase;
  
  /*clear errno*/
  errno = 0;
  /*open filename if cannot be opened return errno*/
  aFile = fopen(filename,FILE_OPEN_MODE);
  if(aFile==NULL){
    return errno;
  }
  
  /*mallocs a new struct anagram pointer*/
  old=(struct anagram *)malloc(sizeof(struct anagram));
  
  /*if it failed to malloc close the file and return errno*/
  if(old == NULL){
    (void)fclose(aFile);
    return errno;
  }
  
  /*make sure everthing in the member is 0*/
  (void)memset(old,0,sizeof(struct anagram));

  /*reads the file inputted as long as it does not equal null*/
  while(fgets(wordHolder,SIZE,aFile)!=NULL){
    /*because it returns new line*/
    nlPtr = strchr(wordHolder,'\n');
    /*if it exists make it a null termintor*/
    if(nlPtr){
      *nlPtr = '\0';
    }
    /*copy the word into world holder*/
    (void)strcpy(old[reallocCounter-reallocOffset].word,wordHolder);
    /*loops through the word holder to convert it to lower case*/
    while(wordHolder[counter]){
      lowercase = tolower(wordHolder[counter]);
      /*put the lower case into the sorted member*/
      old[reallocCounter-reallocOffset].sorted[counter] = lowercase;
      counter++;
    }
    
    /*reset the counter*/
    counter = 0;
    /*sort the sorted member of the old anagram*/
    (void)qsort(old[reallocCounter-reallocOffset].sorted,strlen
    (old[reallocCounter-reallocOffset].sorted),sizeof(char),charCompare);
    /*create a new structanagram that is twice its size*/
    new=(struct anagram *)realloc(old,reallocCounter*sizeof(struct anagram));
    reallocCounter++;
   
   /*if cannot realloc free the struct * and return and close file*/
   if(new == NULL){
      free(old);
      (void)fclose(aFile);
      return errno;
    }
    /*else memset to 0 the newly allocated struct*/
    else{
      (void)memset(&new[reallocCounter-reallocOffset],0,sizeof(new[0]));
      
    }
    /*set the old equal to new*/
    old = new;
  }
  
  /*sort the arrray of structs based on sorted member first*/
  (void)qsort(new,reallocCounter-reallocOffset,sizeof(struct 
  anagram),anagramCompare);
  /*store the info of anagramPtr as old*/
  info->anagramPtr = old;
  /*store the info of numofanagrams to the indexes created*/
  info->numOfAnagrams = reallocCounter-reallocOffset;
  /*free the old and the new*/
  free(old);
  free(new);
  
  /*successful*/
  return 0;

}
