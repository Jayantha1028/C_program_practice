#include <stdio.h>

int main() {
    int num,i,j;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("The star pattern is:\n");
    for(i=num;i>0;i--){
        for(j=i;j>0;j--){
        printf("* ");
    }
    printf("\n");
    }
}