#include <stdio.h>
#include <math.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int sum=0;
    int i=1;
    while(i<=num){
        sum=sum+(pow(10,i)-1)/9;
        i++;
    }
    printf("Sum: %d\n", sum);
    return 0;
}