// C program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX 10000

struct point
{
    long double x, y;
};
typedef struct point Point;

long double distBetweenTwoPoints(Point p1, Point p2) {
    long double result = sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
    return result;
}

long double perimeterOfGivenPoints(Point points[], int n) {
    long double result = 0;
    int i;
    Point reference = points[0];
    for (i = 0; i < n - 1; i++) {
        result += distBetweenTwoPoints(points[i], points[i+1]);
    }
    result += distBetweenTwoPoints(points[n-1], reference);
    return result; 
}

// Um ponto global para ordenar pontos com referência ao primeiro ponto usado na função compare do qsort()
Point p0;

// Uma struct para representar a stack
struct Stack
{
    int top;
    unsigned capacity;
    Point *array;
};
typedef struct Stack Stack;

// Função para criar uma stack dado um tamanho. Inicializa-se com uma stack de tamanho 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Point *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack está cheia quando top for igual ao último index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack está vazia quando top for igual a -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Função para adicionar um item à stack. Incrementa top em 1
void push(struct Stack *stack, Point item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Função para remover um item da stack. Decrementa top em 1
Point pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
}

// Função para pegar o elemento do top da stack
Point top(struct Stack *stack)
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

// Função para realizar o swap entre dois pontos
int swap(Point *p1, Point *p2)
{
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Função para retornar o quadrado da distância entre dois pontos p1 e p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// Para achar a orientação do grupo de três pontos (p, q, r)
// A função retornar os seguintes valores
// 0 --> p, q e r são colineares (colinear)
// 1 --> Sentido horário (clockwise)
// 2 --> Sentido anti-horário (counterclockwise)
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

// Uma função usada pela função de biblioteca qsort() para ordenar
// os pontos com relação ao primeiro ponto
int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Achar orientação
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// Exibe o fecho convexo de um conjunto de n pontos
void convexHull(Point points[], int n)
{
    // Acha o ponto mais baixo
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Pega o ponto mais baixo ou escolhe o
        // ponto mais à esquerda em caso de empate
        if ((y < ymin) || (ymin == y &&
                           points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Põe o ponto mais baixo na primeira posição
    swap(&points[0], &points[min]);
    
    // Ordena os n-1 pontos com relação ao primeiro ponto
    // o ponto p1 vem antes do p2 na saída da ordenação se p2
    // tiver maior ângulo polar (na direção anti-horária) que p1
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Se dois ou mais pontos fizerem o mesmo ângulo com p0
    // remove todos os pontos menos o mais distante de p0
    // Lembrar que, na ordenação acima, o critério escolhido
    // foi o de manter o ponto mais distante no final quando
    // mais de um ponto tiver o mesmo ângulo
    int m = 1; // Initialize size of modified array
    for (int i = 1; i < n; i++)
    {
        // Continua removendo i enquanto o ângulo de i e i+1 for o mesmo
        // com relação à p0 
        while (i < n - 1 && orientation(p0, points[i],
                                        points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++; // Atualiza o tamanho do array modificado
    }

    // Se o array de pontos modificado tiver menos de 3 pontos,
    // não existe a possibilidade de um fecho convexo 
    if (m < 3) {
        printf("There is no convex hull possible.\n");
        return;
    }
        
    // Cria uma stack vazia e dá push nos três primeiros pontos
    struct Stack *stack = createStack(MAX);
    push(stack, points[0]);
    push(stack, points[1]);
    push(stack, points[2]);

    // Processa os restantes n-3 pontos
    for (int i = 3; i < m; i++)
    {   
        // Continua removendo de top enquanto o ângulo formado pelos
        // pontos next-top-top, top e points[i]  fizerem um turno não à esquerda
        while (orientation(nextToTop(stack), top(stack), points[i]) != 2)
            pop(stack);
        push(stack, points[i]);
    }
    
    int pointsLeft = stack->top + 1;
    Point results[pointsLeft];
    int index = 0;

    // Agora a stack tem os pontos de saída, exibe o conteúdo da stack
    printf("\nOutput\n");
    while (!isEmpty(stack))
    {
        Point p = top(stack);
        results[index++] = p;
        //printf("(%.2lf, %.2lf)\n", p.x, p.y);
        pop(stack);
    }

    long double output = perimeterOfGivenPoints(results, pointsLeft);
    printf("%.1Lf\n", output);
}

int main()
{   
    // Geeks for geeks
    // Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
    //                   {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    // Hacker rank
    // Point points[] = { {732, 590}, {415, 360}, {276, 276}, {229, 544},{299, 95}};

    // Code Golf
    //Point points[] = {{1, 1}, {2, 2}, {3, 3}, {1, 3}};
    /* Point points[]  = {{4.4, 14}, {6.7, 15.25}, {6.9, 12.8}, {2.1, 11.1}, {9.5, 14.9}, 
                        {13.2, 11.9}, {10.3, 12.3}, {6.8, 9.5}, {3.3, 7.7}, {0.6, 5.1}, {5.3, 2.4}, 
                        {8.45, 4.7}, {11.5, 9.6}, {13.8, 7.3}, {12.9, 3.1}, {11, 1.1}}; */
    
    int n, i;
    scanf("%d", &n);

    Point points[n];

    int x, y;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        Point p;
        p.x = x;
        p.y = y;
        points[i] = p;
    }

    convexHull(points, n);

    return 0;
}