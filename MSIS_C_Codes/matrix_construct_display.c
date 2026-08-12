#include<stdio.h>

int main(){
    int matrix[5][5];
    construct(matrix);
    display(matrix);
    return 0;
}

void construct(int matrix[5][5]){
    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            scanf("%d", &matrix[i][j]);
    }
}

void display(int matrix[5][5]){
    printf("The entered matrix is:\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
