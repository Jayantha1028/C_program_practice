#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int ans[10] = {0}; 
    
    while(num > 0){
        ans[num % 10]++;
        num = num / 10;
    }
    
    for(int i = 0; i < 10; i++){ 
        printf(" %d : %d\n", i, ans[i]);
    }
    return 0;
}
