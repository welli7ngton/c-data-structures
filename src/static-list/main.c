#include "sequential_list.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  List *my_list = create_list();
  struct student st = {1234, "welli7ngton", 1.0, 2.0, 3.0};

  append_to_list(my_list, st);
  printf("\nfull: %d", is_full(my_list));
  printf("\nempty: %d", is_empty(my_list));
  printf("\nlist length: %d", list_length(my_list));

  return 0;
}
