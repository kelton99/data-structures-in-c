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

void list_push_back(DLinked_List *list, int value)
{
        Node *new_node = create_node(value);
        if(is_empty(list)){
                list->head = new_node;
                list->tail = new_node;
        } else {          
                list->tail->next = new_node;
                new_node->prev = list->tail;
                list->tail = new_node;
        }
        list->size++;
}

void list_push_front(DLinked_List *list, int value)
{
        Node *new_node = create_node(value);
        if(is_empty(list)){
                list->head = new_node;
                list->tail = new_node;
        } else {          
                list->head->prev = new_node;
                new_node->next = list->head;
                list->head = new_node;
        }
        list->size++;
}

static void sew(Node *node, int value)
{
                Node *new_node = create_node(value);
                new_node->next = node;
                new_node->prev = node->prev;
                node->prev->next = new_node;
                node->prev = new_node;

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
                for(int i = list->size - 1; i > index; i--) 
                        aux_node = aux_node->prev;
        }
        return aux_node;
}

void list_insert(DLinked_List *list, int value, int index)
{               
        if(list->size <= index || index < 0){
                puts("Invalid index");
                return;
        }
        
        Node *aux_node = set_pointer(list, index);
        
        if(aux_node->prev == NULL) {
                list_push_front(list, value);
        } else if (aux_node->next == NULL){
                list_push_back(list, value);
        } else {
                sew(aux_node, value);
                list->size++;
        }
        
}

int list_search(DLinked_List *list, int value)
{
        Node *aux_node = list->head;
        for(int i = 0; aux_node != NULL; i++){
                if(aux_node->item == value)
                        return i;
                aux_node = aux_node->next;
        }
        return -1;
}

void list_remove(DLinked_List *list, int value)
{
        if(is_empty(list)) return;
        Node *aux_node = list->head;

        if(list->head->item == value) {
                list->head = aux_node->next;
                free(aux_node);
                list->size--;
        }

        while(aux_node->next != NULL){
                if(aux_node->next->item == value){
                        if(aux_node->next->next != NULL)
                                aux_node->next->next->prev = aux_node->next->prev;
                        aux_node->next = aux_node->next->next;
                        free(aux_node);
                        list->size--;

                }else{ 
                        aux_node = aux_node->next;
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

        if(aux_node->prev == NULL) {
                aux_node->next->prev = aux_node->prev;
                list->head = aux_node->next;

        } else if (aux_node->next == NULL){
                aux_node->prev->next = aux_node->next;
                list->tail = aux_node->prev;

        } else {
                aux_node->next->prev = aux_node->prev;
                aux_node->prev->next = aux_node->next;
        }
        free(aux_node);                
        list->size--;
}

void list_print(DLinked_List *list)
{
        if(is_empty(list)){
                puts("The list is empty");
                return;
        }
        Node *aux_node = list->head;
        while(aux_node != NULL){
                printf("[%d]", aux_node->item);
                aux_node = aux_node->next;
        }
        printf("\nSize: %d\n", list->size);
}