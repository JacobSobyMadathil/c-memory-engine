#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int N, *arr, *start, *min, *max;
    scanf("%d", &N);
    arr = malloc(N * sizeof(int));
    start = arr;
    for (int i = 0; i < N; i ++){
        scanf("%d", (arr + i));
    }
    min = arr;
    max = arr;
    for (int i = 0; i < N; i ++){
        if (*min > *(arr + i)){
            min = (arr + i);
        }
        if (*max < *(arr + i)){
            max = (arr + i);
        }
    }
    
    swap (min, max);
    printf("%d %d %d\n", *max, *min, (*min) - (*max));
    for (int i = 0; i < N; i ++){
        printf("%d ", *(arr + i));
    }
    free (start);
    return 0;
}