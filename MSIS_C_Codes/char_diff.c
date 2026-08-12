#include <stdio.h>
#include <stdlib.h>

int main() {
    char a, b;
    
    printf("Enter a character: ");
    scanf("%c", &a); 

    printf("Enter second character: ");
    scanf(" %c", &b);

    if (a >= 'A' && a <= 'Z') {
        a = a + 32;
    }
    if (b >= 'A' && b <= 'Z') {
        b = b + 32;
    }
    
    printf("Diff between characters is: %c,%c, %d\n", a, b, abs(a - b));
    return 0;
}
