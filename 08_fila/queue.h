#ifndef QUEUE_H
#define QUEUE_H

typedef struct _element Element;
typedef struct _queue Queue;

void freeQueue(Queue* queue);
int isEmpty(Queue* queue);
void showLast(Queue* queue);
void showFirst(Queue* queue);
void showQueue(Queue* queue);
int dequeue(Queue* queue);
void enqueue(Queue* queue, int value);
Queue* newQueue();

#endif