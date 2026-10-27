#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, *arr, *temp;
    /* TODO: Read the number of elements. */
    scanf("%d", &n);
    /* TODO: Allocate memory and read the input elements. */
    arr = malloc (n * sizeof(int));
    if (arr == NULL){
        printf("Allocation failed");
        return 1;
    }
    temp = arr;
    for (int i = 0; i < n; i ++){
        scanf("%d", arr + i);
    }
    /* TODO: Resize the allocated memory using realloc. */
    arr = realloc (temp, (2 * n - 1) * sizeof(int));
    if (arr == NULL){
        printf("Reallocation failed");
        return 1;
    }
    /* TODO: Perform the required processing. */
    for (int i = n - 1; i >= 0; i --){
        *(arr + (2 * i)) = *(arr + i);
    }
    
    for (int i = 0; i < (2 * n - 1); i += 2){
        *(arr + i + 1) = *(arr + i) + *(arr + i + 2);
    }
    /* TODO: Print the resulting elements. */
    for (int i = 0; i < (2 * n - 1); i ++){
        printf("%d ", *(arr + i));
    }
    /* TODO: Free all dynamically allocated memory. */
    free (arr);
    return 0;
}