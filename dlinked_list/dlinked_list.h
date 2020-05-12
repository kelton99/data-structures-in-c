#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H
#include "node.h"

typedef struct dl_list DLinked_List;

struct dl_list{
        int size;
        Node *head;
        Node *tail;
};

DLinked_List *create_list();

int list_size(DLinked_List *list);

int is_empty(DLinked_List *list);

void list_push_front(DLinked_List *list, int value);

void list_push_back(DLinked_List *list, int value);

void list_insert(DLinked_List *list, int value, int index);

void list_remove(DLinked_List *list, int value); //return position

void list_remove_from(DLinked_List *list, int index); //return element

int list_search(DLinked_List *list, int value);

void list_print(DLinked_List *list);

#endif