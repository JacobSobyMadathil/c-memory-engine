#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, *p, *start, temp;
    scanf(" %d %d", &n, &k);
    p = malloc (n * sizeof(int));
    start = p;
    
    while (p - start < n){
        scanf("%d", p ++);
    }
    p = start;
    
    //reversing the first k elements
    for (int i = 0; i < k/2; i ++){
        temp = *(p + i);
        *(p + i) = *(p + (k - 1 - i));
        *(p + (k - 1 - i)) = temp;
    }
    
    //reversing n - k elements
    for (int i = 0; i < (n - k)/2; i ++){
        temp = *(p + (k + i));
        *(p + (k + i)) = *(p + (n - 1 - i));
        *(p + (n - 1 - i)) = temp;
    }
    
    //reversing all the elements
    for (int i = 0; i < n/2; i ++){
        temp = *(p + i);
        *(p + i) = *(p + (n - 1 - i));
        *(p + (n - 1 - i)) = temp;
    }
    
    p = start;
    
    while (p - start < n){
        printf("%d ", *p++);
    }
    
    free (start);
    return 0;
}
