#include<stdio.h>
#include<math.h>

int main() {
     while (1){
        printf("\n Select a function to perform:\n 1. Square Root\n 2. Natural log\n 3. Logarithm (base 10)\n 4. Power\n 5. Cosine\n 6. Exit\n");
        int choice;
        printf("\n Enter your choice (1-6): ");
        scanf("%d", &choice);
        if (choice == 6) {
            printf("\nExiting the program.\n\n");
            break;
        }
        else if (choice < 1 || choice > 6) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        else if (choice==1) {
            double num;
            printf("Enter a number: ");
            scanf("%lf", &num);
            printf("Square Root of %.4f: %.4f\n", num, sqrt(num));
        }
        else if (choice==2) {
            double num;
            printf("Enter a number: ");
            scanf("%lf", &num);
            printf("Natural Log of %.4f: %.4f\n", num, log(num));
        }
        else if (choice==3) {
            double num;
            printf("Enter a number: ");
            scanf("%lf", &num);
            printf("Logarithm (base 10) of %.4f: %.4f\n", num, log10(num));
        }
        else if (choice==4) {
            double base, exponent;
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &base, &exponent);
            printf("%.4f raised to the power %.4f: %.4f\n", base, exponent, pow(base, exponent));
        }
        else if (choice==5) {
            double angle;
            printf("Enter an angle in degrees: ");
            scanf("%lf", &angle);
            printf("Cosine of %.4f degrees: %.4f\n", angle, cos(angle * M_PI / 180));
        }
    }
    return 0;
}