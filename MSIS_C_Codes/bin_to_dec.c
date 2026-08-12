#include <stdio.h>
#include<math.h>

int main() {
    int num;
    printf("Enter the binary number: ");
    scanf("%d", &num);
    int dec=0,i=0;
    while(num>0){
        dec= dec + (num%10)*pow(2,i);
        i++;
        num=num/10;
    }
    printf("The decimal value is %d",dec);
}