/* Write a program to find the root of the following equation using the Newton Raphson method.
					y = x - e-x  */
					
#include <stdio.h>
#include <math.h>

double f(double x){
	return x - exp(-x);
}

double df(double x){
	return 1 + exp(-x);
}

double newton_raphson(double initial_guess, double tolerance, int max_iteration);

int main(){
	double initial_guess = 0.5;
	double tolerance = 0.05;
	int max_iteration = 100;
	double root = newton_raphson(initial_guess, tolerance, max_iteration);
    printf("Root of the equation is: %lf\n", root);
    return 0;
}

double newton_raphson(double initial_guess, double tolerance, int max_iteration){
	double x = initial_guess;
	int i;
	for(i = 0; i < max_iteration; i++){
		double y = f(x);
		double dy = df(x);
		double h = y / dy;
		double x_new = x - h;
		
		if(fabs(x_new - x) < tolerance){
			return x_new;
		}
		
		x = x_new;
	}
	
	return x;
}
