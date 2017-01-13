/*
* File:   main.c
* Author: zhan2413
*
* Created on October 7, 2015, 12:36 PM
*/

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {
    //get a seed from the user
    unsigned int seed;
    int guessNumber;
    
    printf("Enter seed: ");
    scanf("%d", &seed);
    
    //ask user to input a number
    printf("Guess a number from 1 to 7 (<=0 to quit): ");
    scanf("%u", &guessNumber);
    
    srand(seed);
    
    //put the number into while loop
    while (guessNumber > 0) {
        if (guessNumber >= 1 && guessNumber <= 7) { //check if the input number meet the conditions
            int numberPicked = rand() % 7 + 1; //generate a random number
            printf("Number picked: %d\n", numberPicked);
            
            if (numberPicked == guessNumber) //compare the random number with the input number
                printf("Good guess!\n"); //display that random number equal to the input number
            else
                printf("Sorry, try again!\n"); //display that random number not equal the input number
            
        }
        if (guessNumber > 7) { //condition for the input number
            printf("Number too high, guess again!\n"); //display the condition to the user
        }
        printf("Guess a number from 1 to 7 (<=0 to quit): "); //ask user for another input number to start another loop
        scanf("%u", &guessNumber);
        
    }
    
    
    
    printf("Goodbye"); //display when the user input a number<0 in order to quit
    
    return (EXIT_SUCCESS);
}
