#include <stdio.h>

void main() {
    float cel;
    printf("Enter the temperature in Celsius :");
    scanf("%f",&cel);
    printf("The temperature in Fahrenheit is %.2f", 32 + (cel*9/5));
}