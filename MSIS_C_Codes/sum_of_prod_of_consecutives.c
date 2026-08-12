#include <stdio.h>
    
   int main()
{
    int num, prev, pres, i;
    int ans=0;

    printf("Enter the array size : ");
    scanf("%d", &num);

    printf("Enter the array elements:\n");
    scanf("%d", &prev);
    for(i = 1; i < num; i++){
        scanf("%d", &pres);
        ans= ans+ prev*pres;
        prev=pres;
    }

    printf("\nOutput = %d\n", ans);

    return 0;
}