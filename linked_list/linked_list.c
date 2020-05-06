#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "node.h"

Linked_List *create_list()
{
        Linked_List *list = malloc(sizeof(Linked_List));
        list->size = 0;
        list->head = NULL;
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
        if(is_empty(list)){
                list->head = create_node(value);
        } else {
                Node *aux_node = list->head;
                while(aux_node->next != NULL)
                        aux_node = aux_node->next;
                aux_node->next = create_node(value);
        }
        list->size++;
}

void list_insert(Linked_List *list, int value, int index)
{               
        if(list->size <= index || index < 0){
                puts("Invalid index");
                return;
        }
        
        Node *aux_node = list->head;
        
        for(int i = 1; i < index; i++) 
                aux_node = aux_node->next;

        Node *new_node = create_node(value);

        if(index == 0){
                new_node->next = aux_node;
                list->head = new_node;
        }else{
                new_node->next = aux_node->next;
                aux_node->next = new_node;
        }
        list->size++;
}

int list_search(Linked_List *list, int value)
{
        Node * aux_node = list->head;
        for(int i = 0; aux_node != NULL; i++){
                if(aux_node->item == value)
                        return i;
                aux_node = aux_node->next;
        }
        return -1;
}

void list_remove(Linked_List *list, int value)
{
        if(is_empty(list)) return;
        Node * aux_node = list->head;

        if(list->head->item == value) {
                list->head = aux_node->next;
                list->size++;
        }

        while(aux_node->next != NULL){
                if(aux_node->next->item == value){
                        aux_node->next = aux_node->next->next;
                        list->size--;
                }else{ 
                        aux_node = aux_node->next;
                }
        }
}

void list_remove_from(Linked_List *list, int index)
{
        if(list->size <= index){
                puts("Invalid index");
                return;
        }

        Node * aux_node = list->head;
        for(int i = 1; i < index; i++) 
                aux_node = aux_node->next;

        if(index == 0)
                list->head = aux_node->next;
        else
                aux_node->next = aux_node->next->next;
                
        list->size--;
}

void list_print(Linked_List *list)
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