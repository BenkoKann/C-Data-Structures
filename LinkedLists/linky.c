#include<stdio.h>
#include<assert.h>

struct node {
    int data;
    struct node* next;
};

void Push(struct node** headRef, int newData) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node** lastPtrRef = &head;
    int i;
    for(i=1;i<=3;i++) {
        Push(lastPtrRef, i);
        lastPtrRef = &((*lastPtrRef)->next);
    }
    return head;
}

void printList(struct node* head) {
    // [1 => 2 => 3 => 4]

    struct node* current = head;

    printf("[");
    while(current != NULL) {
        printf("%d", current->data);
        if(current->next != NULL) {
            printf("%s", " => ");
        }
        current = current->next;
    }
    printf("]\n");

}

////////////////////// LINKED LIST PROBLEMS BELOW //////////////////////

// 1 — Count()

int Count(struct node* head, int num) {
    struct node* current = head;

    int count = 0;
    while(current != NULL) {
        if(current->data == num) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() {

    struct node* head = BuildOneTwoThree();
    printList(head);
    printf("%d", Count(head, 2));

    return 0;
}