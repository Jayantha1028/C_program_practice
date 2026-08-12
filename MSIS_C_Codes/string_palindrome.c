#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    printf("Enter the string :\n");
    scanf("%s",s);
    int n=strlen(s), i=0;
    int pal=1,k=n/2;
    while(n>k){
        if (s[i]!=s[n-1]){
            pal=0;
            break;
        }
        n--;
        i++;
    }
    if (pal==1)
        printf("\nPalindrome");
    else
        printf("\nNot a Palindrome");
    return 0;
}