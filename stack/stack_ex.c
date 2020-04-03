#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#ifdef _WIN32
	void clear_console() { system("cls"); }
#else
	void clear_console() { system("clear"); }
#endif

int get_int_input(int *value);
int get_menu_input(void);
void print(Stack *s);
void push(Stack *s);
void pop(Stack *s);
void invert(Stack *s);
void remove_element(Stack *s);
void load_dataset(Stack *s);
void help();

enum options {OPT_EXIT, OPT_PUSH, OPT_POP, OPT_INVERT, OPT_REMOVE, OPT_HELP};

int main(void)
{
	Stack *s = create_stack(10);
	load_dataset(s);
	while(1) {
		clear_console();
		
    		print(s);

    		int option = get_menu_input();

    		switch (option) {
    			case OPT_EXIT:
    				exit(0);
    			case OPT_PUSH:
    				push(s);
    				break;
    			case OPT_POP:
    				pop(s);
    				break;
			case OPT_INVERT:
    				invert(s);
    				break;
			case OPT_REMOVE:
    				remove_element(s);
    				break;
			case OPT_HELP:
				help();
				break;
			default:
				puts("Option not avaliable!");
				break;
    		}

    		puts("Press any key to continue to menu...");
		getchar();

	}
}

int get_int_input(int *value)
{
	char line[256];

	if (fgets(line, sizeof(line), stdin)) 
		return sscanf(line, "%d", value);
	
	return 0;
}

int get_menu_input(void)
{
	puts("Options Menu:");
	puts("[0] exit   [1]push");
	puts("[2] pop    [3]invert");
	puts("[4] remove [5]help");
	puts("Insert an option:");
	
	int option;
	if (get_int_input(&option)) return option;
	
	return 0;
}

void print(Stack *s)
{
	printf("%s","Current Stack: ");
	stack_print(s);
}

void push(Stack *s)
{
	int value;
	puts("Insert a value to push:");
	if (get_int_input(&value)) 
		stack_push(s, value);
	else
		puts("Not able to push, invalid input.");
}

void pop(Stack *s)
{
	int value = stack_pop(s);
	if (value == -1) return;
	printf("Value dequeued: %d\n", value);
}

void invert(Stack *s)
{
	if (is_empty(s)){
		puts("Can't invert a empty stack");
		return;
	}
	
	Stack *aux = create_stack(stack_size(s));
	Stack *aux2 = create_stack(stack_size(s));

	while(!is_empty(s)){
		stack_push(aux, stack_pop(s));
	}
	while(!is_empty(aux)){
		stack_push(aux2, stack_pop(aux));
	}
	while(!is_empty(aux2)){
		stack_push(s, stack_pop(aux2));
	}
}

void remove_element(Stack *s)
{
	if (is_empty(s)){
		puts("Can't remove an element of an empty stack");
		return;
	}

	int n;
	puts("Insert a value to remove: ");
	if(!get_int_input(&n)) return;

	Stack *aux = create_stack(stack_size(s));
	while (stack_top(s) != n){
		stack_push(aux, stack_pop(s));
	}

	stack_pop(s);
	while (!is_empty(aux)){
		stack_push(s, stack_pop(aux));
	}
}

void load_dataset(Stack *s)
{
	int i;
	for(i = 0; i < 10; i++) stack_push(s, i);
}

void help()
{
	//TODO help
}