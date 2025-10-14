#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int **arr;
};

int main() {
    int i, j;
    struct Matrix m;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m.rows, &m.cols);

    m.arr = (int**) malloc(m.rows * sizeof(int*));
    for(i = 0; i < m.rows; i++) {
        m.arr[i] = (int*) malloc(m.cols * sizeof(int));
    }

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < m.rows; i++) {
        for(j = 0; j < m.cols; j++) {
            scanf("%d", &m.arr[i][j]);
        }
    }

    printf("\nMatrix elements:\n");
    for(i = 0; i < m.rows; i++) {
        for(j = 0; j < m.cols; j++) {
            printf("%d ", m.arr[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < m.rows; i++)
        free(m.arr[i]);
    free(m.arr);

    return 0;
}
