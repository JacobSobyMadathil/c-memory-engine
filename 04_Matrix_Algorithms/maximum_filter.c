#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int m, int n)
{
    int **matrix = malloc (m * sizeof(int *));
    for (int i = 0; i < m; i ++){
        *(matrix + i) = malloc (n * sizeof(int));
        if (*(matrix + i) == NULL){
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(int **a, int m)
{
    for (int i = 0; i < m; i ++){
        free(*(a + i));
    }
    free (a);
}

void maximum_filter(int **A, int **B, int m, int n)
{
    int max;
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++){
            max = A[i][j];
            if (i < m - 1 && A[i + 1][j] > max){
                max = A[i + 1][j];
            }
            if (j < n - 1 && A[i][j + 1] > max){
                max = A[i][j + 1];
            }
            if (i > 0 && A[i - 1][j] > max){
                max = A[i - 1][j];
            }
            if (j > 0 && A[i][j - 1] > max){
                max = A[i][j - 1];
            }
            if (i < m - 1 && j < n - 1 && A[i + 1][j + 1] > max){
                max = A[i + 1][j + 1];
            }
            if (i < m - 1 && j > 0 && A[i + 1][j - 1] > max){
                max = A[i + 1][j - 1];
            }
            if (i > 0 && j < n - 1 && A[i - 1][j + 1] > max){
                max = A[i - 1][j + 1];
            }
            if (i > 0 && j > 0 && A[i - 1][j - 1] > max){
                max = A[i - 1][j - 1];
            }
            B[i][j] = max;
        }
    }
}

int main(void)
{
    int m, n, k, **A, **B;
    scanf("%d %d %d", &m, &n, &k);
    A = allocate_matrix (m, n);
    B = allocate_matrix (m, n);
    if (A == NULL){
        printf("Matrix Allocation failed");
        return 1;
    }
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++){
            scanf(" %d", &A[i][j]);
        }
    }
    if (k == 0){
        for (int i = 0; i < m; i ++){
            for (int j = 0; j < n; j ++){
                if (j != n - 1){
                    printf("%d ", A[i][j]);
                }
                else{
                    printf("%d", A[i][j]);
                }
            }
            if (i != m - 1){
                printf("\n");
            }
        }
        return 0;
    }
    for (int i = 0; i < k; i ++){
        maximum_filter (A, B, m, n);
        for (int j = 0; j < m; j ++){
            for (int l = 0; l < n; l ++){
                A[j][l] = B[j][l];
            }
        }
    }
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++){
            if (j != n - 1){
                printf("%d ", A[i][j]);
            }
            else{
                printf("%d", A[i][j]);
            }
        }
        if (i != m - 1){
            printf("\n");
        }
    }
    free_matrix (A, m);
    return 0;
}