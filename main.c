#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "error.h"
#include "graham_scan.h"

int main(int argc, char *argv[])
{   
    if (argc != 2) {
        invalidInputError();
    } else {
        startGrahamScan(argv[1]);
    }
    return 0;
}