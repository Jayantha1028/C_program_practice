#include<stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

for(int i=0; i<cols; i++){
    int sum = 0;
    for (int j=0; j<rows; j++){
        sum += matrix[j][i];
    }
    printf("Sum of column %d: %d\n", i+1, sum);
}
    return 0;
}   