#include "test.h"
#include "pa3.h"
#include <strings.h>
#include <stdio.h>

test_makeAnagramTable() {
  struct anagramInfo info;
  unsigned long errors;

  errors = makeAnagramTable("four_anagrams.txt", &info);
  TEST(errors == 0);
  TEST(info.numOfAnagrams == 1);
  TEST(strcmp(info.anagramPtr[0].word, "ai") == 0);
  TEST(strcmp(info.anagramPtr[1].word, "ba") == 0);
  TEST(strcmp(info.anagramPtr[2].word, "hi") == 0);
  TEST(strcmp(info.anagramPtr[3].word, "so") == 0);


  TEST(strcmp(info.anagramPtr[0].sorted, "ai") == 0);
  TEST(strcmp(info.anagramPtr[1].sorted, "ab") == 0);
  TEST(strcmp(info.anagramPtr[2].sorted, "hi") == 0);
  TEST(strcmp(info.anagramPtr[3].sorted, "os") == 0);

  TEST(strcmp(info.anagramPtr[0].word, "ba") == 0);
  TEST(strcmp(info.anagramPtr[1].word, "hi") == 0);
  TEST(strcmp(info.anagramPtr[2].word, "so") == 0);
  TEST(strcmp(info.anagramPtr[3].word, "so") == 0);
 
  
  TEST(strcmp(info.anagramPtr[0].sorted, "ab")==0 );
  
  TEST(strcmp(info.anagramPtr[1].sorted, "hi")==0 );

  TEST(strcmp(info.anagramPtr[2].sorted, "os")==0 );

  TEST(strcmp(info.anagramPtr[3].sorted, "hi")==0 );


  errors = makeAnagramTable("invalid_filename.txt", &info);
  TEST(errors != 0);
}

int main(int argc, char *argv[]) {
  (void) fprintf(stderr, "Starting test_makeAnagramTable\n");

  test_makeAnagramTable();

  (void) fprintf(stderr, "Done.\n");

  return 0;
}
