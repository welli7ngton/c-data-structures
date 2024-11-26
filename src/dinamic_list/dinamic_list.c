#include "dinamic_list.h"
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
