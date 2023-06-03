#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(char* password, int length) {
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    const int numCharacters = sizeof(characters) - 1;
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int randomOffset = rand() % numCharacters;
        password[i] = characters[randomOffset];
    }
    password[length] = '\0';
}

int main() {
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    char* password = (char*)malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generatePassword(password, length);
    printf("Generated Password: %s\n", password);

    free(password);
    return 0;
}
