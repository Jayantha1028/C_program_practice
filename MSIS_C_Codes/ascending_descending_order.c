#include <stdio.h>

int main() {
    int num,arr[100],i,j,temp;
    
    printf("Enter the length of array : ");
    scanf("%d",&num);
    
    printf("\nEnter the elements of array :\n");
    for(i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    
   for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if (arr[j]<arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
     printf("\nArray in Ascending Order:\n");
    for(i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    
    for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if (arr[j]>arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
     printf("\nArray in Ascending Order:\n");
    for(i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
}