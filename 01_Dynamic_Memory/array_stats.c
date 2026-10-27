#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, sum = 0, min, max;
    int *p, *start;
    scanf("%d", &N);
    p = malloc(N * sizeof(int));
    start = p;
    while (p - start < N){
        scanf("%d", &(*p++));
    }
    
    p = start;
    
    while (p - start < N){
        sum += *p++;
    }
    
    p = start;
    
    min = *p;
    max = *p;
    
    while (p - start < N){
        if (min > *p){
            min = *p;
        }
        if (max < *p){
            max = *p;
        }
        p++;
    }
    
    printf("Sum: %d\nMinimum: %d\nMaximum: %d\nAverage: %.2f", sum, min, max, sum/(float)N);
    
    free (start);
    return 0;
}
