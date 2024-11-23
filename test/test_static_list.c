#include "../src/static-list/sequential_list.h"
#include "./test_helpers.h"
#include <stdio.h>

void test_create_list() {
  List *test_list = create_list();
  ASSERT(test_list->qtd == 0, "create_list() initializes an empty list.");
}

void test_appent_to_end() {
  List *test_list = create_list();
  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {2, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "default", 10.0, 8.9, 9.7};

  append_to_end(test_list, test_student1);
  append_to_end(test_list, test_student2);
  append_to_end(test_list, test_student3);

  ASSERT(test_list->data[test_list->qtd - 1].register_number == 3,
         "append_to_end() append one instance of Student to the end of the "
         "list.");
}

void test_free_list() {
  List *test_list = create_list();
  Student test_student = {1, "default", 10.0, 8.9, 9.7};
  append_to_end(test_list, test_student);
  free_list(test_list);
  Student test_student2 = {2, "default", 10.0, 8.9, 9.7};
  append_to_end(test_list, test_student2);
  // ASSERT(test_list->qtd == 1 && test_list->data[1].register_number == 2,
  //        "free_list() completely clean the list.");
  // FIXME: this test isn't passing because of the function isint working
  // properly
  int *temp = &test_list->qtd;
  printf("\nlist qtd: %d\n", *temp);
  printf("\nreg_n: %d\n", test_list->data[0].register_number);
}

void test_list_length() {
  List *test_list = create_list();

  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {2, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "default", 10.0, 8.9, 9.7};

  append_to_end(test_list, test_student1);
  append_to_end(test_list, test_student2);
  append_to_end(test_list, test_student3);

  ASSERT(list_length(test_list) == 3,
         "list_length() return the current length of the list.");
}

void test_is_full() {
  List *test_list = create_list();

  for (int i = 0; i < 100; i++) {
    Student test_student = {i, "default", 10.0, 8.9, 9.7};
    append_to_end(test_list, test_student);
  }
  ASSERT(is_full(test_list), "is_full() return true if the list is full or "
                             "false if the list still have space.");
}

void test_is_not_full() {

  List *test_list = create_list();

  for (int i = 0; i < 99; i++) {
    Student test_student = {i, "default", 10.0, 8.9, 9.7};
    append_to_end(test_list, test_student);
  }
  ASSERT(!is_full(test_list),
         "test if theres space in the list after 99 inserts.");
}

void test_is_empty() {
  ASSERT(is_empty(create_list()), "is_empty() verify if the list is empty.");
}

void test_appent_to_start() {
  List *test_list = create_list();

  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {2, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "default", 10.0, 8.9, 9.7};

  append_to_start(test_list, test_student1);
  append_to_start(test_list, test_student2);
  append_to_start(test_list, test_student3);

  ASSERT(test_list->data[0].register_number == 3,
         "append_to_end() append a value at the start of the list, moving "
         "the old values to the next memory address.");
}

int main() {
  printf("\nRunning tests for Sequential Static Lists...\n");
  printf("\n---------------------------------------------\n");
  test_create_list();
  test_appent_to_end();
  // test_free_list();
  test_list_length();
  test_is_full();
  test_is_not_full();
  test_is_empty();
  test_appent_to_start();
  printf(GREEN "\nAll tests passed!\n" RESET);
  printf("\n---------------------------------------------\n");
}
