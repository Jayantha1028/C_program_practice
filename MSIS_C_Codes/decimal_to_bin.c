#include <stdio.h>
#include<math.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int bin=0,i=0;
    while(num>0){
        bin= bin + (num%2)*pow(10,i);
        i++;
        num=num/2;
    }
    printf("The binary value is %d",bin);
}