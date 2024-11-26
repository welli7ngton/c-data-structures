#include "dinamic_list.h"
#include <stddef.h>
#include <stdlib.h>

struct element {
  struct student data;
  struct element *next;
};

typedef struct element Elem;

List *create_list() {
  List *li = (List *)malloc(sizeof(List));
  if (li != NULL) {
    *li = NULL;
  }
  return li;
}

void free_list(List *li) {
  if (li != NULL) {
    Elem *node;
    while ((*li) != NULL) {
      node = *li;
      *li = (*li)->next;
      free(node);
    }
    free(li);
  }
}
