#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "circular_queue.h"

struct c_queue {
    int *itens;
    int capacity;
    unsigned int start;
    unsigned int end;
};

Circular_Queue *queue_create(int capacity)
{
	Circular_Queue *q = malloc(sizeof(Circular_Queue));
	q->capacity = capacity;
	q->itens = malloc(capacity * sizeof(int));
	q->start = 0;
	q->end = 0;

	return q;
}

int queue_size(Circular_Queue *q)
{
	return q->end >= q->start ? q->end - q->start : q->capacity - q->start + q->end;
}

int is_empty(Circular_Queue *q)
{
	return queue_size(q) == 0;
}

int is_full(Circular_Queue *q)
{
	return queue_size(q) == q->capacity - 1;
}

void queue_enqueue(Circular_Queue *q, int value)
{
	if (is_full(q)) {
		printf("Not able to enqueue %d, The queue is full.\n", value);
		return;
	}

	q->itens[q->end] = value;
	q->end = (q->end + 1) % q->capacity;
}

int queue_dequeue(Circular_Queue *q)
{
	if (is_empty(q)) {
		puts("The queue is empty!");
		return -1;
	}
	
	int value = q->itens[q->start];
	q->start = (q->start + 1) % q->capacity;

	return value;
}

int queue_search_value(Circular_Queue *q, int value)
{
	if (is_empty(q)) {
		printf("Not able to search, Queue is empty.\n");
		return -1;
	}

	unsigned int i;
	for (i = q->start; i != q->end; i = (i + 1) % q->capacity)
		if (q->itens[i] == value) return i;
		
	return -1;
}

void queue_print(Circular_Queue *q)
{
	if (is_empty(q)) {
		puts("The queue is empty!");
		return;
	}

	unsigned int i;
	for (i = q->start; i != q->end; i = (i + 1) % q->capacity)
		printf("[%d]", q->itens[i]);

	puts("");
}

//To be removed and reporpused
void queue_invert(Circular_Queue *q)
{
	
	if (is_empty(q)) {
		printf("Not able to invert, Queue is empty.\n");
		return;
	}

	int size = queue_size(q);

	int i, inversions = size / 2,
	aux, start = q->start, end = q->end - 1;

	for (i = 0; i < inversions; i++){
		aux = q->itens[start];
		q->itens[start] = q->itens[end];
		q->itens[end] = aux;

		start = (start + 1) % q->capacity;
		end = (end - 1) % q->capacity;
	}
}

void queue_destroy(Circular_Queue *q)
{
	if (q != NULL) free(q);
}