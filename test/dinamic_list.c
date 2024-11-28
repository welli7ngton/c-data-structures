#include "../src/dinamic_list/dinamic_list.h"
#include "test_helpers.h"
#include <stdio.h>
#include <string.h>

int help_append_sorting(Elem *ptr) {
  int count = 1;
  while (ptr != NULL) {
    if (ptr->data.id == count) {
      count++;
    } else {
      return 0;
    }
    ptr = ptr->next;
  }
  return 1;
}

void test_create_list() {
  List *li = create_list();
  ASSERT(*li == NULL, "create_list() create a empty linked list, where the "
                      "first instance is a NULL value.");
}

void test_is_empty() {
  List *li = create_list();

  ASSERT(is_empty(li), "is_empty() returns a true value if the list is empty.");
}

void test_append_to_start() {
  List *li = create_list();
  struct student st1 = {1, "st1", 10.0, 10.0};
  struct student st2 = {2, "st2", 10.0, 10.0};

  append_to_start(li, st1);
  append_to_start(li, st2);

  Elem *head = *li;

  struct student data1 = head->data;
  struct student data2 = head->next->data;

  ASSERT(data1.id == 2 && strcmp(data1.name, "st2") == 0 && data2.id == 1 &&
             strcmp(data2.name, "st1") == 0,
         "append_to_start() insert a value at the beggining of the list.");
}

void test_append_to_end() {
  List *li = create_list();
  struct student st1 = {1, "st1", 10.0, 10.0};
  struct student st3 = {3, "st1", 10.0, 10.0};
  struct student st2 = {2, "st2", 10.0, 10.0};

  append_to_start(li, st1);
  append_to_start(li, st3);
  append_to_end(li, st2);

  Elem *head = *li;
  struct student data = head->next->next->data;

  ASSERT(data.id == 2 && strcmp(data.name, "st2") == 0,
         "append_to_end() insert a value to the end of the linked list.");
}

void test_append_sorting() {
  List *li = create_list();
  struct student st1 = {1, "st1", 10.0, 10.0};
  struct student st2 = {2, "st2", 10.0, 10.0};
  struct student st3 = {3, "st3", 10.0, 10.0};
  struct student st4 = {4, "st4", 10.0, 10.0};
  struct student st5 = {5, "st5", 10.0, 10.0};
  struct student st6 = {6, "st6", 10.0, 10.0};

  append_sorting(li, st2);
  append_sorting(li, st5);
  append_sorting(li, st1);
  append_sorting(li, st6);
  append_sorting(li, st4);
  append_sorting(li, st3);

  Elem *head = *li;

  int counter = 1;
  for (int i = 1; i < 6; i++) {
    if (i == head->data.id) {
      counter++;
    }
    head = head->next;
  }

  ASSERT(counter == 6,
         "append_sorting() insert an item in the list sorting by student id.");
}

int main() {
  test_create_list();
  test_is_empty();
  test_append_to_start();
  test_append_to_end();
  test_append_sorting();
  return 0;
}
