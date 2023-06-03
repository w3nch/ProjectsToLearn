
#include <stdio.h>

void printBanner() {
    printf("                                                                \n");
    printf("88b           d88                       88                      \n");
    printf("888b         d888                ,d     88                      \n");
    printf("88`8b       d8'88                88     88                      \n");
    printf("88 `8b     d8' 88  ,adPPYYba,  MM88MMM  88,dPPYba,   ,adPPYba,  \n");
    printf("88  `8b   d8'  88  \"\"    `Y8   88     88P'    \"8a  I8    \"\"  \n");
    printf("88   `8b d8'   88  ,adPPPPP88    88     88       88   `\"Y8ba,   \n");
    printf("88    `888'    88  88,    ,88    88,    88       88  aa   8I  \n");
    printf("88     `8'     88  `\"8bbdP\"Y8   \"Y888  88       88  `\"YbbdP\"'  \n");
}

int main() {
    printBanner();

    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nEnter the radius of a circle:\t");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    printf("Circumference: %lf\n", circumference);
    printf("Area: %lf\n", area);

    return 0;
}
