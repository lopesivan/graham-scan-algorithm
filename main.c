// C program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "graham_scan.h"

#define MAX 10000

int main(int argc, char *argv[])
{   
    if (argc != 2) {
        invalidInputError();
    } else {
        startGrahamScan(argv[1]);
    }

    return 0;
}