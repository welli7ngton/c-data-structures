#include "../src/sequential_list/sequential_list.h"
#include "./suite_runner/suite_runner.h"
#include "./test_helpers.h"
#include <stdio.h>
#include <string.h>

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
  ASSERT(test_list->qtd == 1 && test_list->data[0].register_number == 2,
         "free_list() completely clean the list.");
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

void test_append_sorting() {
  List *test_list = create_list();

  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {22, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "default", 10.0, 8.9, 9.7};

  append_sorting(test_list, test_student3);
  append_sorting(test_list, test_student1);
  append_sorting(test_list, test_student2);

  ASSERT(test_list->data[2].register_number == 22,
         "append_sorting() append the item to list sorting by the register "
         "number.");
}

void test_remove_from_start() {
  List *test_list = create_list();

  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {22, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "default", 10.0, 8.9, 9.7};

  append_sorting(test_list, test_student3);
  append_sorting(test_list, test_student1);
  append_sorting(test_list, test_student2);

  remove_from_start(test_list);

  ASSERT(test_list->data[0].register_number == 3 && test_list->qtd == 2,
         "remove_from_start() remove the first item from the list.");
}

void test_remove_from_end() {
  List *test_list = create_list();

  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {22, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "default", 10.0, 8.9, 9.7};

  append_sorting(test_list, test_student3);
  append_sorting(test_list, test_student1);
  append_sorting(test_list, test_student2);

  remove_from_end(test_list);

  ASSERT(test_list->qtd == 2, "remove_from_end() remove the last item from the "
                              "list, decreasing the amount of items.");
}

void test_remove_from_index() {
  List *test_list = create_list();

  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {22, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "default", 10.0, 8.9, 9.7};

  append_sorting(test_list, test_student3);
  append_sorting(test_list, test_student1);
  append_sorting(test_list, test_student2);

  remove_from_index(test_list, 2);

  ASSERT(test_list->data[1].register_number == 3 && test_list->qtd == 2,
         "remove_from_index() remove an item from its index.");
}

void test_get_by_index() {
  List *test_list = create_list();
  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  append_sorting(test_list, test_student1);

  // A instance of Student to get the values from the function.
  Student st2 = {};

  get_by_index(test_list, 0, &st2);

  ASSERT(st2.register_number == 1 && strcmp(st2.name, "default") == 0,
         "get_by_index() get data from the list by id.");
}

void test_get_by_register_number() {
  List *test_list = create_list();
  Student test_student1 = {1, "default", 10.0, 8.9, 9.7};
  Student test_student2 = {2, "default", 10.0, 8.9, 9.7};
  Student test_student3 = {3, "itworked", 10.0, 8.9, 9.7};

  append_to_end(test_list, test_student1);
  append_to_end(test_list, test_student2);
  append_to_end(test_list, test_student3);

  Student st = {};

  get_by_register_number(test_list, 3, &st);

  ASSERT(st.register_number == 3 && strcmp(st.name, "itworked") == 0,
         "get_by_register_number() return data from the list by the register "
         "number of the student.");
}

void test_remove_from_end_in_an_empty_list() {
  List *test_list = create_list();

  ASSERT(remove_from_end(test_list) == -1, "an empty list shoud return -1.");
}

void test_remove_from_an_invalid_list() {
  List *test_list = NULL;

  ASSERT(remove_from_end(test_list) == 0, "an invalid list should return 0.");
}

int main() {
  func tests[] = {
      test_create_list,
      test_appent_to_end,
      test_free_list,
      test_list_length,
      test_is_full,
      test_is_not_full,
      test_is_empty,
      test_appent_to_start,
      test_append_sorting,
      test_remove_from_start,
      test_remove_from_end,
      test_remove_from_index,
      test_get_by_index,
      test_get_by_register_number,
      test_remove_from_end_in_an_empty_list,
      test_remove_from_an_invalid_list,
  };

  run(tests, 16, "Sequential Static List");
  return 0;
}
