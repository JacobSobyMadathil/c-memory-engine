#include <stdio.h>
#include <stdlib.h>

struct Entry
{
    char name[31];
    char email[51];
};

int main(){
    int N;
    struct Entry *arr, *start;
    scanf("%d", &N);
    arr = malloc (N * sizeof(struct Entry));
    if (arr == NULL){
        return 1;
    }
    start = arr;
    for (int i = 0; i < N; i ++){
        scanf("%s", ((arr + i) -> name));
        scanf("%s", ((arr + i) -> email));
    }
    arr = realloc(start, (N + 1) * sizeof(struct Entry));
    if (arr == NULL){
        return 1;
    }
    
    scanf("%s", ((arr + N) -> name));
    scanf("%s", ((arr + N) -> email));
    
    for (int i = 0; i < N + 1; i ++){
        printf("%s: ", (arr + i) -> name);
        printf("%s ", (arr + i) -> email);
    }
    free (arr);
    
    
    return 0;
}
