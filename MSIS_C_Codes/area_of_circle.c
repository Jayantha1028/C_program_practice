#include <stdio.h>

void main() {
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    float pi=3.14;
    float area = pi * radius * radius;
    printf("Area of the circle: %.2f\n", area);
}