#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    return x * x * x - x * x + 2;  // Example function
}

void secant(double x0, double x1) {
    double x2;
    while (fabs(x1 - x0) >= EPSILON) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }
    printf("The value of the root is : %lf\n", x2);
}

int main() {
    double x0 = -200, x1 = 300;
    secant(x0, x1);
    return 0;
}
