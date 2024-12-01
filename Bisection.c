	/* Write a program to find the root of the following equation using the Bisection method.
	y = x - e-x */
	#include <stdio.h>
	#include <math.h>
	
	double function(double x){
		return x - exp(-x);
	}
	
	
	int main(){
		double xu =5;
		double xl = 0;
	
		
		double ansXu = function(xu);
		double ansXl = function(xl);
		
		printf("Value for xu = %lf ", ansXu);
		printf("\n Value for xl = %lf", ansXl);
		
		double sum = xl + xu;
		double xm = sum / 2;
		
		double ansXm = function(xm);
		printf("\n Value of xm = %lf", xm);
		
		printf("\n Value of f(xm) = %lf", ansXm);
		
		if(ansXm < 0){
			xl = xm;
		} else{
			xu = xm;
		}
		
		printf("Xu = %lf", xu);
		printf("Xl = %lf", xl);
		double error;
		double xmold;
	
			do{
			xmold = xm;
			sum = xl + xu;
	    	xm = sum / 2;
	    	ansXm = function(xm);
		
		    if(ansXm < 0){
				xl = xm;
			} else{
				xu = xm;
			}
		
			error = (xm - xmold) / xm;
			printf("\n Xm = %lf", xm);
			printf("\n Error = %lf", error);
			error = abs(error);
		} while(error > 0.05 ); 
	
		return 0;
		
	}