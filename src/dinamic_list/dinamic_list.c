#include "dinamic_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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

int list_length(List *li) {
  if (li == NULL)
    return -1;
  int cont = 0;

  Elem *node = *li;

  while (node != NULL) {
    cont++;
    node = node->next;
  }
  return cont;
}

int is_empty(List *li) {
  // list content
  if (*li == NULL) {
    return 1;
  }
  // list
  if (li == NULL) {
    return 1;
  }
  return 0;
}

int append_to_start(List *li, struct student st) {
  if (li == NULL)
    return 0;

  Elem *new_node = (Elem *)malloc(sizeof(Elem));

  if (new_node == NULL)
    return 0;

  new_node->data = st;
  new_node->next = (*li);
  *li = new_node;

  return 1;
}

int append_to_end(List *li, struct student st) {
  if (li == NULL)
    return 0;

  // verifiyng if the memory allocation was succeeded
  Elem *new_node = (Elem *)malloc(sizeof(Elem));
  if (new_node == NULL)
    return 0;
  new_node->data = st;
  // as we know, this item will be the last item in the list, so it needs
  // points to a null value, first we need to set new_node->next == NULL.
  new_node->next = NULL;

  if ((*li) == NULL) {
    *li = new_node;
  } else {
    // saving the main head instance of the list
    Elem *temp = *li;
    // searching for the hole list for an NULL value, that means the end of the
    // linked list.
    while (temp->next != NULL) {
      // step ahead
      temp = temp->next;
    }
    // poiting the last value (NULL) to the new node.
    temp->next = new_node;
  }

  return 1;
}

int append_sorting(List *li, struct student st) {
  // sort by id ascendent count
  if (li == NULL)
    return 0;

  Elem *new_node = (Elem *)malloc(sizeof(Elem));
  if (new_node == NULL)
    return 0;
  new_node->data = st;
  new_node->next = NULL;

  if (is_empty(li)) {
    new_node->next = (*li);
    *li = new_node;
    return 1;
  } else {
    Elem *_prev, *_curr = *li;

    while (_curr != NULL && _curr->data.id < new_node->data.id) {
      // step ahead
      _prev = _curr;
      _curr = _curr->next;
    }
    if (_curr == *li) {
      new_node->next = (*li);
      *li = new_node;
    } else {
      new_node->next = _prev->next;
      _prev->next = new_node;
    }
  }

  return 1;
}

int remove_from_start(List *li) {
  if (li == NULL) {
    return 0;
  }
  if ((*li) == NULL) {
    return 0;
  }
  // getting the first item from the list
  Elem *node = *li;
  // step ahead
  *li = node->next;
  free(node);
  return 1;
}

int remove_from_end(List *li) {
  if (li == NULL) {
    return 0;
  }
  if ((*li) == NULL) {
    return 0;
  }

  Elem *_prev_node, *_curr_node = *li;
  // Enquanto o próximo elemento for diferente de NULL, dê um passo para frente
  while (_curr_node->next != NULL) {
    _prev_node = _curr_node;
    _curr_node = _curr_node->next;
  }

  // Caso a lista só tenha um item
  if (_curr_node == (*li)) {
    *li = _curr_node->next;
    // caso a lista tenha mais de 1 item
  } else {
    _prev_node->next = _curr_node->next;
  }
  free(_curr_node);
  return 1;
}

int remove_by_id(List *li, int id) {
  if (li == NULL) {
    return 0;
  }

  if ((*li) == NULL) {
    return 0;
  }

  Elem *_prev_node, *_curr_node = *li;

  while (_curr_node != NULL && _curr_node->data.id != id) {
    _prev_node = _curr_node;
    _curr_node = _curr_node->next;
  }

  if (_curr_node == *li) {
    *li = _curr_node->next;
  } else {
    _prev_node->next = _curr_node->next;
  }
  free(_curr_node);
  return 1;
}
