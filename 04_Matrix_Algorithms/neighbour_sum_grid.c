#include <stdio.h>
#include <stdlib.h>

void add(int **a, int **b, int m, int n){
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++){
            b[i][j] += a[i][j];
            if (i > 0){
                b[i][j] += a[i - 1][j];
            }
            if (j > 0){
                b[i][j] += a[i][j - 1];
            }
            if (i < m - 1){
                b[i][j] += a[i + 1][j];
            }
            if (j < n - 1){
                b[i][j] += a[i][j + 1];
            }
        }
    }
}

int main(){
    int m, n, **a, **starta, **b, **startb;
    scanf(" %d %d", &m, &n);
    a = malloc (m * sizeof(int *));
    starta = a;
    for (int i = 0; i < m; i ++){
         *a = malloc (n * sizeof(int));
         a ++;
    }
    a = starta;
    
    b = malloc (m * sizeof(int *));
    startb = b;
    for (int i = 0; i < m; i ++){
        *b = calloc (n, sizeof(int));
        b ++;
    }
    b = startb;
    
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++){
            scanf("%d", &(a[i][j]));
        }
    }
    
    add (a, b, m, n);
    
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++){
            printf("%d ", (b[i][j]));
        }
        printf("\n");
    }
    
    free (starta);
    free (startb);
    return 0;
}