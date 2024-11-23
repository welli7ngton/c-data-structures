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

void append_to_list(List *li, struct student st) {
  li->data[li->qtd] = st;
  li->qtd++;
}
