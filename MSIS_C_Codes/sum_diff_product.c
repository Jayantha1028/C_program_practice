#include <stdio.h>
#include<stdlib.h>

int main() {
    int num1,num2;
    printf("Enter the numbers: ");
    scanf("%d %d", &num1,&num2);
    printf(" The sum is %d\n The difference is %d\n The product is %d",num1+num2,abs(num1-num2),num1*num2);
}