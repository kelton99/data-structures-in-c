#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.h"

// Terrible way to clean the console window, using only for the sake of simplicity
#ifdef _WIN32
	void clear_console() { system("cls"); }
#else
	void clear_console() { system("clear"); }
#endif

enum options {OPT_EXIT, OPT_ENQUEUE, OPT_DEQUEUE, OPT_SEARCH, OPT_HELP};

int get_int_input(int *value);
int get_menu_input(void);
void print_queue(Circular_Queue *q);
void enqueue(Circular_Queue *q);
void dequeue(Circular_Queue *q);
void search(Circular_Queue *q);
void help();

int main(void)
{
	Circular_Queue *q = queue_create();

	while(1) {
		clear_console();
    		print_queue(q);

    		int option = get_menu_input();

    		switch (option) {
    			case OPT_EXIT:
    				exit(0);
    			case OPT_ENQUEUE:
    				enqueue(q);
    				break;
    			case OPT_DEQUEUE:
    				dequeue(q);
    				break;
    			case OPT_SEARCH:
    				search(q);
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
	puts("Options Menu:\n[0] exit\n[1] enqueue\n[2] dequeue\n[3] search");
	puts("Insert an option:");
	
	int option;
	if (get_int_input(&option)) return option;
	
	return 0;
}

void print_queue(Circular_Queue *q)
{
	printf("Current queue: ");
	queue_print(q);
}

void enqueue(Circular_Queue *q) 
{
	int value;
	puts("Insert a value to enqueue:\n");
	if (get_int_input(&value)) 
		queue_enqueue(q, value);
	else
		puts("Not able to enqueue, input invalid.");
}

void dequeue(Circular_Queue *q)
{
	int value = queue_dequeue(q);
	if (value == -1) return;

	printf("Value dequeued: %d\n", value);
}

void search(Circular_Queue *q)
{

	int value, position;
	printf("Insert a value to search:\n");
	
	if (get_int_input(&value)) {
		position = queue_search_value(q, value);

		if (position != -1)
			printf("Value is on position %d\n", position);
		else 
			puts("value not found.");
		
	} else {
		puts("Type a valid input to search.");
	}
}

void help()
{
	/* TODO
	* Print in the screen what is a circular queue
	* How does it work and the execution time using BigO notation
	*/
}