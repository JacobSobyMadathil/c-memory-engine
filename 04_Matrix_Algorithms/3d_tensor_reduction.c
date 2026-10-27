#include <stdio.h>

int main(){
    int n, m, p, sum = 0;
    scanf("%d %d %d", &n, &m, &p);
    int A[n][m][p];
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            for (int k = 0; k < p; k ++){
                scanf(" %d", &A[i][j][k]);
            }
        }
    }
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            for (int k = 0; k < p; k ++){
                sum += A[i][j][k];
            }
        }
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}