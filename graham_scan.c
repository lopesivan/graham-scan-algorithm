#include "graham_scan.h"
#include "error.h"
#define MAX 10000

/*Função: Calcula o fecho convexo dado um conjunto de pontos de um plano 2D 
 * 
 * Entrada : points -> array de pontos
 *           n -> número de pontos
 * Retorno : NADA
 * Saída   : Exibe o pontos que formam o fecho convexo. Caso não existe, exibe uma mensagem
 *           informando que não é possível formar um fecho com esses pontos
 * Variáveis Locais: ymin, min, m, i, stack, p
 * Variáveis Globais Usadas : p0
 * Variáveis Globais Alteradas : p0
 */

// Um ponto global para ordenar pontos com referência ao primeiro ponto usado na função compare do qsort()
Point p0;

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

    // Agora a stack tem os pontos de saída, exibe o conteúdo da stack
    printf("Output:\n");
    while (!isEmpty(stack))
    {
        Point p = top(stack);
        printf("(%.2f, %.2f)\n", p.x, p.y);
        pop(stack);
    }
}

// Lê pontos do arquivo
void readPointsFromFile(FILE *fp, Point points[], int numOfPoints) {
    int i;
    for (int i = 0; i < numOfPoints; i++) {
        Point p;
        fscanf(fp, "%f", &p.x);
        fscanf(fp, "%f", &p.y);
        points[i] = p;
    }
}

// Inicializa o algoritmo Graham Scan após leitura das entradas
void startGrahamScan(char *inputFileName) {
    int numOfPoints; // Número de pontos
    FILE *fp;
    fp = fopen(inputFileName, "r");

    if (fp == NULL) {
        nonExistentFileError();
        return;
    }

    fscanf(fp, "%d", &numOfPoints); // Lê o número de pontos do aquivo    
    
    Point points[numOfPoints]; // Define o array de pontos a ser analizado
    readPointsFromFile(fp, points, numOfPoints);
    
    fclose(fp);

    convexHull(points, numOfPoints);
}

