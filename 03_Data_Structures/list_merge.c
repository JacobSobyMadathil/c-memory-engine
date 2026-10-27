#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *merge (Node *a, Node *b){
    Node *mergedList;
    Node *temp;
    
    a -> data > b -> data ? mergedList = b : mergedList = a;
    while (mergedList != NULL){
        
    }
    return mergedList;
}

int main(){
    Node *first = malloc (1 * sizeof(Node));
    Node *second = malloc (1 * sizeof(Node));
    Node *temp1;
    int N1, N2;
    scanf("%d", &N1);
    if (N1 != 0){
        scanf ("%d", &(first -> data))
        temp1 = first -> next;
        for (int i = 1; i < N1; i ++){
            temp1 = malloc (1 * sizeof(Node));
            scanf ("%d", &(temp1 -> data));
            temp1 = temp1 -> next;
        }
    }
    scanf("%d", &N2);
    if (N2 != 0){
        scanf ("%d", &(second -> data))
        temp1 = second -> next;
        for (int i = 1; i < N2; i ++){
            temp1 = malloc (1 * sizeof(Node));
            scanf ("%d", &(temp1 -> data));
            temp1 = temp1 -> next;
        }
    }
    merge (N1, N2);
    
    return 0;
}
