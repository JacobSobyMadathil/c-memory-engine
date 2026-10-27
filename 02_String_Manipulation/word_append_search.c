#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDS 20
#define MAXLEN 30

char **findFirst(char **words, int n, char target[]){
    char **firstOccurrence = words;
    int i = 0;
    while (strcmp(*firstOccurrence, target) != 0 && i < n){
        i ++;
        firstOccurrence ++;
    }
    
    if (i == n){
        return NULL;
    }
    return firstOccurrence;
}

int append(char **words, char target[], int n){
    if (findFirst(words, n, target) == NULL){
        words += n;
        strcpy(*words, target);
        return n + 1;
    }
    
    return n;
}

int main(){
    char **words, *target;
    int N, output;
    
    words = malloc(MAXWORDS * sizeof(char *));
    target = malloc(MAXLEN * sizeof(char));
    for (int i = 0; i < MAXWORDS; i ++){
        words[i] = malloc(MAXLEN * sizeof(char));
    }
    
    
    scanf("%d", &N);
    for (int i = 0; i < N; i ++){
        scanf("%s", (words[i]));
    }
    
    scanf("%s", target);
    
    output = append(words, target, N);
    printf("%d %d\n", N, output);
    
    for (int i = 0; i < output; i ++){
        printf("%s ", words[i]);
    }
    free (words);
    return 0;
}