#include <stdio.h>
#include <stdlib.h>

int main(){
    int *n, *m, *startn, N, M;
    scanf("%d", &N);
    n = malloc (N * sizeof(int));
    
    if (n == NULL){
        printf("Memory Allocation Failed");
        return 1;
    }
    
    startn = n;
    
    while (n - startn < N){
        scanf("%d", n++);
    }
    
    n = startn;
    
    scanf("%d", &M);
    n = realloc(startn, M * sizeof(int));
    
    if(M > N){
        n += N;
        while (n - startn < M){
            scanf("%d", n++);
        }
    }
    
    n = startn;
    
    while (n - startn < M){
        printf("%d ", *n++);
    }
    
    free (startn);
    return 0;
}