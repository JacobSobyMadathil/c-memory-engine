#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, len;
    char **words, *temp, *start;
    scanf("%d", &n);
    words = malloc (n * sizeof(char *));
    temp = malloc (51 * sizeof(char));
    
    start = temp;
    for (int i = 0; i < n; i ++){
        scanf("%s", temp);
        while (*temp != '\0'){
            temp ++;
        }
        len = temp - start;
        temp = start;
        *(words + i) = malloc (len * sizeof(char));
        for (int j = 0; j < len; j ++){
            *(*(words + i) + j) = *(temp + j);
        }
    }
    
    for (int i = 0; i < n - 1; i ++){
        for (int j = 0; j < n - i - 1; j ++){
            if (**(words + i) > **(words + i + 1)){
                temp = *(words + i);
                *(words + i) = *(words + i + 1);
                *(words + i + 1) = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i ++){
        printf("%s\n", *(words + i));
    }
    return 0;
}