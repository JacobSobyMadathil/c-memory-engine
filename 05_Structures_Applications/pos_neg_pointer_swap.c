#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int n;
    int *a, *sp, *ln;

    scanf("%d", &n);

    a = malloc(n * sizeof(int));
    if (a == NULL){
        printf("Memory Allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i ++){
        scanf(" %d", a + i);
    }
    
    for (int i = n - 1; i >= 0; i --){
        if (*(a + i) > 0){
            sp = a + i;
        }
        if (*(a + i) < 0){
            ln = a + i;
        }
    }
    
    for (int i = 0; i < n; i ++){
        if (*(a + i) > 0 && *(a + i) < *sp){
            sp = a + i;
        }
        if (*(a + i) < 0 && *(a + i) > *ln){
            ln = a + i;
        }
    }
    
    swap(ln, sp);
    printf("%d %d %d\n", *ln, *sp, *ln - *sp);
    for (int i = 0; i < n; i ++){
        printf("%d ", *(a + i));
    }
    free(a);

    return 0;
}
