#include <stdio.h>
#include <string.h>

int main()
{
    char s[100],ans[100];
    printf("Enter the string :\n");
    scanf("%s",s);
    int n=strlen(s), i=0;
    while(n>0){
        ans[i]=s[n-1];
        n--;
        i++;
    }
    ans[i] = '\0'; 
    printf("\n Reverse of the string is : %s", &ans);
}