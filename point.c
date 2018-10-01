#include "point.h"
#include "graham_scan.h"

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