#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "priority_queue.h"

struct p_queue {
	int *itens;
	int capacity;
	int size;
};

Priority_Queue *queue_create(int capacity)
{
	Priority_Queue *q = malloc(sizeof(Priority_Queue));
	q->itens = malloc(capacity * sizeof(int));
	q->capacity = capacity + 1;
	return q;
}

int queue_size(Priority_Queue *q)
{
	
}

int is_empty(Priority_Queue *q)
{
	return q->size == 0;
}

int is_full(Priority_Queue *q)
{
	return q->size == q->capacity;
}

void swap(Priority_Queue *q, int i, int j)
{
	int temp = q->itens[i];
	q->itens[i] = q->itens[j];
	q->itens[j] = temp;
}

void correct_up(Priority_Queue *q)
{
	int i = q->size;
	while (i >= 2 && q->itens[i/2] < q->itens[i]){
		swap(q, i/2, i);
		i /= 2;
	}
}

void correct_down(Priority_Queue *q)
{
	int i = 1;
	while (2 * i <= q->size){
		int j = 2 * i;
		if(j < q->size && q->itens[j] < q->itens[j + 1])
			j++;

		if(q->itens[i] >= q->itens[j]) {
			i = q->size;
		} else {
			swap(q, i, j);
			i = j;
		}
	}
}

void queue_enqueue(Priority_Queue *q, int value)
{
	if (is_full(q)) {
		printf("Not able to enqueue %d, The queue is full.\n", value);
		return;
	}
	q->size++;
	q->itens[q->size] = value;
	correct_heap(q);
}

int queue_dequeue(Priority_Queue *q)
{
	if (is_empty(q)) {
		puts("The queue is empty!");
		return -1;
	}
	int max = q->itens[1];
	q->itens[1] = q->itens[q->size];
	q->size--;
	correct_down(q);
	return max;
}

int queue_capacity(Priority_Queue *q)
{
	return q->capacity;
}

void queue_print(Priority_Queue *q)
{
	if (is_empty(q)) {
		puts("The queue is empty!");
		return;
	}
	for (int i = 0; i < q->size; i++)
		printf("[%d]", q->itens[i]);
	
	puts("");
}

void queue_destroy(Priority_Queue *q)
{
	if (q != NULL) free(q);
}