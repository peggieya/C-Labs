/*
 * File:   main.c
 * Author: zhan2413
 *
 * Created on October 7, 2015, 12:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {
    
    //get the two numbers and the calculation command  from user
    double firstNumber, secondNumber;
    char inChar;
    
    printf("Enter first number: ");
    scanf("%lf", &firstNumber);
    
    printf("Enter second number: ");
    scanf("%lf", &secondNumber);
    
    printf("Enter calculation command (one of a, s, m, or d): ");
    scanf(" %c", &inChar);
    
    //calculate the result
    double sum;
    double difference;
    double product;
    double division;
    
    sum=firstNumber+secondNumber;
    difference=firstNumber-secondNumber;
    product=firstNumber*secondNumber;
    division=firstNumber/secondNumber;
    
    //decide which result to use according to the calculation command and display the result
    if (inChar=='a')
    {
        printf("Sum of %.2f and %.2f is %.2f", firstNumber,secondNumber,sum);
    }
    else if (inChar=='s')
    {
        printf("Difference of %.2f from %.2f is %.2f", firstNumber,secondNumber,difference);
    }
    else if (inChar=='m')
    {
        printf("Product of %.2f and %.2f is %.2f", firstNumber,secondNumber,product);
    }
    else if (inChar=='d')
    {
        if (secondNumber==0)
            printf("Error, trying to divide by zero");
        
        else
            printf("Division of %.2f by %.2f is %.2f", firstNumber,secondNumber,division);
    }
    else if (inChar!='a' && inChar!='s' && inChar!='m' && inChar!='d')
    {
        printf("Error, unknown calculation command given");
    }
    
    
    return (EXIT_SUCCESS);
}
