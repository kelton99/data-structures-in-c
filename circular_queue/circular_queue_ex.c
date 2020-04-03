#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.h"

// Terrible way to clean the console window, using only for the sake of simplicity
#ifdef _WIN32
	void clear_console() { system("cls"); }
#else
	void clear_console() { system("clear"); }
#endif

enum options {OPT_EXIT, OPT_ENQUEUE, OPT_DEQUEUE, OPT_REMOVE};

int get_int_input(int *value);
int get_menu_input(void);
void print_queue(Circular_Queue *q);
void enqueue(Circular_Queue *q);
void dequeue(Circular_Queue *q);
void remove_element(Circular_Queue *q);

int main(void)
{
	Circular_Queue *q = queue_create(5);

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
			case OPT_REMOVE:
    				remove_element(q);
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

void print_empty(Circular_Queue *q)
{
	while (!is_empty(q))
		printf("[%d]", queue_dequeue(q));
	puts("");
}

void print_not_empty(Circular_Queue *q)
{
	for(int i = 0; i < queue_size(q); i++){
		int temp = queue_dequeue(q);
		printf("[%d]", temp);
		queue_enqueue(q, temp);
	}
	puts("");
}

void remove_element(Circular_Queue *q)
{
	if (is_empty(q)){
		puts("Can't remove an element of an empty queue");
		return;
	}

	int n;
	puts("Insert a value to remove: ");
	if(!get_int_input(&n)) return;

	int i = queue_size(q) - 1;

	while(queue_front(q) != n){
		queue_enqueue(q, queue_dequeue(q));
		i--;
	}
	queue_dequeue(q);

	for(i; i > 0; i--) 
		queue_enqueue(q, queue_dequeue(q));
}
