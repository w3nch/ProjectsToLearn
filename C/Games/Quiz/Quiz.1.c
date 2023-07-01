
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

    printf("====================================\n");
    printf("       Welcome to the Quiz Game      \n");
    printf("====================================\n\n");

    do
    {
        printf("How many questions would you like to answer? (1-%d): ", numberofquestions);
        if (scanf("%d", &numQuestionsToAnswer) != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            clearScreen();
        }
        while (getchar() != '\n');  // Clear input buffer
    } while (numQuestionsToAnswer < 1 || numQuestionsToAnswer > numberofquestions);

    clearScreen();
    printf("====================================\n");
    printf("             Quiz Game               \n");
    printf("====================================\n\n");

    shuffleOptions(options);

    for (int i = 0; i < numQuestionsToAnswer; i++)
    {
        printf("%s\n", questions[i]);

        for (int j = 0; j < 4; j++)
        {
            printf("%s\n", options[i][j]);
        }

        printf("Enter your answer (A, B, C, or D): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("✅ Correct!\n");
            score++;
        }
        else
        {
            printf("❌ Incorrect!\n");
        }

        printf("\n");
        sleep(1);
        clearScreen();
    }

    printf("====================================\n");
    printf("           Quiz Summary              \n");
    printf("====================================\n\n");

    printf("Total Questions: %d\n", numQuestionsToAnswer);
    printf("Correct Answers: %d\n", score);

    return 0;
}
