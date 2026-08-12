#include <stdio.h>

int main()
{
    char a[100],b[100],ans[200];
    printf("Enter the string :\n");
    scanf("%s",a);
    printf("\nEnter the 2nd string :\n");
    scanf("%s", b);
    int i=0,j=0;
    while(a[i]!='\0'){
        ans[i]=a[i];
        i++;
        }
    while(b[j]!='\0'){
        ans[i]=b[j];
        i++;
        j++;
        }
    ans[i]='\0';
    printf("\n The Concatenated string is %s",ans);
    return 0;
}