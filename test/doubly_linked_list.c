#include "../src/doubly_linked_list/doubly_linked_list.h"
#include "./suite_runner/suite_runner.h"
#include "./test_helpers.h"
#include <stdio.h>

void test_create_list() {
  List *li = create_list();
  ASSERT(*li == NULL && li != NULL,
         "create_list() create an empty list, the first instance of the list "
         "point to a NULL value.");
}

int main() {
  func tests[] = {
      test_create_list,
  };
  int amount_of_tests = sizeof(tests) / sizeof(tests[0]);

  run(tests, amount_of_tests, "Sequential Static List");
  return 0;
}
