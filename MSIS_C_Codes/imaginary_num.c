#include<stdio.h>

struct Complex {
    float real;
    float imag;
};

int main() {
    struct Complex num1,num2, ans, prod,diff;
    printf("\nEnter the real and imaginary parts of the first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);
    printf("\nEnter the real and imaginary parts of the second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    ans.real = num1.real + num2.real;
    ans.imag = num1.imag + num2.imag;
    printf("\nThe sum of the complex numbers is: %.2f + %.2fi\n", ans.real, ans.imag);

    diff.real = num1.real - num2.real;
    diff.imag = num1.imag - num2.imag;
    printf("\nThe difference of the complex numbers is: %.2f + %.2fi\n", diff.real, diff.imag);

    prod.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    prod.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    printf("\nThe product of the complex numbers is: %.2f + %.2fi\n", prod.real, prod.imag);

    return 0;
}