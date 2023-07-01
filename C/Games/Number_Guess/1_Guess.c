#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a colorful banner
void printBanner() {
  printf("=================================================\n");
  printf("==              Number Guessing Game           ==\n");
  printf("=================================================\n");
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

  printBanner();

  do {
    printf("Enter a Guess: ");
    scanf("%d", &Guess);

    if (Guess > answer) {
      printf("\nToo High\n");
    } else if (Guess < answer) {
      printf("\nToo Low\n");
    } else {
      printf("\nCORRECT!\n");
    }
    Guesses++;
  } while (Guess != answer);

  printf("\n");
  printf("==============================================\n");
  printf("Congratulations! You found the correct number!\n");
  printf("==============================================\n");
  printf("\n");
  printf("Answer: %d\n", answer);
  printf("Number of Guesses: %d\n", Guesses);
  printf("\n");

  return 0;
}
