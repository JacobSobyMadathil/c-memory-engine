#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int main(void)
{
    Node *head = malloc (1 * sizeof(Node));
    Node *temp1, *temp2, *temp3, *l1 = NULL, *l2 = NULL;
    int n;
    scanf("%d", &n);
    temp1 = head;
    scanf("%d", &(temp1 -> data));
    for (int i = 1; i < n; i ++){
        temp1 -> next = malloc (1 * sizeof(Node));
        temp1 = temp1 -> next;
        scanf("%d", &(temp1 -> data));
    }
    temp1 -> next = NULL;
    
    temp1 = head;
    if (n == 1){
        printf("%d\n", temp1 -> data);
        printf("EMPTY\n");
        printf("%d", temp1 -> data);
        return 0;
    }
    
    l1 = head;
    l2 = head -> next;
    
    temp2 = l1;
    temp3 = l2;
    while (temp1 != NULL && n > 2){
        temp1 = temp1 -> next;
        temp1 = temp1 -> next;
        if (temp1 -> next == NULL){
            temp2 -> next = temp1;
            temp2 = temp2 -> next;
            break;
        }
        temp2 -> next = temp1;
        temp3 -> next = temp1 -> next;
        temp2 = temp2 -> next;
        temp3 = temp3 -> next;
        if ((temp1 -> next) -> next == NULL){
            break;
        }
    }
    
    temp2 -> next = NULL;
    temp3 -> next = NULL;
    
    if (n == 1){
        printf("%d\n", l1 -> data);
        printf("EMPTY\n");
        printf("%d", l1 -> data);
        return 0;
    }
    
    temp2 = l1;
    temp3 = l2;
    while (l1 -> next != NULL){
        printf("%d ", l1 -> data);
        l1 = l1 -> next;
    }
    printf("%d", l1 -> data);
    printf("\n");
    while (l2 -> next != NULL){
        printf("%d ", l2 -> data);
        l2 = l2 -> next;
    }
    printf("%d", l2 -> data);
    printf("\n");
    
    l1 = temp2;
    l2 = temp3;
    
    if (l2 -> data > l1 -> data){
        head = l1;
        l1 = l1 -> next;
        head -> next = NULL;
    }
    else{
        head = l2;
        l2 = l2 -> next;
        head -> next = NULL;
    }
    temp1 = head;
    while (l1 != NULL && l2 != NULL){
        if (l1 -> data > l2 -> data){
            temp1 -> next = l2;
            temp1 = temp1 -> next;
            l2 = l2 -> next;
            temp1 -> next = NULL;
        }
        else{
            temp1 -> next = l1;
            temp1 = temp1 -> next;
            l1 = l1 -> next;
            temp1 -> next = NULL;
        }
    }
    if  (l2 != NULL){
            temp1 -> next = l2;
            
        }
    
    else if (l1 != NULL){
            temp1 -> next = l1;
            
        }
    
    
    temp1 = head;
    while (temp1 -> next != NULL){
        printf("%d ", temp1 -> data);
        temp1 = temp1 -> next;
    }
    printf("%d", temp1 -> data);
    
    
    return 0;
}