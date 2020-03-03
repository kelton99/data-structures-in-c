#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack *create_stack(int capacity);
int pop(Stack *s);
void push(Stack *s, int value);
int top(Stack *s);
int size(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);
void print(Stack *s);
void destroy(Stack *s);

#endif 

