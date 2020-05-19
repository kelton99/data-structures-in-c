#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "node.h"

Linked_List *create_list()
{
        Linked_List *list = malloc(sizeof(Linked_List));
        list->size = 0;
        list->head = create_node(-1);
        return list;
}

int list_size(Linked_List *list)
{
        return list->size;
}

int is_empty(Linked_List *list)
{
        return list->size == 0;
}

void list_push_back(Linked_List *list, int value)
{
        Node *aux_node = list->head;
        while(aux_node->next != NULL)
                aux_node = aux_node->next;
        aux_node->next = create_node(value);
        
        list->size++;
}

void list_insert(Linked_List *list, int value, int index)
{               
        if(list->size < index || index < 0){
                puts("Invalid index");
                return;
        }

        if(index == list->size) {
                list_push_back(list, value);
                return;
        }
        
        Node *aux_node = list->head;
        
        for(int i = 0; i < index; i++) 
                aux_node = aux_node->next;

        Node *new_node = create_node(value);

        new_node->next = aux_node->next;
        aux_node->next = new_node;

        list->size++;
}

int list_search(Linked_List *list, int value)
{
        Node * aux_node = list->head;
        for(int i = 0; aux_node->next != NULL; i++){
                if(aux_node->next->item == value)
                        return i;
                aux_node = aux_node->next;
        }
        return -1;
}

void list_remove(Linked_List *list, int value)
{
        if(is_empty(list)) return;

        Node * aux_node = list->head;
        for(;aux_node->next != NULL; aux_node = aux_node->next){
                if(aux_node->next->item == value){
                        Node *aux2 = aux_node->next;
                        aux_node->next = aux_node->next->next;
                        free(aux2);
                        list->size--;
                }
        }
}

void list_remove_from(Linked_List *list, int index)
{
        if(list->size <= index || index < 0){
                puts("Invalid index");
                return;
        }
       
        Node * aux_node = list->head;
        for(int i = 0; i < index; i++) 
                aux_node = aux_node->next;

        Node *aux2 = aux_node->next;
        aux_node->next = aux_node->next->next;
        free(aux2);
        list->size--;
}

void list_print(Linked_List *list)
{
        if(is_empty(list)){
                puts("The list is empty");
                return;
        }
        Node *aux_node = list->head;
        for(; aux_node->next != NULL; aux_node = aux_node->next)
                printf("[%d]", aux_node->next->item);
        printf("\nSize: %d\n", list->size);
}