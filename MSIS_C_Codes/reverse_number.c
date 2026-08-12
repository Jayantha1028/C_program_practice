#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int ans=0;
    while(num>0){
        ans= ans*10 + num%10;
        num=num/10;
    }
    printf("The sum is : %d", ans);
    return 0;
}