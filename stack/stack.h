#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack * create_stack();
int pop(Stack * s);
void push(Stack *s, int value);
void destroy(Stack * s);

#endif 

