#include <stdio.h>
#include <stdlib.h>

#include "dlinked_list.h"
#include "node.h"

DLinked_List *create_list()
{
        DLinked_List *list = malloc(sizeof(DLinked_List));
        list->size = 0;
        list->head = create_node(-1);
        list->tail = create_node(-1);
        list->head->next = list->tail;
        list->tail->prev = list->head;
        return list;
}

int list_size(DLinked_List *list)
{
        return list->size;
}

int is_empty(DLinked_List *list)
{
        return list->size == 0;
}

static void sew(Node *node, int value)
{
        Node *new_node = create_node(value);
        new_node->next = node;
        new_node->prev = node->prev;
        node->prev->next = new_node;
        node->prev = new_node;
}

void list_push_back(DLinked_List *list, int value)
{
        sew(list->tail, value);
        list->size++;
}

void list_push_front(DLinked_List *list, int value)
{
        sew(list->head->next, value);         
        list->size++;
}

Node *set_pointer(DLinked_List *list, int index)
{
        Node *aux_node = NULL;

        if(index < list->size / 2){
                aux_node = list->head;
                for(int i = 0; i < index; i++) 
                        aux_node = aux_node->next;
        } else {
                aux_node = list->tail;
                for(int i = list->size; i > index - 1; i--) 
                        aux_node = aux_node->prev;
        }
        return aux_node;
}

void list_insert(DLinked_List *list, int value, int index)
{               
        if(list->size < index || index < 0){
                puts("Invalid index");
                return;
        }
        
        Node *aux_node = set_pointer(list, index);

        sew(aux_node->next, value);
        list->size++;
}

int list_search(DLinked_List *list, int value)
{
        Node *aux_node = list->head;
        for(int i = 0; aux_node->next->item != -1; i++){
                if(aux_node->next->item == value)
                        return i;
                aux_node = aux_node->next;
        }
        return -1;
}

void list_remove(DLinked_List *list, int value)
{
        if(is_empty(list)) return;
        Node *aux_node = list->head;

        for(; aux_node->next->item != -1; aux_node = aux_node->next){
                if(aux_node->next->item == value){
                        Node * aux2 = aux_node->next;
                        aux_node->next->next->prev = aux_node;
                        aux_node->next = aux_node->next->next;
                        free(aux2);
                        list->size--;
                }
        }
}

void list_remove_from(DLinked_List *list, int index)
{
        if(list->size <= index || index < 0){
                puts("Invalid index");
                return;
        }

        Node *aux_node = set_pointer(list, index);
        Node * aux2 = aux_node->next;
        aux_node->next->next->prev = aux_node;
        aux_node->next = aux_node->next->next;
        free(aux2);
        list->size--;
}

void list_print(DLinked_List *list)
{
        if(is_empty(list)){
                puts("The list is empty");
                return;
        }

        Node *aux_node = list->head;
        for( ;aux_node->next->item != -1; aux_node = aux_node->next)
                printf("[%d]", aux_node->next->item);
                
        printf("\nSize: %d\n", list->size);
}