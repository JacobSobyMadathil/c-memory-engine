#include <stdio.h>
#include <stdlib.h>

int main(){
    int maxLength = 1001, len, status = 0;
    int d;
    char *c, *p, *start;
    
    c = malloc (maxLength * sizeof(char));
    if (c == NULL){
        return 1;
    }
    start = c;
    
    d = getchar();
    *c ++ = (char) d;
    while (d != '\0' && d != EOF){
        d = getchar();
        *c ++ = (char) d;
    }
    *c = '\0';
    len = c - start - 1;
    
    printf("Length: %d\n", len);
    printf("Reversed: ");
    while(c - start > 0){
        printf("%c", *(--c));
    }
    
    printf("\n");
    
    c = start;
    p = c;
    
    while (*p != '\0'){
        if (*p >= 'a' && *p <= 'z'){
            *c = *p;
            c ++;
        }
        else if (*p >= 'A' && *p <= 'Z'){
            *c = *p + 'a' - 'A';
            c ++;
        }
        p ++;
    }
    
    *c = '\0';
    
    c = start;
    len = 0;
    
    while(*c != '\0'){
        len ++;
        c ++;
    }
    
    p = start;
    
    for (int i = 0; i < len / 2; i ++){
        if (*(p + i) != *(c - 1 - i)){
            status = 1;
            break;
        }
    }
    
    if (status == 1){
        printf("Palindrome: No");
    }
    if (status == 0){
        printf("Palindrome: Yes");
    }
    
    
    free (start);
    
    return 0;
}