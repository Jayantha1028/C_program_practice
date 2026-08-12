#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("2 power of %d is : %d ",num, 1 << num);
    return 0;
}