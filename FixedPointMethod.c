/* Write a program to find the root of the following equation using the Fixed Point method.
					y = x - e-x */
					
#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(-x);
}

double fixed_point(double initial_guess, double tolerance, int max_iterations);

int main() {
    double initial_guess = 0.5;
    double tolerance = 1e-7;
    int max_iterations = 100;
    
    double root = fixed_point(initial_guess, tolerance, max_iterations);
    printf("Root of the equation is: %.10lf\n", root);
    
    return 0;
}


double fixed_point(double initial_guess, double tolerance, int max_iterations) {
    double x_prev = initial_guess;
    double x_next;
    int i;
    
    for (i = 0; i < max_iterations; i++) {
        x_next = f(x_prev);
        if (fabs(x_next - x_prev) < tolerance) {
            return x_next;
        }
        x_prev = x_next;
    }
    
    printf("Exceeded maximum iterations. No solution found.\n");
    return x_next;
}
