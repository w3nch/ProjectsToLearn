#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 10

char board[MAX_SIZE][MAX_SIZE];
int BOARD_SIZE;

const char PLAYER = 'X';
const char COMPUTER = 'O';

void initializeBoard();
void printBoard();
int countFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\033[1;36m"); // Set text color to cyan
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---");
            for (int j = 1; j < BOARD_SIZE; j++) {
                printf("+---");
            }
            printf("\n");
        }
    }
    printf("\033[0m"); // Reset text color
}

int countFreeSpaces() {
    int freeSpace = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ')
                freeSpace++;
        }
    }
    return freeSpace;
}

void playerMove() {
    int row, col;
    printf("\033[1;33m"); // Set text color to yellow
    printf("Your turn: Enter the row (1-%d): ", BOARD_SIZE);
    scanf("%d", &row);
    printf("Your turn: Enter the column (1-%d): ", BOARD_SIZE);
    scanf("%d", &col);
    printf("\033[0m"); // Reset text color
    row--; // Convert to 0-based index
    col--;
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ')
        board[row][col] = PLAYER;
    else {
        printf("\033[1;31m"); // Set text color to red
        printf("Invalid move. Try again.\n");
        printf("\033[0m"); // Reset text color
        playerMove();
    }
}

void computerMove() {
    int row, col;
    bool moved = false;

    // Check for any possible winning moves for the computer
    // Check rows
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = COMPUTER;
                if (checkWinner() == COMPUTER) {
                    moved = true;
                    break;
                }
                board[row][col] = ' ';
            }
        }
        if (moved)
            break;
    }

    if (!moved) {
        // Check columns
        for (col = 0; col < BOARD_SIZE; col++) {
            for (row = 0; row < BOARD_SIZE; row++) {
                if (board[row][col] == ' ') {
                    board[row][col] = COMPUTER;
                    if (checkWinner() == COMPUTER) {
                        moved = true;
                        break;
                    }
                    board[row][col] = ' ';
                }
            }
            if (moved)
                break;
        }
    }

    if (!moved) {
        // Check diagonal (top-left to bottom-right)
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][i] == ' ') {
                board[i][i] = COMPUTER;
                if (checkWinner() == COMPUTER) {
                    moved = true;
                    break;
                }
                board[i][i] = ' ';
            }
        }
    }

    if (!moved) {
        // Check diagonal (top-right to bottom-left)
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][BOARD_SIZE - i - 1] == ' ') {
                board[i][BOARD_SIZE - i - 1] = COMPUTER;
                if (checkWinner() == COMPUTER) {
                    moved = true;
                    break;
                }
                board[i][BOARD_SIZE - i - 1] = ' ';
            }
        }
    }

    if (!moved) {
        // Choose a random move
        while (true) {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
            if (board[row][col] == ' ') {
                board[row][col] = COMPUTER;
                break;
            }
        }
    }
}

char checkWinner() {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2] && board[row][0] != ' ')
            return board[row][0];
    }

    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col] && board[0][col] != ' ')
            return board[0][col];
    }

    // Check diagonal (top-left to bottom-right)
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
        return board[0][0];

    // Check diagonal (top-right to bottom-left)
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // Check for a tie
    bool tie = true;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == ' ') {
                tie = false;
                break;
            }
        }
        if (!tie)
            break;
    }
    if (tie)
        return 'T';

    // No winner yet
    return ' ';
}

void printWinner(char winner) {
    usleep(1000000); // Pause for 1 second
    system("clear"); // Clear the terminal
    printf("\033[1;34m"); // Set text color to blue
    printf("\n");
    printf("#############################################\n");
    printf("#                                           #\n");
    printf("#               TIC TAC TOE                 #\n");
    printf("#                                           #\n");
    printf("#############################################\n");
    printf("\n");
    printf("\033[1;35m"); // Set text color to purple
    if (winner == PLAYER) {
        printf("Congratulations! You won!\n");
    } else if (winner == COMPUTER) {
        printf("Computer won! Better luck next time.\n");
    } else {
        printf("It's a tie!\n");
    }
    printf("\033[0m"); // Reset text color
    printf("\n");
}

int main() {
    char restart;
    char size_choice;

    while (true) {
        printf("\033[1;34m"); // Set text color to blue
        printf("\n");
        printf("#############################################\n");
        printf("#                                           #\n");
        printf("#               TIC TAC TOE                 #\n");
        printf("#                                           #\n");
        printf("#############################################\n");
        printf("\n");
        printf("\033[1;37m"); // Set text color to white
        printf("Enter the size of the board (3-%d): ", MAX_SIZE);
        scanf(" %c", &size_choice);

        BOARD_SIZE = size_choice - '0';
        if (BOARD_SIZE < 3 || BOARD_SIZE > MAX_SIZE) {
            printf("\033[1;31m"); // Set text color to red
            printf("Invalid board size. Please try again.\n");
            printf("\033[0m"); // Reset text color
            continue;
        }

        initializeBoard();
        printBoard();

        char currentPlayer = PLAYER;
        char winner = ' ';
        while (winner == ' ') {
            if (currentPlayer == PLAYER)
                playerMove();
            else
                computerMove();

            printBoard();
            winner = checkWinner();
            if (winner == ' ')
                currentPlayer = (currentPlayer == PLAYER) ? COMPUTER : PLAYER;
        }

        printWinner(winner);

        printf("\033[1;33m"); // Set text color to yellow
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &restart);
        printf("\033[0m"); // Reset text color

        if (restart != 'Y' && restart != 'y')
            break;

        system("clear"); // Clear the terminal
    }

    return 0;
}
