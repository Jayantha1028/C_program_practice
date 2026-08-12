#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a,b;
    
    printf("Enter the 2 numbers: \n");
    scanf("%d %d",&a,&b);
    printf("The numbers before swap: %d, %d \n",a,b);
    swap(&a,&b);
    printf("The numbers after swap: %d, %d \n",a,b);
}