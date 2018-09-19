
// C program for array implementation of stack 
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
struct point {
    int x, y;
};
typedef struct point Point;

// A structure to represent a stack 
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    Point* array; 
}; 

// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (Point*) malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, Point item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
Point pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--]; 
} 
// Driver program to test above functions 
int main() 
{ 
    struct Stack* stack = createStack(100); 
    
    Point p;
    p.x = 7;
    p.y = 4;

    push(stack, p);

    printf("%d\n", stack->array[0].x);
    printf("%d\n", stack->array[0].y);

  
    return 0; 
} 
