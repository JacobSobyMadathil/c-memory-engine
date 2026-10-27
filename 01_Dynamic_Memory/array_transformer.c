#include <stdio.h>

int main()
{
    int N, K;
    int sum = 0, max, even = 0;
    scanf("%d", &N);
    int a[N];
    int *p = a;
    for (int i = 0; i < N; i ++){
        scanf("%d", p);
        p ++;
    }
    scanf("%d", &K);
    
    p = a;
    
    for (int i = 0; i < N; i ++){
        if (*p % 3 == 0){
            *p /= 3;
        }
        else{
            *p += K;
        }
        p ++;
    }
    
    p = a;
    
    for (int i = 0; i < N; i ++){
        sum += *p;
        p ++;
    }
    
    p = a;
    max = *p;
    
    for (int i = 0; i < N; i ++){
        if (max < *p){
            max = *p;
        }
        p ++;
    }
    
    p = a;
    
    for (int i = 0; i < N; i ++){
        if (*p % 2 == 0){
            even ++;
        }
        p ++;
    }
    
    p = a;
    
    for (int i = 0; i < N - 1; i ++){
        printf("%d ", *p);
        p ++;
    }
    printf("%d\n", *p);
    
    printf("%d %d %d", sum, max, even);
    return 0;
}
