#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, len = 0, c, len1 = 0;
    char **words, *temp;
    scanf("%d", &n);
    c = getchar();
    words = malloc (n * sizeof(char *));
    temp = malloc (101 * sizeof(char));
    
    for (int i = 0; i < n; i ++){
        c = getchar();
        while (c != '\n' && c != EOF){
            len ++;
            *(temp + len - 1) = (char) c;
            c = getchar();
        }
        *(words + i) = malloc ((len + 1) * sizeof(char));
        for (int j = 0; j < len; j ++){
            *(*(words + i) + j) = *(temp + j);
        }
        *(*(words + i) + len) = '\0';
        len = 0;
    }
    
    for (int i = 0; i < n - 1; i ++){
        for (int j = 0; j < n - i - 1; j ++){
            for (len = 0; *(*(words + j) + len) != '\0'; len ++);
            for (len1 = 0; *(*(words + j + 1) + len1) != '\0'; len1 ++);
            if (len > len1){
                temp = *(words + j);
                *(words + j) = *(words + j + 1);
                *(words + j + 1) = temp;
            }
        }
    }
    
    for (int i = 0; i < n; i ++){
        c = *(*(words + i));
        for (int j = 1; c != '\0'; j ++){
            printf("%c", c);
            c = *(*(words + i) + j);
        }
        printf("\n");
    }
    free (words);
    free (temp);
    return 0;
}