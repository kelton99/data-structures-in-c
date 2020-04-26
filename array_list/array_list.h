#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct a_list Array_List;

Array_List *create_list(int capacity);

int list_size(Array_List *list);

int is_full(Array_List *list);

int is_empty(Array_List *list);

//boolean
int list_push_back(Array_List *list, int value);
//void
void list_push_pos(Array_List *list, int value, int index);

//boolean
int list_remove(Array_List *list, int value);
//element
int list_remove_from(Array_List *list, int index);

int list_search(Array_List *list, int value);

void list_print(Array_List *list);

#endif