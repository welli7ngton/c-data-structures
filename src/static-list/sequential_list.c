#include "sequential_list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// implementação da lista
struct list {
  int qtd;
  struct student data[MAX];
};

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

void append_to_list(List *li, student st) {
  if (li == NULL) {
    return -1;
  } else {
    li->qtd++;
    li->st;
  }
}
