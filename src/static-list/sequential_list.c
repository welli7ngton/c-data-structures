#include "sequential_list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

List *create_list() {
  List *li;
  li = (List *)malloc(sizeof(struct list));

  if (li != NULL) {
    li->qtd = 0;
  }

  return li;
}

// FIXME: this function isn't working properly, it doesn't clean the pointer and
// do not free the memory, it keeps appending items to the list.
void free_list(List *li) { free(li); }

int list_length(List *li) {
  if (li == NULL) {
    return -1;
  } else {
    return li->qtd;
  }
}

bool is_full(List *li) {
  if (li == NULL) {
    return -1;
  } else {
    return (li->qtd == MAX);
  }
}

bool is_empty(List *li) {
  if (li == NULL) {
    return -1;
  } else {
    return (li->qtd == 0);
  }
}

int append_to_end(List *li, struct student st) {
  if (li == NULL) {
    return -1;
  }
  if (is_full(li)) {
    return 0;
  }

  li->data[li->qtd] = st;
  li->qtd++;
  return 1;
}

int append_to_start(List *li, Student st) {
  if (li == NULL)
    return -1;
  if (is_full(li))
    return 0;
  for (int i = li->qtd - 1; i >= 0; i--) {
    li->data[i + 1] = li->data[i];
  }

  li->data[0] = st;
  li->qtd++;
  return 1;
}
