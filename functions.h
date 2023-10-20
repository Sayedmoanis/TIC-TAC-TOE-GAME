#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* ********************** Global Variables Section Start ************** */
char board[3][3];
int currentPlayer = 1;
int singlePlayer = 0;/* ********************** Global Variables  Section End   ************* */

/* ********************** Sub-Program Declerations Section Start ******* */
void initializeBoard();
void clearScreen();
void printBoard();
void displayLastBoard();
int checkWin();
int makeMove(int row,int col,int symbol);
void aiMove();
void playSinglePlayer();
void playMultiplayer();
char coinToss();
/* ********************** Sub-Program Declerations Section End ******* */


#endif // BG_H_INCLUDED
