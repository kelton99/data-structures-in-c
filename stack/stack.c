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
}

int is_empty(Stack *s)
{
        return s->size == -1;
}

int is_full(Stack *s)
{
        return s->size == s->capacity - 1;
}

int pop(Stack *s)
{
        if(is_empty(s)){
                puts("The Stack is empty!");
                return -1;
        }

        s->size--; //return and decrement in the same line can suck my balls!
        return s->elements[s->size + 1];
}

void push(Stack *s, int value)
{
        if (isFull(s)) {
                puts("The Stack is Full!");
                return;
        }
        s->size++; // return and increment in the same line can suck my balls!
        s->elements[s->size] = value;
}

int top(Stack *s)
{
        return s->elements[s->size];
}

int size(Stack *s)
{
        return s->size;
}

void print(Stack *s)
{
        if (is_empty(s)){
                puts("The stack is empty!");
                return;
        }

        int i;
        for (i = 0; i < s->size; i++)
                printf("[%d]", s->elements[i]);
        
        puts("");
}

void destroy(Stack *s)
{
        if(s != NULL) free(s);
        puts("The Stack is Null");
        return;
}