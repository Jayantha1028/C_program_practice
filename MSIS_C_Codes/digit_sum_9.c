#include <stdio.h>

int main() {
    int num=9,i=1;
    printf("The two digit numbers who digit sum is %d are:\n",num);
    for(i=1;i<=num;i++){
        printf("%d ",i*10+(num-i));
    }
}