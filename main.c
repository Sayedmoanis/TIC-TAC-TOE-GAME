/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ELSAYED MOANIS
 * @brief          : Contains the functionality of my application
 ******************************************************************************
 */

 /* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"


/* ********************** Includes Section End   ********************** */





int main() {
    system("cls");
    printf(" \033[1;32m  \n");

    int choice;
    int playAgain;

    printf("                            Welcome to Tic-Tac-Toe!\n                      ");

    do {
        printf(" \033[1;32m  \n");

        initializeBoard(); // Reset the board for a new game

        char coinResult = coinToss();
        if (coinResult == 'H') {
            printf("                            Player 1 (Heads) starts first!\n");
            currentPlayer = 1;
        } else {
            printf("                            Player 2 (Tails) starts first!\n");
            currentPlayer = 2;
        }

        int validChoice = 0;
        while (!validChoice) {
            printf("                            Select the mode:\n");
            printf("                            1. Multiplayer\n");
            printf("                            2. Single Player\n");
            if (scanf("                            %d", &choice) != 1 || (choice != 1 && choice != 2)) {
                printf("                            Invalid input. Please enter 1 for Single Player or 2 for Multiplayer.\n");
                while (getchar() != '\n'); // Clear the input buffer
            } else {
                validChoice = 1;
            }
        }

        if (choice == 2) {
            singlePlayer = 1;
        } else if (choice == 1) {
            singlePlayer = 0; // Reset singlePlayer for multiplayer
        }

        if (singlePlayer) {
            playSinglePlayer();
        } else {
            playMultiplayer();
        }

        printf("                            Do you want to play again? (1 for yes, 0 for no): ");
        scanf("                            %d", &playAgain);
        displayLastBoard(); // Display the last board and reset it
        system("cls");
        printf(" \033[1;32m  \033[1;0m \n");
    } while (playAgain);

    return 0;
}


