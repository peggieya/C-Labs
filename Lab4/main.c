/*
* File:   Lab4.c
* Author: zhan2413
*
* Created on October 20, 2015, 6:30 PM
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to get the y value (height)
double gaussFunc(double x, double spread) {
    
    double valueofY;
    
    valueofY = exp(-pow(x, 2) / spread);
    
    return (valueofY);
}

int main(int argc, char** argv) {
    
    //reserve space for input variables
    double spread;
    double a;
    double b;
    int n;
    
    //ask user for the variable "spread" and check the condition
    printf("Enter the spread value (must be >0): ");
    scanf("%lf", &spread);
    
    
    while (spread <= 0) {
        printf("Enter the spread value (must be >0): ");
        scanf("%lf", &spread);
    }
    
    //ask user for the variable "n" and check the condition
    printf("Please enter the number of rectangles (n): ");
    scanf("%d", &n);
    
    
    while (n >= 1) {
        
        
        double rectangle;
        double valueofIntegral = 0;
        double k = 0.5;
        double base;
        double height;
        double valueofX;
        double valueofY;
        
        //ask user for the variable "a" and "b" and check the condition
        printf("Enter the interval of integration (a b): ");
        scanf("%lf %lf", &a, &b);
        
        
        while (b < a) {
            
            printf("Invalid interval!\n");
            printf("Enter the interval of integration (a b): ");
            scanf("%lf %lf", &a, &b);
            
        }
        
        //calculate and print out the integral
        while (k < n) {
            
            base = (b - a) / n;
            valueofX = a + (k * ((b - a) / n));
            rectangle = base * gaussFunc(valueofX, spread);
            valueofIntegral = valueofIntegral + rectangle;
            
            k = k + 1;
        }
        printf("Integral of Gaussian with spread %.3f on [%.3f, %.3f] with n = %d is: %.3f", spread, a, b, n, valueofIntegral);
        
        
        //ask user for a new "n" and start the loop again
        printf("\n\nPlease enter the number of rectangles (n): ");
        scanf("%d", &n);
    }
    
    printf("Exiting.");
    
    return (EXIT_SUCCESS);
}
