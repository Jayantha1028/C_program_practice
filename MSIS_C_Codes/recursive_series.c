#include <stdio.h>

float series(float x, int count, int n, float term)
{
    if (count >= n)
        return 0;

    term = term * x * x / ((2 * count + 1) * (2 * count));
    return (term + series(x, count + 1, n, term));
}

int main()
{
    float x;
    int n;
    printf("Enter the value of x: ");
    scanf("%f", &x);
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("The sum of the series is: %f\n", x + series(x, 1, n , x));
    return 0;
}