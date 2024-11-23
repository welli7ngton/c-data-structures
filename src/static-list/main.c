#include "sequential_list.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  List *my_list = create_list();
  struct student st = {1234, "welli7ngton", 1.0, 2.0, 3.0};
  struct student st1 = {1234, "welli7ngton", 1.0, 2.0, 3.0};
  struct student st3 = {1234, "welli7ngton", 1.0, 2.0, 3.0};
  struct student st2 = {1234, "welli7ngton", 1.0, 2.0, 3.0};

  append_to_end(my_list, st);
  append_to_end(my_list, st1);
  append_to_end(my_list, st2);
  append_to_end(my_list, st3);
  printf("\nis full: %d", is_full(my_list));
  printf("\nis empty: %d", is_empty(my_list));
  printf("\nlist length: %d", list_length(my_list));

  return 0;
}
