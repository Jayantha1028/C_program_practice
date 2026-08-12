#include <stdio.h>

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int i=3,c=1;
    printf("The first %d prime numbers are :\n2\n",num);
    for (i=3;c<num;i++){
        int j=2,end=i/2+1,isprime=1;
        while(j<=end){
            if (i%j==0){
                isprime=0;
                break;
            }
            j++;
        }
        if (isprime==1){
           printf("%d\n", i);
           c++;
        }
    }
}