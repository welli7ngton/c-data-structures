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

int list_length(List *li){
  // -1 if list is null
  if (li == NULL) {
    return -1;
  }
    // -1 if first item of the list is null (equals an empty list)
  if ((*li) == NULL){
    return 0;
  }
  
  int count = 0;
  Elem *node = *li;
  while (node != NULL) {
    count++;
    node = node->next;
  }
  return count;
}

int is_empty(List *li){
  if (li == NULL) {
    return -1;
  }
  if ((*li) == NULL) {
    return 1;
  }
  return 0;
}
