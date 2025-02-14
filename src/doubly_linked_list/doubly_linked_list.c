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

int list_length(List *li) {
  // -1 if list is null
  if (li == NULL) {
    return -1;
  }
  // -1 if first item of the list is null (equals an empty list)
  if ((*li) == NULL) {
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

int is_empty(List *li) {
  if (li == NULL) {
    return -1;
  }
  if ((*li) == NULL) {
    return 1;
  }
  return 0;
}


int append_to_start(List *li, struct student st){
  if (li == NULL) {
    return -1;
  }

  Elem *node = (Elem*) malloc(sizeof(Elem));

  if ((*node) == NULL){  // verifica se a alocacao foi bem sucedida
    return -1;
  }

  node->data = st;    // adicionando novo estudante.
  node->next = (*li)  // colocando antigo inicio da lista como proximo item.
  node->prev = NULL;  // como o node estará no inicio da lista ele deve apontar para nulo.

  // caso o inicio da lista seja diferete de NULL (a lista nao está vazia).
  if (*li != NULL){
    (*li)->prev = node; // atual inicio da lista recebe o node como anterior a ele.
  }
  *li = node;  // inicio da lista recebe o node.
}

int append_to_end(List *li, struct student st){
  if (li == NULL) return -1;
  Elem *node = (Elem*) malloc(sizeof(Elem));
  if (node == NULL) return -1;

  node->data = st;
  node->next = NULL;
  if((*li) == NULL){
    // lista vazia: insercao no inicio
    node->prev = NUll;
    *li = node;
    return 1;
  } else {
    Elem *temp = *li;
    while (temp->next != NULL) {
      temp = temp->next; // step ahead
    }
    temp->next = node; // ultimo elemento passa a ser o penultimo.
    node->prev = temp; // novo ultimo elemento tem como elemento antecessor o antigo ultimo elemento.
  }
  return 1;
}

int append_sorting(List *li, struct student st){
  if (li == NULL) return -1;
  Elem *node = (Elem*) malloc(sizeof(Elem));
  if (node == NULL) return -1;

  node->data = st;
  node->next = NULL;
  if((*li) == NULL){
    // lista vazia: insercao no inicio
    node->prev = NULL;
    *li = node;
    return 1;
  } else {
    Elem *prev, *curr = *li;
    while (curr != NUll && curr->data.id < st.id) {
      prev = curr;
      curr = curr->next;
    }
    if (curr == *li){  // inicio da lista
      node->prev = NUll;
      (*li)->prev = node;
      node->next = (*li);
      *li = node;
    } else {
      node->next = prev->next;
      node->prev = prev;
      if (curr != NULL){
        curr->prev = node;
      }
    }
    return 1
  }

