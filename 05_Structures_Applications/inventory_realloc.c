#include <stdio.h>
#include <stdlib.h>

struct Item
{
    char code[11];
    int quantity;
};

int main()
{
    int n, total = 0;
    struct Item *items;
    struct Item *temp;

    scanf("%d", &n);

    items = malloc(n * sizeof(struct Item));
    if (items == NULL){
        printf("Memory Allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i ++){
        scanf("%10s", (items + i) -> code);
        scanf("%d", &(items + i) -> quantity);
    }
    
    temp = items;
    
    items = realloc(temp, (n + 2) * sizeof(struct Item));
    if (items == NULL){
        printf("Memory Reallocation failed");
        return 1;
    }
    
    for (int i = 0; i < 2; i ++){
        scanf("%10s", (items + n + i) -> code);
        scanf("%d", &(items + n + i) -> quantity);
    }
    
    printf("%d ", (items -> quantity));
    total += (items -> quantity);
    
    for (int i = 1; i < n + 2; i ++){
        printf("+ %d ", ((items + i) -> quantity));
        total += ((items + i) -> quantity);
    }
    
    printf("= %d", total);

    free(items);

    return 0;
}
