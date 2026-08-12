#include <stdio.h>

int main() {
    char input;

    printf("Enter a single character or a digit (0-9): ");
    scanf(" %c", &input);

    // Direct comparison using ASCII values
    if (input >= '0' && input <= '9') {
        printf("The input '%c' is an integer.\n", input);
    } else {
        printf("The input '%c' is a character.\n", input);
    }

    return 0;
}
