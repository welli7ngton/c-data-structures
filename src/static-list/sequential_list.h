#include <stdbool.h>

// tamanho máximo da lista
#define MAX 100

// struct exemplo de tipo de dado dinâmico a ser inserido na lista
typedef struct student {
  int register_number;
  char name[30];
  float n1, n2, n3;
} Student;

// implementação da lista
typedef struct list {
  int qtd;
  struct student data[MAX];
} List;

List *create_list();

void free_list(List *li);

int list_length(List *li);

bool is_full(List *li);

bool is_empty(List *li);

int append_to_end(List *li, Student st);

int append_to_start(List *li, Student st);

int append_sorting(List *li, Student st);

int remove_from_start(List *li);

int remove_from_end(List *li);

int remove_from_index(List *li, int idx);
