#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack *create_stack(int capacity);

int is_empty(Stack *s);

int is_full(Stack *s);

void stack_push(Stack *s, int value);

int stack_pop(Stack *s);

int stack_top(Stack *s);

int stack_size(Stack *s);

void stack_print(Stack *s);

void stack_destroy(Stack *s);

#endif 

