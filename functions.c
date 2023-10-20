#include "functions.h"

/* ********************** Sub-Program Section Start ************* */

void initializeBoard() {  //initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void clearScreen() {//clear the screen

    system("cls");
}

void printBoard() {
    clearScreen();
    printf("                            \n");
    printf("                               Tic-Tac-Toe\n\n");
    printf("                               1 | 2 | 3\n");
    printf("                              ---|---|---\n");
    printf("                               4 | 5 | 6\n");
    printf("                              ---|---|---\n");
    printf("                               7 | 8 | 9\n");
    printf("                            \n");

    // Now, you can also display the current state of the board with 'X' and 'O' symbols.
    printf("                               Current Board\n");
    printf("                               %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("                              ---|---|---\n");
    printf("                               %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("                              ---|---|---\n");
    printf("                               %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("                            \n");
}
void displayLastBoard() {
    printBoard(board);
    // Reset the last board to an empty state
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return -1; // Draw
}


int makeMove(int row,int col,int symbol) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return 0; // Invalid move
    }
    board[row][col] = symbol;
    return 1; // Valid move
}
/*
function aiMove  take nothing and return nothing
used to make AI to enter O in the board ,rend is function in <stdlib.h>  and %3 to set O in board in row and col
1 2 3 randomly
*/
void aiMove() {
   int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    makeMove(row, col, 'O');
}
/*
function playSinglePlayer  take nothing and return nothing
use to play against AI
*/
void playSinglePlayer() {
    int position;
    int moveCount = 0;

    initializeBoard();

    do {
        printBoard();

        if (currentPlayer == 1) {
            int validPosition = 0;
            while (!validPosition) {
                printf("                            Your turn. Enter a position (1-9): ");
                if (scanf("                            %d", &position) != 1) {
                    printf("                            Invalid input. Please enter a number between 1 and 9.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                } else {
                    int row = (position - 1) / 3;
                    int col = (position - 1) % 3;

                    if (position >= 1 && position <= 9 && makeMove(row, col, 'X')) {
                        moveCount++;
                        validPosition = 1;
                    } else {
                        printf("                            Invalid move. Try again.\n");
                    }
                }
            }
        } else {
            aiMove();
            moveCount++;
        }

        int result = checkWin();
        if (result == 1) {
            printBoard();
            if (currentPlayer == 1) {
                printf("                            You win!\n");
            } else {
                printf("                            AI wins!\n");
            }
            break;
        } else if (result == -1) {
            printBoard();
            printf("                            It's a draw!\n");
            break;
        }

        currentPlayer = 3 - currentPlayer;
    } while (moveCount < 9);
}


/*
function playMultiplayer  take nothing and return nothing
use to play against another player
*/
void playMultiplayer() {
    char *player1_name = (char *)malloc(20 * sizeof(char));
    char *player2_name = (char *)malloc(20 * sizeof(char));

    printf("                            Enter the name of Player 1: ");
    scanf("                            %s", player1_name);

    printf("                            Enter the name of Player 2: ");
    scanf("                            %s", player2_name);

    int position;
    int moveCount = 0;

    initializeBoard();

    do {
        printBoard();

        printf("                            %s's turn. Enter a position (1-9): ", (currentPlayer == 1) ? player1_name : player2_name);
        int validPosition = 0;
        while (!validPosition) {
            if (scanf("%d", &position) != 1 || position < 1 || position > 9) {
                printf("                            Invalid input. Enter a number between 1 and 9.\n");
                while (getchar() != '\n'); // Clear the input buffer
            } else {
                int row = (position - 1) / 3;
                int col = (position - 1) % 3;

                if (makeMove(row, col, (currentPlayer == 1) ? 'X' : 'O')) {
                    moveCount++;
                    validPosition = 1;
                } else {
                    printf("                            Invalid move. Try again.\n");
                }
            }
        }

        int result = checkWin();
        if (result == 1) {
            printBoard();
            printf("                            %s wins!\n", (currentPlayer == 1) ? player1_name : player2_name);
            break;
        } else if (result == -1) {
            printBoard();
            printf("                            It's a draw!\n");
            break;
        }

        currentPlayer = 3 - currentPlayer;
    } while (moveCount < 9);
}




char coinToss() {
    return rand() % 2 == 0 ? 'H' : 'T';
}

/* ********************** Sub-Program Section End ************* */

/**
 ******************************************************************************
 User          Date                 Brief
 ******************************************************************************
 ELSAYED MOANIS     19Oct2023            Add  coinToss()
*/
