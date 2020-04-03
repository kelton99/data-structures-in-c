#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct p_queue Priority_Queue;

Priority_Queue *queue_create();

int queue_size(Priority_Queue *q);

int is_empty(Priority_Queue *q);

int is_full(Priority_Queue *q);

void queue_enqueue(Priority_Queue *q, int value);

int queue_dequeue(Priority_Queue *q);

void queue_print(Priority_Queue *q);

void queue_destroy(Priority_Queue *q);

#endif //QUEUE_H