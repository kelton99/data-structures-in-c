#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "circular_queue.h"

struct c_queue {
	int *itens;
	int capacity;
	int size;
	int start;
	int end;
};

Circular_Queue *queue_create(int capacity)
{
	Circular_Queue *q = malloc(sizeof(Circular_Queue));
	q->capacity = capacity;
	q->itens = malloc(capacity * sizeof(int));
	q->size = 0;
	q->start = -1;
	q->end = -1;

	return q;
}

int queue_size(Circular_Queue *q)
{
	return q->size;
}

int queue_front_position(Circular_Queue *q)
{
	return q->start;
}

int queue_front(Circular_Queue *q)
{
	return q->itens[q->start];
}

int is_empty(Circular_Queue *q)
{
	return q->start == -1;
}

int is_full(Circular_Queue *q)
{
	return (q->end + 1) % q->capacity == q->start;
}

void queue_enqueue(Circular_Queue *q, int value)
{
	if (is_full(q)) {
		printf("Not able to enqueue %d, The queue is full.\n", value);
		return;
	}

	if (q->start == -1) q->start = 0;

	q->end = (q->end + 1) % q->capacity;
	q->itens[q->end] = value;
	q->size++;
}

int queue_dequeue(Circular_Queue *q)
{
	if (is_empty(q)) {
		puts("The queue is empty!");
		return -1;
	}
	int e = q->itens[q->start];
	
	if(q->start == q->end)
		q->start = q->end = -1;
	else
		q->start = (q->start+1) % q->capacity;
	
	q->size--;

	return e;
}


void queue_print(Circular_Queue *q)
{
	if (is_empty(q)) {
		puts("The queue is empty!");
		return;
	}

	int i;
	int ind = q->start;
	for (i = 0; i < q->size; i++){
		printf("[%d]", q->itens[ind]);
		ind = (ind + 1) % q->capacity;
	}

	puts("");
}

void queue_destroy(Circular_Queue *q)
{
	if (q != NULL) free(q);
}