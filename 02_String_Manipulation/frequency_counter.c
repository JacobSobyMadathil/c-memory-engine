#include <stdio.h>
#include <stdlib.h>

int main(){
    char *p, *start;
    int *q, *temp, a;
    int maxLimit = 1001;
    p = malloc (maxLimit * sizeof(char));
    q = calloc (26, sizeof(int));
    
    start = p;
    temp = q;
    
    a = getchar();
    *p = (char) a;
    
    while(a != '\0' && a != EOF){
        p ++;
        a = getchar();
        *p = (char) a;
        }
    p ++;
    *p = '\0';
    
    p = start;
    
    for (int i = 0; *p != '\0'; i ++){
        if (*p >= 'a' && *p <= 'z'){
            q += (*p - 'a');
            (*q) ++;
            q = temp;
        }
        else if (*p >= 'A' && *p <= 'Z'){
            q += (*p - 'A');
            (*q) ++;
            q = temp;
        }
        p ++;
    }
    
    for (int i = 0; i < 26; i ++){
        if (*(q + i) != 0){
            printf("%c: %d\n", (i + 'a'), *(q + i));
        }
    }
    
    free (q);
    free (start);
    
    return 0;
}