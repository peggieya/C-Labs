#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//This variable changes if one player has on valid move
char ifValid = 'B';

//This function checkc how many titles for each colour are on the board
void checkScore(char board[26][26], char computer, char player, int n) {
    
    int playerScore;
    int computerScore;
    int row = 0;
    int col = 0;
    
    for (; row < n; row++) {
        for (; col < n; col++) {
            
            if (board[row][col] == player) {
                playerScore++;
            }
            if (board[row][col] == computer) {
                computerScore++;
            }
        }
    }
    
    if (playerScore >= computerScore)
        printf("%c player wins.", player);
    
    if (computerScore > playerScore)
        printf("%c player wins.", computer);
    
}

//This function checks if one move is on the board
bool positionInBounds(int N, char row, char col) {
    
    if (row - 'a' < N && row - 'a' >= 0 && col - 'a' < N && col - 'a' >= 0) {
        return true;
    }
    return false;
}

//This function checks if a certain direction is valid to make a move
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
                return true;
        }
    }
    return false;
}

//This function flip the opposite color in two color
void flipTitle(char board[26][26], char row, char col, char colour, int n) {
    
    int deltaRow;
    int deltaCol;
    
    int x;
    int y;
    
    char opponent;
    if (colour == 'W')
        opponent = 'B';
    else
        opponent = 'W';
    
    for (deltaRow = -1; deltaRow < 2; deltaRow++) {
        for (deltaCol = -1; deltaCol < 2; deltaCol++) {
            if ((deltaRow != 0) || (deltaCol != 0)) {
                if (checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)) {
                    
                    x=row-'a';
                    y=col-'a';
                    
                    x += deltaRow;
                    y += deltaCol;
                    
                    while (board[x][y] == opponent) {
                        
                        board[x][y] = colour;
                        x += deltaRow;
                        y += deltaCol;
                    }
                }
            }
        }
    }
}

//This function  print a new board according to n
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

//This function print the board in current condition
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

