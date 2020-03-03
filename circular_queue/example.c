#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "circular_queue.h"

// Terrible way to clean the console window, using only for the sake of simplicity
#ifdef _WIN32
	void inline clear_console() { system("cls"); }
#else
	void inline clear_console() { system("clear"); }
#endif

enum options {OPT_EXIT, OPT_ENQUEUE, OPT_DEQUEUE, OPT_SEARCH, OPT_INVERT, OPT_HELP};

int get_int_input(int * value)
{
	char line[256];

	if (fgets(line, sizeof(line), stdin)) 
		return sscanf(line, "%d", value);
	
	return false;
}

int get_menu_input(void)
{
	puts("Options Menu:\n[0] exit\n[1] enqueue\n[2] dequeue\n[3] search\n[4] invert");
	puts("Insert an option:");
	
	int option;
	if (1 == get_int_input(&option)) return option;
	
	return false;
}

void print_queue_status(Circular_Queue *q)
{
	printf("Current queue status: ");
	queue_print(q);
}

void enqueue(Circular_Queue *q) 
{
	int value;
	printf("Insert a value to enqueue:\n");
	if (1 == get_int_input(&value)) 
		queue_enqueue(q, value);
	else
		puts("Not able to enqueue, input invalid.");
}

void dequeue(Circular_Queue *q) {
	int value = queue_dequeue(q);
	if (value == false) {
		puts("Not able to dequeue, queue is empty.");
		return;
	}

	printf("Value dequeued: %d\n", value);
}

void search(Circular_Queue *q) {

	int value, position;
	printf("Insert a value to search:\n");
	
	if (1 == get_int_input(&value)) {
		position = queue_search_value(q, value);

		if (position != -1)
			printf("Value is on position %d\n", position);
		else 
			puts("value not found.");
		
	} else {
		puts("Type a valid input to search.");
	}
}

void queue_help(){
	/* TODO
	* Print in the screen what is a circular queue
	* How does it work and the execution time using BigO notation
	*/
}

int main(void)
{
	Circular_Queue *q = queue_create();

	while(true) {
		clear_console();
    		print_queue_status(q);

    		int option = get_menu_input();

		if (option < OPT_EXIT || option > OPT_INVERT) {
    			printf("%d is an invalid option.\n", option);
    			continue;
    		}

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
    			case OPT_INVERT:
    				queue_invert(q);
    				break;
    		}

    		printf("Press any key to continue to menu...");
		getchar();

	}
}