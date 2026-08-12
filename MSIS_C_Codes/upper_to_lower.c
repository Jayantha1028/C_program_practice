#include <stdio.h>

int main() {
    char upper[100];
    char lower[100];
    printf("Enter an uppercase letter: ");
    scanf("%s", upper);
    convertToLowercase(upper);
    return 0;  
}

void convertToLowercase(char upper[]) {
    char  lower[100];
    for (int i = 0; upper[i] != '\0'; i++) {
        if (upper[i] >= 'A' && upper[i] <= 'Z') {
            lower[i] = upper[i] + 32;
        } else {
            lower[i] = upper[i];
        }
    }
    printf("Lowercase letter: %s\n", lower);
}