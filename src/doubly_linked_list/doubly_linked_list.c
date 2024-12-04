#include "./doubly_linked_list.h"
#include <stddef.h>
#include <stdlib.h>

List *create_list() {
  List *li = (List *)malloc(sizeof(List));
  if (li != NULL) {
    *li = NULL;
  }
  return li;
}

void free_list(List *li) {
  if (li == NULL)
    return;

  Elem *node;
  while (node != NULL) {
    node = *li;
    *li = (*li)->next;
    free(node);
  }
  free(li);
}
