#include <stdbool.h>

// tamanho máximo da lista
#define MAX 100

// struct exemplo de tipo de dado dinâmico a ser inserido na lista
struct student {
  int register_number;
  char name[30];
  float n1, n2, n3;
};

typedef struct list List;

List *create_list();

void free_list(List *li);

int list_length(List *li);

bool is_full(List *li);

bool is_empty(List *li);

void append_to_list(List *li, student st);
