#include <stdio.h>

#define concat(a, b) a##b

int main() {
    printf("%d\n", concat(12, 34));// concat function does not work for varibles, only for literals
    return 0;
}