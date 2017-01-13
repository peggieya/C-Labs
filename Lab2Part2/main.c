/*
 * File:   main.c
 * Author: zhan2413
 *
 * Created on September 23, 2015, 2:26 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {
    
    //names the constants
    const int TEN=10;
    const int HUNDRED=100;
    const int THOUSAND=1000;
    const int NUMBER_B3_FACTOR=8;
    const int NUMBER_B2_FACTOR=4;
    const int NUMBER_B1_FACTOR=2;
    
    //get the 4-bit binary number from user
    int fourBitNum;
    printf("Enter 4-bit binary number: ");
    scanf("%d", &fourBitNum);
    
    //get B3 from the 4-bit binary number
    int numberB3;
    numberB3=(fourBitNum/THOUSAND);
    
    //get B2 from the 4-bit binary number
    int numberB2;
    numberB2=(fourBitNum/HUNDRED)-(numberB3*TEN);
    
    //get B1 from the 4-bit binary number
    int numberB1;
    numberB1=(fourBitNum/TEN)-(numberB3*HUNDRED)-(numberB2*TEN);
    
    //get B0 from the 4-bit binary number
    int numberB0;
    numberB0=fourBitNum-(numberB3*THOUSAND)-(numberB2*HUNDRED)-(numberB1*TEN);
    
    //calculate the Decimal Value
    int decimalValue;
    decimalValue=(numberB3*NUMBER_B3_FACTOR)+(numberB2*NUMBER_B2_FACTOR)+(numberB1*NUMBER_B1_FACTOR)+numberB0;
    
    //calculate the number that displayed on screen
    int resultNum;
    resultNum=(numberB3*THOUSAND)+(numberB2*HUNDRED)+(numberB1*TEN)+numberB0;
    
    //display the result on the screen
    printf("%d in base 2 is %d in base 10", resultNum, decimalValue);
    
    return (EXIT_SUCCESS);
}
