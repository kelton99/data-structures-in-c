#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct c_queue Circular_Queue;

Circular_Queue *queue_create();

int queue_size(Circular_Queue *q);

int is_empty(Circular_Queue *q);

int is_full(Circular_Queue *q);

int queue_size(Circular_Queue *q);

int queue_front_position(Circular_Queue *q);

int queue_front(Circular_Queue *q);

void queue_enqueue(Circular_Queue *q, int value);

int queue_dequeue(Circular_Queue *q);

void queue_print(Circular_Queue *q);

void queue_destroy(Circular_Queue *q);

#endif //QUEUE_H