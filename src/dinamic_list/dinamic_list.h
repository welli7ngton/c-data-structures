struct student {
  int id;
  char name[30];
  float n1, n2;
};

typedef struct element *List;

struct element {
  struct student data;
  struct element *next;
};

typedef struct element Elem;
List *create_list();

void free_list(List *li);

int list_length(List *li);

int is_empty(List *li);

int append_to_start(List *li, struct student st);

int append_to_end(List *li, struct student st);

int append_sorting(List *li, struct student st);

int remove_from_start(List *li);

int remove_from_end(List *li);

int remove_by_id(List *li, int id);
