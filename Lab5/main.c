/*
 * File:   Lab5.c
 * Author: zhan2413
 *
 * Created on October 28, 2015, 7:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*reverse space in memory for the array DNA*/
const char DNA[] = {'A', 'G', 'C', 'G', 'G', 'G', 'A', 'C', 'C', 'G', 'T', 'C',
    'C', 'C', 'G', 'A', 'C', 'A', 'T', 'T', 'G', 'A', 'T', 'G',
    'A', 'A', 'G', 'G', 'G', 'T', 'C', 'A', 'T', 'A', 'G', 'A',
    'C', 'C', 'C', 'A', 'A', 'T', 'A', 'C', 'G', 'C', 'C', 'A',
    'C', 'C', 'A', 'C', 'C', 'C', 'C', 'A', 'A', 'G', 'T', 'T',
    'T', 'T', 'C', 'C', 'T', 'G', 'T', 'G', 'T', 'C', 'T', 'T',
    'C', 'C', 'A', 'T', 'T', 'G', 'A', 'G', 'T', 'A', 'G', 'A',
    'T', 'T', 'G', 'A', 'C', 'A', 'C', 'T', 'C', 'C', 'C', 'A',
    'G', 'A', 'T', 'G', '\0'};

/*the function to get the sequence from input and check the condition*/
int getSequence(char sequence[], int *len) {
    int length;
    const int TRUE = 1;
    
    //ask user to input the data
    printf("Enter length of DNA sequence to match: ");
    scanf("%d", &length);
    if (length <= 0) {
        return 0;
    }
    printf("Enter %d characters (one of AGTC*) as a search sequence: ", length);
    *len = length;
    
    scanf("%s", sequence);
    
    int i = 0;
    while ((i < length) && (TRUE)) {
        
        //check if there are input character that is not ACGT*
        if ((sequence[i] != 'A') && (sequence[i] != 'G') &&
            (sequence[i] != 'C') && (sequence[i] != 'T') && (sequence[i] != '*')) {
            printf("Erroneous character input '%c' exiting\n", sequence[i]);
            return 0;
        }
        i++;
    }
    
    return 1;
}


/*find the matched array and display the first index*/
void findMatch(char sequence[], int length) {
    
    bool Match = false;
    
    for (int i = 0; DNA[i] != '\0'; i++) {
        if ((sequence[0] == '*') || (DNA[i] == sequence[0])) {
            Match = true;
            int j = i + 1;
            int k = 1;
            
            while ((k < length) && (Match)) {
                if (sequence[k] == '*')
                    Match = true;
                
                else if (DNA[j] != sequence[k])
                    Match = false;
                
                else Match = true;
                
                j++;
                k++;
            }
            
            if (Match && i<=(100-length))
                printf("Match of search sequence found at element %d\n", i);
        }
    }
}


int main(int argc, const char * argv[]) {
    int len;
    char searchSequence[100];
    
    while (getSequence(searchSequence, &len)) {
        findMatch(searchSequence, len);
    }
    
    printf("Goodbye\n");
    return 0;
}
