#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

// Terrible way to clean the console window, using only for the sake of simplicity
#ifdef _WIN32
	void clear_console() { system("cls"); }
#else
	void clear_console() { system("clear"); }
#endif

enum options {OPT_EXIT, OPT_ENQUEUE, OPT_DEQUEUE};

int get_int_input(int *value);
int get_menu_input(void);
void print_queue(Priority_Queue *q);
void enqueue(Priority_Queue *q);
void dequeue(Priority_Queue *q);

int main(void)
{
	Priority_Queue *p = queue_create(5);

	while(1) {
		clear_console();
    		print_queue(p);

    		int option = get_menu_input();

    		switch (option) {
    			case OPT_EXIT:
    				exit(0);
    			case OPT_ENQUEUE:
    				enqueue(p);
    				break;
    			case OPT_DEQUEUE:
    				dequeue(p);
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
	puts("Options Menu:\n[0] exit\n[1] enqueue\n[2] dequeue\n[3] search");
	puts("Insert an option:");
	
	int option;
	if (get_int_input(&option)) return option;
	
	return 0;
}

void print_queue(Priority_Queue *q)
{
	printf("Current queue: ");
	queue_print(q);
}

void enqueue(Priority_Queue *q) 
{
	int value;
	puts("Insert a value to enqueue:\n");
	if (get_int_input(&value)) 
		queue_enqueue(q, value);
	else
		puts("Not able to enqueue, input invalid.");
}

void dequeue(Priority_Queue *q)
{
	int value = queue_dequeue(q);
	if (value == -1) return;

	printf("Value dequeued: %d\n", value);
}
