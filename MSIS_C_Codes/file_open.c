#include <stdio.h>

int main() {
    FILE *input, *odd, *even;
    int num;

    input = fopen("numbers.txt", "r");
    odd = fopen("odd.txt", "w");
    even = fopen("even.txt", "w");

    if (input == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(input, "%d", &num) != EOF) {
        if (num % 2 == 0)
            fprintf(even, "%d\n", num);
        else
            fprintf(odd, "%d\n", num);
    }

    printf("Numbers have been written to odd.txt and even.txt successfully.\n");

    fclose(input);
    fclose(odd);
    fclose(even);

    return 0;
}