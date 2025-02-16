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
         "is_empty() return 1 (truthy value) if the list is empty.");
}

void test_is_empty_in_a_null_list() {
  ASSERT(is_empty(NULL) == -1, "is_empty() return -1 if the list is NULL.");
}

void test_list_length() {
  List *li = create_list();
  ASSERT(list_length(li) == 0,
         "list_length() return the actual length of the list.");
}

void test_list_length_in_a_null_list() {
  ASSERT(list_length(NULL) == -1,
         "list_length() should return -1 in a not valid list.");
}

void test_append_to_start() {
  List *li = create_list();

  struct student s1 = {1, "default", 10.0, 8.9};
  struct student s2 = {2, "default", 10.0, 8.9};
  struct student s3 = {3, "default", 10.0, 8.9};

  append_to_start(li, s1);
  append_to_start(li, s2);
  append_to_start(li, s3);

  Elem *head = *li;

  ASSERT(head->data.id == 3 && head->next->data.id == 2,
         "append_to_start() should append an item to the start of the list.");
}

int main() {
  func tests[] = {
      test_create_list,
      test_is_empty,
      test_is_empty_in_a_null_list,
      test_list_length,
      test_list_length_in_a_null_list,
      test_append_to_start,
  };
  int amount_of_tests = sizeof(tests) / sizeof(tests[0]);

  run(tests, amount_of_tests, "Doubly Linked List");
  return 0;
}
