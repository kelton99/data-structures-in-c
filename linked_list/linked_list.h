#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

typedef struct l_list Linked_List;

struct l_list{
        int size;
        Node *head;
};

Linked_List *create_list();

int list_size(Linked_List *list);

int is_empty(Linked_List *list);

void list_push_back(Linked_List *list, int value);

void list_insert(Linked_List *list, int value, int index);

void list_remove(Linked_List *list, int value); //return position

void list_remove_from(Linked_List *list, int index); //return element

int list_search(Linked_List *list, int value);

void list_print(Linked_List *list);

#endif