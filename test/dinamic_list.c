#include "../src/dinamic_list/dinamic_list.h"
#include "test_helpers.h"
#include <stdio.h>

void test_create_list() {
  List *li = create_list();
  ASSERT(*li == NULL,
         "create_list() create a empty linked list, where the "
         "first instance of an empty linked list is a NULL value.");
}

int main() {
  test_create_list();
  return 0;
}
