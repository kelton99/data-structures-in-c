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
void help();

enum options {OPT_EXIT, OPT_PUSH, OPT_POP, OPT_HELP};

int main(void)
{
	Stack *s = create_stack(10);

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
	puts("Options Menu:\n[0] exit\n[1] push\n[2] pop\n[3] help");
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

void help()
{
	//TODO help
}