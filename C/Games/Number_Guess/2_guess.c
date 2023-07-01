#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print colorful banner with ASCII art
void printBanner() {
  printf("\033[1;33m");
  printf("      .-\"\"\"\"\"-.\n");
  printf("     /          \\\n");
  printf("    |   o    o   |\n");
  printf("    |    '~~'    |\n");
  printf("     \\          /\n");
  printf("      '-......-'\n");
  printf("\033[0m");
  printf("\033[1;36m");
  printf("==  Number Guessing Game  ==\n");
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

  printBanner();

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
