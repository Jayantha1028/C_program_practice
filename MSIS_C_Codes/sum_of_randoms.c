#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, sum;
    srand(time(0));

    num1 = rand() % 10000;
    num2 = rand() % 10000;

    sum = num1 + num2;

    printf("First random number: %d\n", num1);
    printf("Second random number: %d\n", num2);
    printf("Sum: %d\n", sum);

    return 0;
}