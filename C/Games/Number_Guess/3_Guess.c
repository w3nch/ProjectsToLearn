#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to clear the screen
void clearScreen() {
  printf("\033[2J");
  printf("\033[H");
}

// Function to print colorful banner with ASCII art
void printBanner() {
  printf("\033[1;33m");
  printf("   _______ _            ______ _                 _   \n");
  printf("  |__   __| |          |  ____(_)               | |  \n");
  printf("     | |  | |_   _ ___  | |__   _ _ __ ___  _   _| |_ \n");
  printf("     | |  | | | | / __| |  __| | | '_ ` _ \\| | | | __|\n");
  printf("     | |  | | |_| \\__ \\ | |    | | | | | | | |_| | |_ \n");
  printf("     |_|  |_|\\__, |___/ |_|    |_|_| |_| |_|\\__,_|\\__|\n");
  printf("              __/ |                                   \n");
  printf("             |___/                                    \n");
  printf("\033[0m");
  printf("\n");
}

// Function to animate a spinning line
void animateSpinner() {
  const char spinner[] = "-\\|/";
  int i;

  for (i = 0; i < 10; i++) {
    printf("\033[1;36m");
    printf("Loading... %c\r", spinner[i % 4]);
    fflush(stdout);
    usleep(300000);
  }

  printf("\033[0m");
  printf("\n");
}

int main() {
  const int MIN = 1;
  const int MAX = 100;
  int Guess;
  int Guesses = 0;
  int answer;

  srand(time(0));
  answer = (rand() % MAX) + MIN;

  printf("\033[1;35m");
  printf("Welcome to the Number Guessing Game!\n");
  printf("\033[0m");
  printf("\n");

  clearScreen();
  printBanner();

  usleep(1000000);

  clearScreen();

  printf("\033[1;34m");
  printf("Preparing the game");
  fflush(stdout);
  usleep(1000000);

  animateSpinner();

  clearScreen();

  do {
    printf("\033[1;34m");
    printf("Enter a Guess: ");
    scanf("%d", &Guess);
    printf("\033[0m");

    if (Guess > answer) {
      printf("\033[1;31m");
      printf("Too High\n");
      printf("\033[0m");
    } else if (Guess < answer) {
      printf("\033[1;31m");
      printf("Too Low\n");
      printf("\033[0m");
    } else {
      printf("\033[1;32m");
      printf("\nCORRECT!\n");
      printf("\033[0m");
    }
    Guesses++;
  } while (Guess != answer);

  printf("\n");
  printf("\033[1;35m");
  printf("=====================================\n");
  printf("Congratulations! You found the number!\n");
  printf("=====================================\n");
  printf("\033[0m");
  printf("\n");
  printf("\033[1;33m");
  printf("Answer: %d\n", answer);
  printf("Number of Guesses: %d\n", Guesses);
  printf("\033[0m");
  printf("\n");

  return 0;
}
