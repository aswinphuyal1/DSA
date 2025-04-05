#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double g(double x) {
    return sqrt((x + 2) / 3);  // Example function for fixed point iteration
}

void fixedPoint(double x0) {
    double x1;
    while (1) {
        x1 = g(x0);
        if (fabs(x1 - x0) < EPSILON)
            break;
        x0 = x1;
    }
    printf("The value of the root is : %lf\n", x1);
}


int main() {
    double x0 = -20;
    fixedPoint(x0);
    return 0;
}
