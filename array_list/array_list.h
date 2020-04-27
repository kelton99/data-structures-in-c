#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct a_list Array_List;

Array_List *create_list(int capacity);

int list_size(Array_List *list);

int is_full(Array_List *list);

int is_empty(Array_List *list);

void list_push_back(Array_List *list, int value);

void list_insert(Array_List *list, int value, int index);

int list_remove(Array_List *list, int value); //return position

int list_remove_from(Array_List *list, int index); //return element

int list_search(Array_List *list, int value);

void list_print(Array_List *list);

#endif