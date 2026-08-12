#include<stdio.h>

int main(){
    int a[100],num,i,key;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&num);
    printf("Enter the elements of the sorted array: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    int right = num - 1;
    int left = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == key){
            printf("Element found at index %d\n", mid);
            return 0;
        }
        else if(a[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    printf("Element not found\n");
    return 0;
}