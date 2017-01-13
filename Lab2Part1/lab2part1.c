/*
 * File:   main.c
 * Author: zhan2413
 *
 * Created on September 21, 2015, 11:52 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {
    
    /* get the patient age */
    double ageofPatient;
    printf("Enter patient age: ");
    scanf("%lf",&ageofPatient);
    
    /* get the doctors’ estimate */
    double doctorEstimate;
    printf("Enter doctor %% likelihood guess of heart failure: ");
    scanf("%lf",&doctorEstimate);
    
    /* get the  amount of BNTP */
    int amountofBNPT;
    printf("Enter patient BNPT value (between 0 and 1000 pg/ml): ");
    scanf("%d",&amountofBNPT);
    
    /* names constant */
    const double DOCTOR_ESTIMATE_FACTOR=1.5;
    const double AMOUNT_OF_BNTP_FACTOR=125;
    const int AGE_OF_PATIENT_FACTOR=10;
    const int AMOUNT_OF_BNTP_MULTIPLAIER=20;
    
    /* calculates the likelihood */
    double valueofLikelihood;
    valueofLikelihood=(doctorEstimate/DOCTOR_ESTIMATE_FACTOR)+(ageofPatient/AGE_OF_PATIENT_FACTOR)+(amountofBNPT/AMOUNT_OF_BNTP_FACTOR)*AMOUNT_OF_BNTP_MULTIPLAIER;
    
    /* display the result of likelihood */
    printf("Computed likelihood of heart failure is %.1f%%",valueofLikelihood);
    
    
    return (EXIT_SUCCESS);
}
