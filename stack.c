#include "stack.h"

// Função para criar uma stack dado um tamanho. Inicializa-se com uma stack de tamanho 0
Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Point *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack está cheia quando top for igual ao último index
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack está vazia quando top for igual a -1
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Função para adicionar um item à stack. Incrementa top em 1
void push(Stack *stack, Point item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Função para remover um item da stack. Decrementa top em 1
Point pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
}

// Função para pegar o elemento do top da stack
Point top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top];
}

Point nextToTop(Stack *S)
{
    Point p = top(S);
    pop(S);
    Point res = top(S);
    push(S, p);
    return res;
}