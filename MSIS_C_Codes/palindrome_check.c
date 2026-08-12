#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int original = num;
    int ans=0;
    while(num>0){
        ans= ans*10 + num%10;
        num=num/10;
    }
    if (ans == original) {
        printf("The number is a palindrome\n");
    } else {
        printf("The number is not a palindrome\n");
    }
    return 0;
}