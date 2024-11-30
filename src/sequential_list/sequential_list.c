#include "sequential_list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <strings.h>

List *create_list() {
  List *li;
  li = (List *)malloc(sizeof(struct list));

  if (li != NULL) {
    li->qtd = 0;
  }

  return li;
}

int free_list(List *li) {
  if (li == NULL) {
    return -1;
  }
  free(li);

  li = create_list();
  return 1;
}

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

int append_sorting(List *li, Student st) {
  if (li == NULL) {
    return -1;
  }
  if (is_full(li)) {
    return -1;
  }

  int k, i = 0;
  // Enquanto i for menor que o tamanho da lista e o numero da matricula da
  // da posição i for menor que o aluno passado como parâmetro, incremente o i
  while (i < li->qtd && li->data[i].register_number < st.register_number) {
    i++;
  }
  for (k = li->qtd - 1; k >= i; k--) {
    li->data[k + 1] = li->data[k];
  }
  li->data[i] = st;
  li->qtd++;
  return 1;
}

int remove_from_start(List *li) {
  if (li == NULL) {
    return -1;
  }

  if (is_empty(li)) {
    return -1;
  }

  for (int i = 0; i < li->qtd; i++) {
    li->data[i] = li->data[i + 1];
  }
  li->qtd--;
  return 1;
}

int remove_from_end(List *li) {
  if (li == NULL) {
    return 0;
  }

  if (is_empty(li)) {
    return -1;
  }

  li->qtd--;
  return 1;
}

int remove_from_index(List *li, int idx) {
  if (li == NULL) {
    return -1;
  }

  if (idx < 0 || idx >= li->qtd) {
    // index out of range.
    return -1;
  }

  if (is_empty(li)) {
    // cannot remove items from an empty list.
    return -1;
  }

  for (int k = idx; k < li->qtd - 1; k++) {
    // first K position is the item to be removed and K+1 is the next item in
    // the list.
    li->data[k] = li->data[k + 1];
  }

  li->qtd--;
  return 1;
}

int get_by_index(List *li, int idx, struct student *st) {
  if (li == NULL || idx >= li->qtd) {
    return -1;
  }
  *st = li->data[idx];
  return 1;
}

int get_by_register_number(List *li, int reg_number, struct student *st) {
  if (li == NULL) {
    return -1;
  }

  int i = 0;
  while (i <= li->qtd - 1) {
    if (reg_number == li->data[i].register_number) {
      *st = li->data[i];
      return 1;
    }
    i++;
  }
  return -1;
}
