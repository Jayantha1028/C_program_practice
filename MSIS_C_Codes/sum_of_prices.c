#include <stdio.h>

int main() {
    float price, qty, sum;
    printf("Enter the price of the first item: ");
    scanf("%f", &price);
    printf("Enter the quantity of the first item: ");
    scanf("%f", &qty);
    sum = price * qty;
    printf("\nThe total price is: %f\n", sum);
    if (sum < 1000)
        printf("\nThe discounted price is %.2f\n", sum * 0.95);
    else if (sum >= 1000 && sum < 5000)
        printf("\nThe discounted price is %.2f\n", sum * 0.90);
    else
       printf("\nThe discounted price is %.2f\n", sum * 0.85);
    return 0;
}
