#include <stdio.h>
#include <stdlib.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+ - * /): ");
    scanf(" %c", &operator);

    printf("Enter number 1: ");
    scanf("%lf", &num1);

    printf("Enter number 2: ");
    scanf("%lf", &num2);

    result = (operator == '+') ? (num1 + num2)
             : (operator == '-') ? (num1 - num2)
             : (operator == '*') ? (num1 * num2)
             : (operator == '/') ? (num1 / num2)
                                 : printf("Invalid operator.\n");

    printf("The result is %.2lf.\n", result);

    return 0;
}
