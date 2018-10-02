/*  
 * file : stack.c
 * 
 *     
 * Plataforma Alvo : Raspberry Pi
 * Compilador : GCC
 * IDE :  VSCode(editor de texto)
 *  
 * Funcoes relacionadas a Stack, criacao, verifica se esta cheia, se esta vazia, push, pop,
 * verifica se está no topo e o proximo elemento do topo 
 * 
 *  Authors : Jessica Lewinter e Thalys Viana
 *  Copyright (C) 2018 Jessica Lewinter <jessicalewinter@gmail.com>
 *  Copyright (C) 2018 Thalys Viana  <thalysvianaguiar@gmail.com>
 *  Data de Atualizacao : 01 de outubro de 2018
 */


#include "stack.h"

/* Função: Função para criar uma stack dado um tamanho. Inicializa-se com uma stack de tamanho 0
 * 
 * Entrada : capacity -> capacidade de armazenamento da stack
 * Retorno : Stack -> pilha de tamanho da capacity
 * Saída   : Nada
 * Variáveis Locais: stack
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Point *)malloc(stack->capacity * sizeof(int));
    return stack;
}

/* Função: Checa se a stack está cheia
 * 
 * Entrada : stack -> pilha de armazenamento
 * Retorno : Int -> inteiro representando um valor booleano informando e
 *           a stack está cheia ou não
 * Saída   : Nada
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

int isFull(Stack *stack)
{
    // Stack está cheia quando top for igual ao último index
    return stack->top == stack->capacity - 1;
}

/* Função: Checa se a stack está vazia
 * 
 * Entrada : stack -> pilha de armazenamento
 * Retorno : Int -> inteiro representando um valor booleano informando e
 *           a stack está vazia ou não
 * Saída   : Nada
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

int isEmpty(Stack *stack)
{
    // Stack está vazia quando top for igual a -1
    return stack->top == -1;
}

/* Função: Adiciona um item à stack
 * 
 * Entrada : stack -> pilha de armazenamento
 *           item -> item do tipo Point a ser inserido na stack
 * Retorno : Nada
 * Saída   : Nada
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

void push(Stack *stack, Point item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

/* Função: Remove um item da stack
 * 
 * Entrada : stack -> pilha de armazenamento
 * Retorno : Point -> ponto que estava no topo da stack
 * Saída   : Nada
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

Point pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
}

/* Função: Pega o elemento do top da stack
 * 
 * Entrada : stack -> pilha de armazenamento
 * Retorno : Point -> ponto que está no topo da stack
 * Saída   : Nada
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

Point top(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top];
}

/* Função: Encontra o próximo ao topo em uma stack (ponto abaixo de top)
 * 
 * Entrada : stack -> pilha de armazenamento
 * Retorno : Point -> ponto próximo ao topo da stack
 * Saída   : Nada
 * Variáveis Locais: p, res
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

Point nextToTop(Stack *S)
{
    Point p = top(S);
    pop(S);
    Point res = top(S);
    push(S, p);
    return res;
}