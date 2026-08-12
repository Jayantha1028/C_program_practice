#include <stdio.h>
#include<math.h>

int main() {
    int units;
    printf("Enter the consumption: ");
    scanf("%d", &units);
    if (units>299){
        printf("Amount= %d",1700+(units-300)*10);
    }
    else if (units>199){
        printf("Amount= %d",1000+(units-200)*7);
    } 
    else{
        printf("Amount= %d",(units-200)*5);
    }
}