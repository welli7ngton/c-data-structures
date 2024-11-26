struct student {
  int id;
  char name[30];
  float n1, n2;
};

typedef struct element *List;

List *create_list();

void free_list(List *li);
