#include <stdio.h>

void find_max_min(int a[], int size, int *max, int *min)
{
    int i;
    *max=a[0];
    *min=a[0];
    for (i=1;i<size;i++){
        if (a[i]<*min){
            *min=a[i];
        }
        if (a[i]>*max){
            *max=a[i];
        }
    }
}
    
   int main()
{
    int a[100], num, i, max, min;

    printf("Enter the array size : ");
    scanf("%d", &num);

    printf("Enter the array elements:\n");
    for(i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }

    find_max_min(a, num, &max, &min);

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    return 0;
}