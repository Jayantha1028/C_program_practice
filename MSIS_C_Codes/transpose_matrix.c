#include<stdio.h>

int main(){
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    int mat[rows][rows];
    printf("Enter the elements of the matrix:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("The original matrix is:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    int trans[rows][rows];
    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
            trans[j][i] = mat[i][j];
        }
    }
    printf("The transposed matrix is:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}