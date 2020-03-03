#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct c_queue Circular_Queue;

Circular_Queue *queue_create();

void queue_destroy(Circular_Queue *q);

void queue_enqueue(Circular_Queue *q, int value);

int queue_dequeue(Circular_Queue *q);

int queue_size(Circular_Queue *q);

int queue_search_value(Circular_Queue *q, int value);

void queue_print(Circular_Queue *q);

/* To be removed for not being part of the structure itself
* Reimplement later on main using the essential functions (i.e: enqueue, dequeue)
*/
void queue_invert(Circular_Queue *q); 

#endif //QUEUE_H