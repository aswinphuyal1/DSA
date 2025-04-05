#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    return x * x * x - x * x + 2;  // Example function
}

void bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("You have not assumed right a and b\n");
        return;
    }

    double c = a;
    while ((b - a) >= EPSILON) {
        c = (a + b) / 2;

        if (f(c) == 0.0)
            break;

        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("The value of root is : %lf\n", c);
}

int main() {
    double a = -200, b = 300;
    bisection(a, b);
    return 0;
}
