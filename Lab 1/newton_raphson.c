#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    return x * x * x - x * x + 2;  // Example function
}

double f_derivative(double x) {
    return 3 * x * x - 2 * x;  // Derivative of the example function
}

void newtonRaphson(double x) {
    double h = f(x) / f_derivative(x);
    while (fabs(h) >= EPSILON) {
        h = f(x) / f_derivative(x);
        x = x - h;
    }
    printf("The value of the root is : %lf\n", x);
}

int main() {
    double x0 = -20;
    newtonRaphson(x0);
    return 0;
}
