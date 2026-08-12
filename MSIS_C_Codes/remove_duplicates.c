#include <stdio.h>

int main() {
    int a[10],i,j,k,l=10;
    for(i=0;i<10;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<l;i++){
        for(j=i+1;j<l;j++){
            if(a[i]==a[j]){
                for(k=j;k<l-1;k++){
                    a[k]=a[k+1];
                }
                l--;
                j--;
            }
        }
    }
    a[l] = '\0';
    printf("Array after removing duplicates: ");
    for(i=0;i<l;i++){
        printf("%d ",a[i]);
    }
    return 0;
}