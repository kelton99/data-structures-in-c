#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

struct a_list{
        int *itens;
        int capacity;
        int size;
};

Array_List *create_list(int capacity)
{
        Array_List *list = (Array_List *) malloc(sizeof(Array_List));
        list->capacity = capacity;
        list->size = 0;
        list->itens = malloc(capacity * sizeof(int));
        return list;
}

int list_size(Array_List *list)
{
        return list->size;
}

int is_full(Array_List *list)
{
        return list->size == list->capacity;
}

int is_empty(Array_List *list)
{
        return list->size == 0;
}

int list_push_back(Array_List *list, int value)
{
        if(is_full(list)){
                puts("The list is full!");
                return 0;
        }
        list->itens[list->size] = value;
        list->size++;
        return 1;
}

void list_push_pos(Array_List *list, int value, int index)
{
        if(is_full(list)){
                puts("The list is full!");
                return;
        }
        for(int i = list->size; i > index + 1; i--)
                list->itens[i + 1] = list->itens[i];
        
        list->itens[index] = value;
        list->size++;
}

int list_search(Array_List *list, int value)
{
        for(int i = 0; i < list->size; i++){
                if(list->itens[i] == value){
                        return i;
                }
        }
        return -1;
}

int list_remove(Array_List *list, int value)
{
        int index = list_search(list, value);
        if(index == -1){
                puts("Value not found");
                return 0;
        }
        for(int i = index + 1; i < list->size; i++)
                list->itens[i - 1] = list->itens[i];
        list->size--;
        return 1;

}
int list_remove_from(Array_List *list, int index)
{
        if(index > list->size){
                puts("Invalid index");
                return -1;
        }
        int element = list->itens[index];

        for(int i = index + 1; i < list->size; i++)
                list->itens[i - 1] = list->itens[i];
        list->size--;

        return element;

}


void list_print(Array_List *list)
{
        if(is_empty(list)) puts("The list is empty!");
        
        for (int i = 0; i < list->size; i++)
                printf("[%d]", list->itens[i]);        
}