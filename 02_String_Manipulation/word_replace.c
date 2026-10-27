#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **findFirst(char **words, int n, char *target){
	char **firstOccurrence;
    for (int i = 0; i < n; i ++){
        if (strcmp(*(words + i), target) == 0){
            firstOccurrence = words + i;
            return firstOccurrence;
        }
    }
    return NULL;
}

int replace(char **words, int n, char *target1, char *target2){
    char **p = findFirst(words, n, target1);
    if (findFirst(words, n, target1) == NULL){
        strcpy(*(words + n), target2);
        return n + 1;
    }
    else{
        strcpy(*(p), target2);
        return n;
    }
}

int main()
{
    int n, newlen;
    char **words, *target1, *target2;
    scanf("%d", &n);
    words = malloc(20 * sizeof(char *));
    target1 = malloc(31 * sizeof(char));
    target2 = malloc(31 * sizeof(char));
    
    if (words == NULL){
        printf("Memory Allocation failed");
        return 1;
    }
    if (target1 == NULL){
        printf("Memory Allocation failed");
        return 1;
    }
    if (target2 == NULL){
        printf("Memory Allocation failed");
        return 1;
    }
    
    for (int i = 0; i < 20; i ++){
        *(words + i) = malloc(31 * sizeof(char));
        if (*(words + i) == NULL){
            printf("Memory Allocation failed");
            return 1;
        }
    }
    
    for (int i = 0; i < n; i ++){
        scanf("%30s", *(words + i));
    }
    
    scanf("%30s", target1);
    scanf("%30s", target2);
    
    newlen = replace (words, n, target1, target2);
    
    printf("%d %d\n", n, newlen);
    for (int i = 0; i < newlen; i ++){
        printf("%s ", *(words + i));
    }
    free(words);
    free (target1);
    free (target2);
    return 0;
}