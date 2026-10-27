#include <stdio.h>
#include <stdlib.h>

struct Student{
    int roll;
    char name[50];
    float marks;
};

struct Student *highest(struct Student *s, int n){
    struct Student *temp = s;
    for (int i = 0; i < n; i ++){
        if ((temp -> marks) < ((s + i) -> marks)){
            temp = (s + i);
        }
    }
    return temp;
}

struct Student *search(struct Student *s, int n, int target){
    struct Student *temp = s;
    for (int i = 0; i < n; i ++){
        if (((s + i) -> roll) == target){
            temp = (s + i);
        }
    }
    return temp;
}
int main(){
    int n, target;
    struct Student *s, *temp, swap;
    scanf("%d", &n);
    s = malloc (n * sizeof(struct Student));
    temp = s;
    for (int i = 0; i < n; i ++){
        scanf("%d %s %f", &((s + i) -> roll), ((s + i) -> name), &((s + i) -> marks));
    }
    scanf("%d", &target);
    printf("Student with highest marks:\n");
    temp = highest (s, n);
    printf("Roll: %d\nName: %s\nMarks %.2f\n", (temp -> roll), (temp -> name), (temp -> marks));
    
    printf("Search result:\n");
    temp = search (s, n, target);
    printf("Roll: %d\nName: %s\nMarks %.2f\n", (temp -> roll), (temp -> name), (temp -> marks));
    
    printf("Students sorted by marks:\n");
    
    for (int i = 0; i < n - 1; i ++){
        for (int j = 0; j < n - i - 1; j ++){
            if (((s + j) -> marks) < ((s + j + 1) -> marks)){
                swap = *(s + j);
                *(s + j) = *(s + j + 1);
                *(s + j + 1) = swap;
            }
        }
    }
    
    for (int i = 0; i < n; i ++){
        printf("%d %s %.2f\n", ((s + i) -> roll), ((s + i) -> name), ((s + i) -> marks));
    }
    free (s);
    return 0;
}
