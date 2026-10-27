#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    int priority;
    struct node *next;
} Node;

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    Node *temp3 = NULL;
    int N, nl = 0, searchID;
    char command;
    
    head = malloc (1 * sizeof(Node));
    tail = malloc (1 * sizeof(Node));
    head -> next = NULL;
    tail -> next = NULL;
    
    scanf ("%d", &N);
    
    for (int i = 0; i < N; i ++){
        scanf (" %c", &command);
        if (command == 'A'){
            if (head -> next == NULL){
                head -> next = malloc (1 * sizeof(Node));
                temp1 = head -> next;
            }
            else{
                temp1 = head -> next;
                while (temp1 -> next != NULL){
                    temp1 = temp1 -> next;
                }
                temp1 -> next = malloc (1 * sizeof(Node));
                temp1 = temp1 -> next;
            }
            scanf ("%d %d", &(temp1 -> id), &(temp1 -> priority));
            nl ++;
        }
        else if (command == 'S'){
            if (head -> next == NULL){
                continue;
            }
            temp1 = head -> next;
            temp2 = temp1 -> next;
            head -> next = temp2;
            free (temp1);
            nl --;
        }
        else if (command == 'C'){
            scanf ("%d", &searchID);
            temp3 = head;
            while (temp3 -> next != NULL){
                temp2 = temp3;
                temp3 = temp3 -> next;
                if (temp3 -> id == searchID){
                    temp1 = temp3 -> next;
                    temp2 -> next = temp1;
                    free (temp3);
                    break;
                }
            }
            nl --;
        }
        else if (command == 'U'){
            scanf ("%d", &searchID);
            temp1 = head -> next;
            for (int i = 0; i < nl; i ++){
                if ((temp1 -> id) == searchID){
                    break;
                }
                temp1 = temp1 -> next;
            }
            scanf ("%d", &(temp1 -> priority));
        }
    }
    
    temp1 = head -> next;
    if (temp1 == NULL){
        head -> next = tail;
    }
    else{
        while (temp1 -> next != NULL){
            temp1 = temp1 -> next;
        }
        temp1 -> next = tail;
    }
    
    if (head -> next == tail){
        printf("EMPTY");
        return 0;
    }
    
    temp1 = head -> next;
    while (temp1 != tail){
        printf("%d(%d) ", (temp1 -> id), (temp1 -> priority));
        temp1 = temp1 -> next;
    }
    return 0;
}