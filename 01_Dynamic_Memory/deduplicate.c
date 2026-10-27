#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, count = 1, nextVal;
    int *p, *start, *q;
    scanf("%d", &N);
    
    p = calloc(N, sizeof(int));
    
    if (p == NULL){
        printf("No Memory Allocated");
        return 1;
    }
    
    start = p;
    q = p + 1;
    
    while (p - start < N){
        scanf("%d", &(*p++));
    }
    
    p = start;
    
    while(q - start < N){
        if(*q != *p){
            p ++;
            *p = *q;
            count ++;
        }
        q ++;
    }
    
    p = start;
    
    printf("%d\n", count);
    
    for (int i = 0; i < count; i ++){
        printf("%d ", (*p++));
    }
    
    free (start);
    return 0;
}
