#include <stdio.h>

int main() {
    int num,row=1,count=0;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("The star pattern is:\n");
    while(row<=num){
        if (count<row){
            printf("* ");
            count++;
        }
        else{
            count=0;
            printf("\n");
            row++;
        }
    }
}