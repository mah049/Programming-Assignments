#include "test.h"
#include <stdio.h>
#include "pa3.h"

test_sortedMemberCompare() {
  /* Create new structs for each test */

  struct anagram lhs1 = {"post", "opst"};
  struct anagram rhs1 = {"stop", "opst"};

  TEST(sortedMemberCompare(&lhs1, &rhs1) == 0);

  struct anagram lhs2 = {"water", "aertw"};
  struct anagram rhs2 = {"frog", "fgor"};

  TEST(sortedMemberCompare(&lhs2, &rhs2) < 0);
}

int main(int argc, char *argv[]) {
  (void) fprintf(stderr, "Starting test_sortedMemberCompare\n");

  test_sortedMemberCompare();

  (void) fprintf(stderr, "Done.\n");

  return 0;
}
