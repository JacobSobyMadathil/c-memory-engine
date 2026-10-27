#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char name[31];
    char word[31];
    struct node *next;
    struct node *prev;
}Node;

int main(){
    int N;
    char dir, start[31];
    scanf("%d", &N);
    Node *first = malloc (1 * sizeof(Node));
    Node *last = malloc (1 * sizeof(Node));
    Node *temp1;
    Node *temp2;
    Node *temp3;
    if (N >= 2){
        temp1 = first;
        scanf ("%s %s", (first -> name), (first -> word));
        first -> prev = NULL;
        for (int i = 1; i < N - 1; i ++){
            temp1 -> next = malloc (1 * sizeof(Node));
            temp2 = temp1;
            temp1 = temp1 -> next;
            temp1 -> prev = temp2;
            scanf ("%s %s", (temp1 -> name), (temp1 -> word));
        }
        temp1 -> next = last;
        scanf ("%s %s", (last -> name), (last -> word));
    }
    else{
        scanf ("%s %s", (first -> name), (first -> word));
        first -> next = NULL;
        first -> prev = NULL;
    }
    scanf ("%s %c", (start), &(dir));
    
    temp1 = first;
    while (temp1 != NULL){
        if (temp1 -> name == start){
            break;
        }
        temp1 = temp1 -> next;
    }
    if (dir == 'R'){
        temp2 = temp1;
        while (temp1 != NULL){
            printf("%s: ", temp1 -> name);
            temp3 = temp2;
            while (temp3 -> prev != temp1){
                printf("%s ", temp3 -> word);
                temp3 = temp3 -> next;
            }
            temp1 = temp1 -> next;
            printf("\n");
        }
    }
}
