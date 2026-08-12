#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2;
    int s1 = 0, s2 = 0;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Sum of proper divisors of num1
    s1 = 1;
    for (int i = 2; i <= sqrt(num1); i++) {
        if (num1 % i == 0) {
            s1 += i;
            if (i != num1 / i)
                s1 += num1 / i;
        }
    }

    // Sum of proper divisors of num2
    s2 = 1;
    for (int i = 2; i <= sqrt(num2); i++) {
        if (num2 % i == 0) {
            s2 += i;
            if (i != num2 / i)
                s2 += num2 / i;
        }
    }

    if (s1 == num2 && s2 == num1)
        printf("Amicable Numbers");
    else
        printf("Not Amicable Numbers");

    return 0;
}