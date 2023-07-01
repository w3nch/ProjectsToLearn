#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void shuffleOptions(char options[][4][100])
{
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        int j = rand() % 4;
        int k = rand() % 4;
        char temp[100];
        strcpy(temp, options[i][j]);
        strcpy(options[i][j], options[i][k]);
        strcpy(options[i][k], temp);
    }
}

void printBanner()
{
    printf("\033[1;34m"); // Set color to blue
    printf("=================================================\n");
    printf("      🎯  Welcome to the Ultimate Quiz Game! 🎯\n");
    printf("=================================================\n");
    printf("\033[0m"); // Reset color
    printf("\n");
}

void printSummary(int numQuestionsToAnswer, int score)
{
    printf("\n");
    printf("\033[1;34m"); // Set color to blue
    printf("====================================\n");
    printf("           Quiz Summary              \n");
    printf("====================================\n");
    printf("\033[0m"); // Reset color
    printf("\n");
    printf("Total Questions: %d\n", numQuestionsToAnswer);
    printf("Correct Answers: %d\n", score);
}

int main()
{
    char questions[][100] = {
        "1. What year did the C language debut?",
        "2. Who is known as the father of the C language?",
        "3. What is the syntax for a function declaration in C?",
        "4. What does the 'void' keyword indicate in a function declaration?",
        "5. Which operator is used to access the value at a specific memory address?"
    };

    char options[][4][100] = {
        {"A. 1972", "B. 1982", "C. 1990", "D. 2000"},
        {"A. Dennis Ritchie", "B. Ken Thompson", "C. Linus Torvalds", "D. Alan Turing"},
        {"A. int functionName()", "B. void functionName()", "C. functionName() int", "D. functionName() void"},
        {"A. No return value", "B. Pointer to an integer", "C. Pointer to a character", "D. No arguments"},
        {"A. *", "B. &", "C. ->", "D. %"}
    };

    char answers[] = {'A', 'A', 'B', 'D', 'A'};

    int numberofquestions = sizeof(questions) / sizeof(questions[0]);
    int numQuestionsToAnswer;
    char guess;
    int score = 0;

    printf("\033[2J\033[1;1H"); // Clear the screen
    printBanner();

    do
    {
        printf("\033[1;33m"); // Set color to yellow
        printf("How many questions would you like to answer? (1-%d): ", numberofquestions);
        printf("\033[0m"); // Reset color

        if (scanf("%d", &numQuestionsToAnswer) != 1 || numQuestionsToAnswer <= 0 || numQuestionsToAnswer > numberofquestions)
        {
            printf("\033[1;31m"); // Set color to red
            printf("Invalid input! Please enter a number between 1 and %d.\n", numberofquestions);
            printf("\033[0m"); // Reset color
            clearScreen();
            printBanner();
            while (getchar() != '\n')
                continue;
        }
        else
        {
            break;
        }

    } while (1);

    printf("\033[2J\033[1;1H"); // Clear the screen
    printBanner();

    for (int i = 0; i < numQuestionsToAnswer; i++)
    {
        shuffleOptions(options);
        printf("\033[1;33m"); // Set color to yellow
        printf("%s\n", questions[i]);
        printf("\033[0m"); // Reset color

        for (int j = 0; j < 4; j++)
        {
            printf("%s\t", options[i][j]);
        }

        printf("\nEnter your answer (A, B, C, D): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("\033[1;32m"); // Set color to green
            printf("✅ Correct!\n");
            printf("\033[0m"); // Reset color
            score++;
        }
        else
        {
            printf("\033[1;31m"); // Set color to red
            printf("❌ Incorrect!\n");
            printf("\033[0m"); // Reset color
        }

        printf("\n");
        sleep(1);
        clearScreen();
        printBanner();
    }

    printSummary(numQuestionsToAnswer, score);

    return 0;
}
