#include<stdio.h>

int main(){
    int a[100],num,i,key;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&num);
    printf("Enter the elements of the array: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]); 
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    for(i=0;i<num;i++){
        if(a[i]==key){
            printf("Element found at index %d\n",i);
            return 0;  
        }
    }
    printf("Element not found\n");
    return 0;
}