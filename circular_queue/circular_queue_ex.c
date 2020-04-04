#include <stdlib.h>
#include <stdio.h>
#include "circular_queue.h"

// Terrible way to clean the console window, using only for the sake of simplicity
#ifdef _WIN32
	void clear_console() { system("cls"); }
#else
	void clear_console() { system("clear"); }
#endif

enum options {OPT_EXIT, OPT_ENQUEUE, OPT_DEQUEUE, OPT_REMOVE, OPT_PRINT_E, OPT_PRINT_NE, OPT_INVERT};

int get_int_input(int *value);
int get_menu_input(void);
void print_queue(Circular_Queue *q);
void enqueue(Circular_Queue *q);
void dequeue(Circular_Queue *q);
void remove_element(Circular_Queue *q);
void load_dataset(Circular_Queue *q);
void print_empty(Circular_Queue * q);
void print_not_empty(Circular_Queue * q);
void invert(Circular_Queue *q);

int main(void)
{
	Circular_Queue *q = queue_create(20);
	load_dataset(q);
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
			case OPT_PRINT_E:
    				print_empty(q);
    				break;
			case OPT_PRINT_NE:
    				print_not_empty(q);
    				break;
			case OPT_INVERT:
    				invert(q);
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
	puts("Options Menu:\n[0] exit\n[1] enqueue\n[2] dequeue\n[3] remove\n[4] print empty\n[5] print without empty");
	puts("[6] invert");
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
	int j;
	for(j = 0; queue_front(q) != n; i--, j++){
		queue_enqueue(q, queue_dequeue(q));
		if(j == queue_size(q) - 1) return;
	}
	
	queue_dequeue(q);

	for(; i > 0; i--) 
		queue_enqueue(q, queue_dequeue(q));
}

void invert(Circular_Queue *q)
{
	int size = queue_size(q) - 1;
	int arr[size];
	for (int i = 0; !is_empty(q); i++)
		arr[i] = queue_dequeue(q);
	
	for (int i = size; i >= 0; i--)
		queue_enqueue(q, arr[i]);
	
}

void load_dataset(Circular_Queue *q)
{
	int i = 0;
	while (!is_full(q)){
		queue_enqueue(q, i);
		i++;
	} 
}