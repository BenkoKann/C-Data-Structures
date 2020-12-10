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

int GetNth(struct node* head, int index) {
    assert(index >= 0); 
    struct node* current = head;
    int count = 0;
    while(count < index && current != NULL) {
        current = current->next;
        count++;
       // printf("%d", count);
    }
    assert(count == index); 
    assert(current != NULL);
    return current->data;
}

void DeleteList(struct node** headRef) {
    struct node* current = *headRef;
    struct node* next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *headRef = NULL;


}

int Pop(struct node** headRef) {
    struct node* head = *headRef;
    assert(head != NULL);
    int retVal = head->data;

    *headRef = head->next;
    free(head);

    return retVal;
}

void InsertNth(struct node** headRef, int index, int data) {

    struct node* current = *headRef;
    if(index == 0) {
        Push(headRef, data);
        return;
    }
    int count = 0;
    while(count < index-1 && current != NULL) { // get to place before the insert
        current = current->next;
        count++;
    }
    assert(current != NULL);
    Push(&(current->next), data);
}

void SortedInsert(struct node** headRef, struct node* newNode) {

    struct node* current = *headRef;
    if(current == NULL || current->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        while(current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

}

int main() {

    struct node* head = BuildOneTwoThree();
    printList(head);
    // printf("%d\n", Count(head, 2));
    // printf("%d\n", GetNth(head, 0));
    // printf("%d\n", GetNth(head, 1));
    // printf("%d\n", GetNth(head, 2));
    // printf("%d\n", GetNth(head, 3));
    //DeleteList(&head);
    //Pop(&head);

    // InsertNth(&head, 3, 9999);

    // struct node* n1 = (struct node*) malloc(sizeof(struct node));
    // n1->data = 210;
    // n1->next = NULL;

    // SortedInsert(&head, n1);

    
    printList(head);

    return 0;
}