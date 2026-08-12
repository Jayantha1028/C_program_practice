#include <stdio.h>

int main() {
    int num,a=0,b=0,c=1,i;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("The fibinocci series is:\n");
    for(i=0;i<num;i++){
        printf("%d ",a);
        c=a+b+c;
        b=c-a-b;
        a=c-a-b;
    }
}