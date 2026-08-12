#include <stdio.h>
#include<math.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int sum=0,org=num;
    while(num>0){
        sum= sum + pow((num%10),3);
        num=num/10;
    }
    if (org==sum){
        printf("Armstrong number");
    }
    else{
        printf("Not an Armstrong number");
    }
}
