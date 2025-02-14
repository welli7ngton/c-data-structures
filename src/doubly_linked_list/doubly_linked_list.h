struct student {
  int id;
  char nome[20];
  float n1, n2;
};

typedef struct element *List;

struct element {
  struct element *prev;
  struct student data;
  struct element *next;
};

typedef struct element Elem;

List *create_list();

void free_list(List *li);

int list_length(List *li);

int is_empty(List *li);

int append_to_start(List *li, struct student st);

int append_sorting(List *li, struct student st);

int append_to_end(List *li, struct student st);
