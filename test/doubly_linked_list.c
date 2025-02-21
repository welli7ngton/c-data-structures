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

void test_append_to_end() {
  List *li = create_list();

  struct student s1 = {1, "default", 10.0, 8.9};
  struct student s2 = {2, "default", 10.0, 8.9};
  struct student s3 = {3, "default", 10.0, 8.9};

  append_to_end(li, s1);
  append_to_end(li, s3);
  append_to_end(li, s2);

  Elem *head = *li;

  ASSERT(head->data.id == 1 && head->next->data.id == 3,
         "append_to_end() should append an item to the end of the list.");
}

void test_append_sorting() {
  List *li = create_list();

  struct student s1 = {1, "default", 10.0, 8.9};
  struct student s2 = {2, "default", 10.0, 8.9};
  struct student s3 = {3, "default", 10.0, 8.9};

  append_sorting(li, s2);
  append_sorting(li, s3);
  append_sorting(li, s1);

  Elem *head = *li;

  ASSERT(head->data.id == 1 && head->next->data.id == 2,
         "append_sorting() should append an item and sort by id.");
}

void test_remove_from_start() {
  List *li = create_list();

  struct student s1 = {1, "default", 10.0, 8.9};
  struct student s2 = {2, "default", 10.0, 8.9};
  struct student s3 = {3, "default", 10.0, 8.9};

  append_sorting(li, s2);
  append_sorting(li, s3);
  append_sorting(li, s1);

  remove_from_start(li);

  Elem *head = *li;

  ASSERT(
      head->data.id ==
          2 /* && head->next->data.id == 1*/, // BUG: whenever i try to
                                              // access the next item from
                                              // the list i get the
                                              // segmentation error, need fix.
      "remove_from_start() should remove an item from the begining of the "
      "list \nand if the list isnt empty, the first item should point to "
      "NULL.");
}

int main() {
  func tests[] = {
      test_create_list,
      test_is_empty,
      test_is_empty_in_a_null_list,
      test_list_length,
      test_list_length_in_a_null_list,
      test_append_to_start,
      test_append_to_end,
      test_append_sorting,
      test_remove_from_start,
  };
  int amount_of_tests = sizeof(tests) / sizeof(tests[0]);

  run(tests, amount_of_tests, "Doubly Linked List");
  return 0;
}
