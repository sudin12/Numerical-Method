/* Write a program to find the root of the following equation using the False Position method.
					y = x - e-x */

#include <stdio.h>
#include <math.h>

double f(double x) {
    return x - exp(-x);
}

double false_position(double a, double b, double tolerance, int max_iterations); 

int main() {
    double a = 0.0;         
    double b = 1.0;       
    double tolerance = 0.05;
    int max_iterations = 100;

    double root = false_position(a, b, tolerance, max_iterations);
    printf("Root of the equation is: %.10lf\n", root);

    return 0;
}

double false_position(double a, double b, double tolerance, int max_iterations) {
    double fa = f(a);
    double fb = f(b);
    if (fa * fb >= 0) {
        printf("Function has the same sign at points a and b.\n");
        return a;
    }

    double c = a;
    int i;
    for (i = 0; i < max_iterations; i++) {
        c = b - (fb * (a - b)) / (fa - fb);
        double fc = f(c);

        if (fabs(fc) < tolerance) {
            return c;
        }
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    printf("Exceeded maximum iterations. No solution found.\n");
    return c;
}