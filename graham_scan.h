#ifndef GRAHAM_SCAN_H
#define GRAHAM_SCAN_H
#include "point.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

extern Point p0;

int swap(Point *p1, Point *p2);
int distSq(Point p1, Point p2);
int orientation(Point p, Point q, Point r);
int compare(const void *vp1, const void *vp2);
void convexHull(Point points[], int n);
void readPointsFromFile(FILE *fp, Point points[], int numOfPoints);
void startGrahamScan(char *inputFileName);

#endif