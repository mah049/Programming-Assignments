#include "test.h"
#include <stdio.h>

test_charCompare() {
  char lhs = 'a';
  char rhs = 'a';
  TEST(charCompare(&lhs, &rhs) == 0);

  lhs = 'a';
  rhs = 'b';
  TEST(charCompare(&lhs, &rhs) < 0);

  TEST(charCompare(&rhs, &lhs) > 0);
}

int main(int argc, char *argv[]) {
  (void) fprintf(stderr, "Starting test_charCompare\n");

  test_charCompare();

  (void) fprintf(stderr, "Done.\n");

  return 0;
}
