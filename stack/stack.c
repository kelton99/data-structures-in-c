#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct stack{
        int capacity;
        int *elements;
        int size;
};

Stack *create_stack(int capacity)
{
        Stack *s = (Stack *) malloc(sizeof(Stack));
        s->capacity = capacity;
        s->elements = (int *) malloc(capacity * sizeof(int));
        s->size = -1;

        return s;
}

int is_empty(Stack *s)
{
        return s->size == -1;
}

int is_full(Stack *s)
{
        return s->size == s->capacity - 1;
}

void stack_push(Stack *s, int value)
{
        if (is_full(s)) {
                puts("The stack is full!");
                return;
        }
        s->size++;
        s->elements[s->size] = value;
}

int stack_pop(Stack *s)
{
        if (is_empty(s)) {
                puts("The stack is empty!");
                return -1;
        }
        s->size--;
        return s->elements[s->size + 1];
}

int stack_top(Stack *s)
{
        return s->elements[s->size];
}

int stack_size(Stack *s)
{
        return s->size + 1;
}

void stack_print(Stack *s)
{
        if (is_empty(s)) {
                puts("The stack is empty!");
                return;
        }
        int i;
        for (i = 0; i <= s->size; i++)
                printf("[%d]", s->elements[i]);
        
        puts("");
}

void stack_destroy(Stack *s)
{
        if (s != NULL) free(s);
        puts("The Stack is Null");
        return;
}