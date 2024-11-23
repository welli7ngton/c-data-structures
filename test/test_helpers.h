#include <stdlib.h>
#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

#define ASSERT(test, message)                                                  \
  do {                                                                         \
    if (test) {                                                                \
      printf(GREEN "PASS: " RESET message "\n");                               \
    } else {                                                                   \
      printf(RED "FAIL: " RESET message "\n");                                 \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)

#endif // TEST_HELPERS_H
