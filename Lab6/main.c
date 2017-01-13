/*
 * File:   Lab6.c
 * Author: zhan2413
 *
 * Created on November 3, 2015, 7:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *
 */

//This function display a new board when the dimension is given
void newBoard(char board[26][26], int n) {
    
    int row, col;
    
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            board[row][col] = 'U';
        }
    }
    //filp the four center element to W/B
    board[n / 2 - 1][n / 2 - 1] = 'W';
    board[n / 2 - 1][n / 2] = 'B';
    board[n / 2][n / 2 - 1] = 'B';
    board[n / 2][n / 2] = 'W';
    
}

//This function display the newest board
void printBoard(char board[26][26], int n) {
    
    int row, col;
    printf("  ");
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%c", 'a' + i);
    }
    
    int j = 0;
    
    for (row = 0; row < n; row++, j++) {
        printf("\n");
        printf("%c ", 'a' + j);
        
        for (col = 0; col < n; col++) {
            printf("%c", board[row][col]);
        }
    }
}

//This function checks if the position is in bounds
bool positionInBounds(int N, char row, char col) {
    
    if (row - 'a' < N && row - 'a' >= 0 && col - 'a' < N && col - 'a' >= 0) {
        return true;
    }
    return false;
}

//This function checks is a direction legal for a move
bool checkLegalInDirection(char board[26][26], int N, char row, char col, char colour, int deltaRow, int deltaCol) {
    
    char opponent;
    if (colour == 'W')
        opponent = 'B';
    else
        opponent = 'W';
    bool valid = false;
    if (positionInBounds(N, row, col)) {
        row += deltaRow;
        col += deltaCol;
        
        while (board[row - 'a'][col - 'a'] == opponent) {
            
            row += deltaRow;
            col += deltaCol;
            
            
            if ((board[row - 'a'][col - 'a'] == colour))
                valid = true;
            if (valid)
                
                return true;
        }
    }
    return false;
}

//This function ask for configuration and flip
void funcConfig(char board[26][26]) {
    
    char colour;
    char row;
    char col;
    printf("\nEnter board configuration:\n");
    
    do {
        scanf(" %c%c%c", &colour, &row, &col);
        
        int row1 = row - 'a';
        int col1 = col - 'a';
        board[row1][col1] = colour;
    } while (colour != '!' && row != '!' && col != '!');
}

//This function find and display available moves for W and B
void availableMove(char board[26][26], int n) {
    
    char row = 'a';
    char col = 'a';
    char colour;
    int deltaRow;
    int deltaCol;
    
    bool validMove = false;
    
    //find available move for W
    colour = 'W';
    printf("\nAvailable moves for W:\n");
    for (row = 'a'; row < 'a' + n; row++) {
        for (col = 'a'; col < 'a' + n; col++) {
            
            if (board[row - 'a'][col - 'a'] == 'U') {
                
                if (validMove = checkLegalInDirection(board, n, row, col, colour, -1, -1)) {
                    printf("%c%c\n", row, col);
                }
                
                if (validMove = checkLegalInDirection(board, n, row, col, colour, -1, 0)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, -1, 1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 0, -1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 0, 1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 1, -1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 1, 0)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 1, 1)) {
                    printf("%c%c\n", row, col);
                }
            }
        }
    }
    
    //find available move for B
    colour = 'B';
    printf("Available moves for B:\n");
    for (row = 'a'; row < 'a' + n; row++) {
        for (col = 'a'; col < 'a' + n; col++) {
            
            if (board[row - 'a'][col - 'a'] == 'U') {
                
                if (validMove = checkLegalInDirection(board, n, row, col, colour, -1, -1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, -1, 0)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, -1, 1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 0, -1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 0, 1)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 1, -1)) {
                    printf("%c%c\n", row, col);
                }
                
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 1, 0)) {
                    printf("%c%c\n", row, col);
                }
                if (validMove = checkLegalInDirection(board, n, row, col, colour, 1, 1)) {
                    printf("%c%c\n", row, col);
                }
            }
        }
    }
    char colourEnter;
    char rowEnter;
    char colEnter;
    
    printf("Enter a move:\n");
    scanf(" %c %c %c", &colourEnter, &rowEnter, &colEnter);
    
    //check is the move valid for W
    if (colourEnter == 'W') {
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, -1) ||
            checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 0) ||
            checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 1) ||
            checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, -1) ||
            checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, 1) ||
            checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, -1) ||
            checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 0) ||
            checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 1)){
            
        }
        
        printf("Valid move.\n");
        
        //flip the title if it is a valid move
        
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, -1)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[(rowEnter - 1) - 'a'][(colEnter - 1) - 'a'] = colourEnter;
        }
        
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 0)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[(rowEnter - 1) - 'a'][colEnter - 'a'] = colourEnter;
        }
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 1)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[(rowEnter - 1) - 'a'][(colEnter + 1) - 'a'] = colourEnter;
        }
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, -1)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[rowEnter - 'a'][(colEnter - 1) - 'a'] = colourEnter;
        }
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, 1)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[rowEnter - 'a'][(colEnter + 1) - 'a'] = colourEnter;
        }
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, -1)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[(rowEnter + 1) - 'a'][(colEnter - 1) - 'a'] = colourEnter;
        }
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 0)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[(rowEnter + 1) - 'a'][colEnter - 'a'] = colourEnter;
        }
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 1)) {
            board[rowEnter - 'a'][colEnter - 'a'] = 'W';
            board[(rowEnter + 1) - 'a'][(colEnter + 1) - 'a'] = colourEnter;
        }
    }
    
    
    //check is the move valid for W
    else if (colourEnter == 'B') {
        if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, -1) ||
            (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 0)) ||
            (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 1)) ||
            (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, -1)) ||
            (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, 1)) ||
            (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, -1)) ||
            (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 0)) ||
            (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 1))) {
            
            printf("Valid move.\n");
            
            //flip the title if it is a valid move
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, -1)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[(rowEnter - 1) - 'a'][(colEnter - 1) - 'a'] = colourEnter;
            }
            
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 0)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[(rowEnter - 1) - 'a'][colEnter - 'a'] = colourEnter;
            }
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, -1, 1)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[(rowEnter - 1) - 'a'][(colEnter + 1) - 'a'] = colourEnter;
            }
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, -1)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[rowEnter - 'a'][(colEnter - 1) - 'a'] = colourEnter;
            }
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 0, 1)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[rowEnter - 'a'][(colEnter + 1) - 'a'] = colourEnter;
            }
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, -1)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[(rowEnter + 1) - 'a'][(colEnter - 1) - 'a'] = colourEnter;
            }
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 0)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[(rowEnter + 1) - 'a'][colEnter - 'a'] = colourEnter;
            }
            if (checkLegalInDirection(board, n, rowEnter, colEnter, colourEnter, 1, 1)) {
                board[rowEnter - 'a'][colEnter - 'a'] = 'B';
                board[(rowEnter + 1) - 'a'][(colEnter + 1) - 'a'] = colourEnter;
            }
        }
        else
            printf("Invalid move.\n");
    }
    
}


int main(int argc, char** argv) {
    int n;
    //ask the user for the dimension of the board
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    
    //display the new board according to the dimension
    char board[26][26];
    newBoard(board, n);
    printBoard(board, n);
    
    //ask user input configuration and flip the title
    funcConfig(board);
    printBoard(board, n);
    
    //ask user for a move and check if it is valid
    //if it is valid, flip the title and display the new board
    //if it id invalid, display the old board
    availableMove(board, n);
    printBoard(board, n);
    
    return (EXIT_SUCCESS);
}
