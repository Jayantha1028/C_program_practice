#include <stdio.h>

int main() {
    int yr;

    printf("Enter the year: ");
    scanf("%d", &yr);

    // Leap year logic: divisible by 400 OR (divisible by 4 AND not divisible by 100)
    if ((yr % 400 == 0) || (yr % 4 == 0 && yr % 100 != 0)) {
        printf("The year is a leap year\n");
    } else {
        printf("The year is not a leap year\n");
    }

    return 0;
}
