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

void test_is_empty() {
  List *li = create_list();
  ASSERT(is_empty(li),
         "is_empty() return 1 (truthy value) if the list is empty");
}

void test_is_empty_in_a_null_list() {
  ASSERT(is_empty(NULL) == -1, "is_empty() return -1 if the list is NULL");
}

int main() {
  func tests[] = {
      test_create_list,
      test_is_empty,
      test_is_empty_in_a_null_list,
  };
  int amount_of_tests = sizeof(tests) / sizeof(tests[0]);

  run(tests, amount_of_tests, "Sequential Static List");
  return 0;
}
