#ifndef STACK_H
#define STACK_H

typedef struct _element Element;
typedef struct _stack Stack;

void freeStack(Stack* p);
int isEmpty(Stack* p);
void showFirst(Stack* p);
void showStack(Stack* p);
int pop(Stack* p);
void push(Stack* p, int n);
Stack* newStack();

#endif