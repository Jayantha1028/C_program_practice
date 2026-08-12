#include <stdio.h>

int main() {
    int num;
    printf("Enter a five digit number: ");
    scanf("%d",&num);
    int i=0;
    int sum=0;
    while(i<5){
        sum= sum+ num%10;
        num=num/10;
        i++;
    }
    printf("The sum is : %d", sum);
    return 0;
}