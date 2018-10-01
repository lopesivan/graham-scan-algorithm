#ifndef POINT_H
#define POINT_H

// Estrutura representado os pontos de um plano 2D
struct point
{
    float x, y;
};
typedef struct point Point;

int swap(Point *p1, Point *p2);
int distSq(Point p1, Point p2);
int orientation(Point p, Point q, Point r);
int compare(const void *vp1, const void *vp2);

#endif
