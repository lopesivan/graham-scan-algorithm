#ifndef STACK_H
#define STACK_H
#include "point.h"
#include <stdlib.h>

// Uma struct para representar a stack
struct Stack
{
    int top;
    unsigned capacity;
    Point *array;
};
typedef struct Stack Stack;

Stack *createStack(unsigned capacity);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, Point item);
Point pop(Stack *stack);
Point top(Stack *stack);
Point nextToTop(Stack *S);

#endif