//This function checks if there are valid move for a color
bool validMove(char board[26][26], int n, char colour) {
    
    int deltaRow = -1;
    int deltaCol = -1;
    
    char row = 'a';
    char col = 'a';
    
    for (row = 'a'; row < 'a' + n; row++) {
        for (col = 'a'; col < 'a' + n; col++) {
            for (deltaRow = -1; deltaRow < 2; deltaRow++) {
                for (deltaCol = -1; deltaCol < 2; deltaCol++) {
                    if ((deltaRow != 0) || (deltaCol != 0)) {
                        if (checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

//Check the score for one direction
int getOneCounter(char board[26][26], int n, char row, char col, int deltaRow, int deltaCol, char computer) {
    
    int counter = 0;
    int i = row - 'a';
    int j = col - 'a';
    
    char player;
    if (computer == 'W')
        player = 'B';
    else
        player = 'W';
    
    if (checkLegalInDirection(board, n, row, col, computer, deltaRow, deltaCol)) {
        i += deltaRow;
        j += deltaCol;
        counter++;
        
        while (board[i][j] == player) {
            
            i += deltaRow;
            j += deltaCol;
            counter++;
        }
        return counter;
    }
    return 0;
}

//Sum the score for eight directions
int getCounter(char board[26][26], int n, char row, char col, char computer) {
    int counter = 0;
    counter += getOneCounter(board, n, row, col, 1, 1, computer)
    + getOneCounter(board, n, row, col, 1, 0, computer) + getOneCounter(board, n, row, col, 1, -1, computer);
    +getOneCounter(board, n, row, col, 0, 1, computer)
    + getOneCounter(board, n, row, col, 0, -1, computer)
    + getOneCounter(board, n, row, col, -1, 1, computer)
    + getOneCounter(board, n, row, col, -1, 0, computer)
    + getOneCounter(board, n, row, col, -1, -1, computer);
    return counter;
}

//Find the best move for computer and make a move
void computerBestMove(char board[26][26], int n, char computer) {
    
    struct computerMove {
        int counter;
        char bestrow;
        char bestcol;
    } bestMove;
    
    bestMove.counter = 0;
    
    int deltaRow;
    int deltaCol;
    
    
    char player;
    if (computer == 'W')
        player = 'B';
    else
        player = 'W';
    
    char row;
    char col;
    int currentScore = 0;
    
    
    for (row = 'a'; row < 'a' + n; row++) {
        for (col = 'a'; col < 'a' + n; col++) {
            if (board[row - 'a'][col - 'a'] == 'U') {
                
                if (getCounter(board, n, row, col, computer) > (bestMove.counter)) {
                    bestMove.counter = getCounter(board, n, row, col, computer);
                    bestMove.bestrow = row;
                    bestMove.bestcol = col;
                }
            }
        }
    }
    
    printf("\nComputer places %c at %c%c.\n", computer, bestMove.bestrow, bestMove.bestcol);
    int bestRow = (bestMove.bestrow) - 'a';
    int bestCol = (bestMove.bestcol) - 'a';
    
    board[bestRow][bestCol] = computer;
    
    flipTitle(board, bestMove.bestrow, bestMove.bestcol, computer, n);
    
    printBoard(board, n);
}

//Ask player to move a move and check if it is valid
//If it is not a valid move, get out of the program
void playerMakeMove(char board[26][26], char computer, int n) {
    
    char rowEnter;
    char colEnter;
    
    
    if (computer == 'W') {
        char player = 'B';
        printf("\nEnter move for colour B (RowCol) : ");
        scanf(" %c%c", &rowEnter, &colEnter);
        
        //check if it is a valid move for color B
        if ((checkLegalInDirection(board, n, rowEnter, colEnter, player, -1, -1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, -1, 0) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, -1, 1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 0, -1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 0, 1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 1, -1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 1, 0) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 1, 1)) == false) {
            
            printf("Invalid move.\n");
            ifValid = 'R';
            return; //If the move id invalid, get back to main function
        }
        board[rowEnter - 'a'][colEnter - 'a'] = 'B';
        
        flipTitle(board, rowEnter, colEnter, player, n);
        
        printBoard(board, n);
        
    } else if (computer == 'B') {
        
        char player = 'W';
        printf("\nEnter move for colour W (RowCol) : ");
        scanf(" %c%c", &rowEnter, &colEnter);
        
        //check if it is a valid move for color W
        if ((checkLegalInDirection(board, n, rowEnter, colEnter, player, -1, -1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, -1, 0) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, -1, 1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 0, -1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 0, 1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 1, -1) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 1, 0) ||
             checkLegalInDirection(board, n, rowEnter, colEnter, player, 1, 1)) == false) {
            
            printf("Invalid move.\n");
            ifValid = 'R';
            return; //If the move id invalid, get back to main function
        }
        
        board[rowEnter - 'a'][colEnter - 'a'] = 'W';
        
        flipTitle(board, rowEnter, colEnter, player, n);
        
        printBoard(board, n);
    }
}

int main(int argc, char** argv) {
    
    struct computerMove {
        int score;
        char row;
        char col;
    } bestMove;
    
    int n;
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    
    char computer;
    char player;
    
    printf("Computer plays (B/W) : ");
    scanf(" %c", &computer);
    
    if (computer == 'W') {
        player = 'B';
    }
    if (computer == 'B') {
        player = 'W';
    }
    
    char board[26][26];
    newBoard(board, n);
    printBoard(board, n);
    
    char rowEnter;
    char colEnter;
    
    if (player == 'B') {
        playerMakeMove(board, computer, n);
        
        if (ifValid == 'R') {
            
            printf("\n%c player wins.", computer);
            return (EXIT_SUCCESS);
        }
        
        computerBestMove(board, n, computer);
        
        //Check if both player have valid place to make a move
        while ((validMove(board, n, player)) && (validMove(board, n, computer))) {
            playerMakeMove(board, computer, n);
            
            if (ifValid == 'R') {
                
                printf("\n%c player wins.", computer);
                return (EXIT_SUCCESS);
            }
            computerBestMove(board, n, computer);
        }
        
        //If not both player can make move, check who can move
        //This function is under the condition that computer can move
        while ((validMove(board, n, player) == false) && (validMove(board, n, computer == true))) {
            
            printf("\n%c player has no valid move.", player);
            computerBestMove(board, n, computer);
        }
        
        //If not both player can make move, check who can move
        //This function is under the condition that player can move
        while ((validMove(board, n, player) == true) && (validMove(board, n, computer == false))) {
            
            printf("\n%c player has no valid move.", computer);
            playerMakeMove(board, computer, n);
            
            if (ifValid == 'R') {
                
                printf("\n%c player wins.", computer);
                return (EXIT_SUCCESS);
            }
            
            int playerScore;
            int computerScore;
        }
    }
    if (player == 'W') {
        
        computerBestMove(board, n, computer);
        playerMakeMove(board, computer, n);
        if (ifValid == 'R') {
            printf("\n%c player wins.", computer);
            return (EXIT_SUCCESS);
        }
        
        while (validMove(board, n, player) && validMove(board, n, computer)) {
            computerBestMove(board, n, computer);
            playerMakeMove(board, computer, n);
            
            if (ifValid == 'R') {
                printf("\n%c player wins.", computer);
                return (EXIT_SUCCESS);
                
            }
            
            while ((validMove(board, n, player) == false) && (validMove(board, n, computer == true))) {
                
                printf("\n%c player has no valid move.", player);
                computerBestMove(board, n, computer);
            }
            
            while ((validMove(board, n, player) == true) && (validMove(board, n, computer == false))) {
                
                printf("\n%c player has no valid move.", computer);                
                playerMakeMove(board, computer, n);
                
                if (ifValid == 'R') {
                    printf("\n%c player wins", computer);
                    return (EXIT_SUCCESS);
                }
            }
        }
    }
    
    checkScore(board, computer, player, n);
    return (EXIT_SUCCESS);
}
