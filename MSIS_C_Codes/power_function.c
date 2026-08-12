#include <stdio.h>

double power(int val,int expo){
    if (expo == 0)
        return 1;
    return val * power(val,expo-1);
}

int main() {
    int base,exponent;
    printf("Enter the base value and exponent : ");
    scanf("%d %d",&base, &exponent);
    printf("\n %d to the power of %d is %.2lf",base,exponent,power(base,exponent));
    return 0;
}