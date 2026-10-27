#include <stdio.h>
#include <stdlib.h>

int *insert (int *arr, int *n, int pos, int value){
    int *temp = arr;
    arr = realloc (temp, ((*n) + 1) * sizeof(int));
    for (int i = *n; i > pos; i --){
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + pos) = value;
    return arr;
}
int *delete (int *arr, int *n, int pos){
    int *temp = arr;
    for (int i = pos; i < *n; i ++){
        *(arr + i) = *(arr + i + 1);
    }
    arr = realloc (temp, ((*n) - 1) * sizeof(int));
    return arr;
}

int main (){
    int *n, *arr, posI, value, posD;
    n = malloc (sizeof(int));
    scanf("%d", n);
    arr = malloc ((*n) * sizeof(int));
    for (int i = 0; i < *n; i ++){
        scanf("%d", arr + i);
    }
    scanf("%d %d", &posI, &value);
    scanf("%d", &posD);
    printf("After Insertion:\n");
    arr = insert (arr, n, posI, value);
    for (int i = 0; i < (*n) + 1; i ++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
    printf("After Deletion:\n");
    arr = delete (arr, n, posD);
    for (int i = 0; i < (*n); i ++){
        printf("%d ", *(arr + i));
    }
    return 0;
}