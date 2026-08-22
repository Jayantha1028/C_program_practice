#include "assignment_snq.h"

int main(){
    assert(ispalindrome(5,"LEVEL")==1);
    assert(ispalindrome(5,"HELLO")==0);

    int32_t mat[5]={10,20,30,40,50};
    int32_t *a=reverse_k_ele(mat,5,3);
    assert(a[0]==30);
    assert(a[2]==10);

    int32_t arr[5]={10,20,30,40,50};
    int32_t *b=reverse_array(arr,5);
    assert(b[0]==50);
    assert(b[2]==30);

    int32_t t[5]={1,2,3,4,5};
    int32_t *s=even_odd_sorting(t,5);
    assert(s[0]==2);
    assert(s[1]==4);
    assert(s[2]==1);
    assert(s[3]==3);
    assert(s[4]==5);
    return 0;
}



/*


void main(){
    int choice;
    while(1){
        printf("...............OPERATIONS...............\n");
        printf("1. Check string Palindrome \n");
        printf("2.Reverse first k elements of an array\n");
        printf("3.Reverse an array\n");
        printf("4.Sort array into even and odd segment\n");
        printf("5. EXIT\n\n");
        printf("Enter op number of the operation to be performed : ");
        scanf("%d",&choice);
        if(choice==1){
            int size;
            printf("Enter the string length : ");
            scanf("%d",&size);
            char str[size+1];
            scanf("%s",str);
            if (ispalindrome(size+1,str))
                printf("%s is a palindrome",str);
            else
                printf("%s is not a palindrome",str);
        }
        else if(choice==2){
            int size;
            printf("Enter the array length : ");
            scanf("%d",&size);
            int32_t arr[size];
            for(int i=0;i<size;i++)
                scanf("%d",&arr[i]);
            int k;
            scanf("%d",&k);
            int32_t *ans= reverse_k_ele(arr,size,k);
        }
        else if(choice==3){
            int size;
            printf("Enter the array length : ");
            scanf("%d",&size);
            int32_t arr[size];
            for(int i=0;i<size;i++)
                scanf("%d",&arr[i]);
            int32_t *ans= reverse_k_ele(arr,size,size);
        }
        else if(choice==4){
            int size;
            printf("Enter the array length : ");
            scanf("%d",&size);
            int32_t arr[size];
            for(int i=0;i<size;i++)
                scanf("%d",&arr[i]);
            int32_t *ans= even_odd_sorting(arr,size);
        }
        else if(choice==5)
            return;
        else
            printf("Wrong choice number\n\n");
    }
}  

*/

