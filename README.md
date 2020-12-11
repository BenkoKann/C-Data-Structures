# C-Data-Structures
- Implementation of data structures in C
- Based off of this source: [LinkedListProblems](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf)

## Linked List
<details><summary>Implementation</summary>
  
## definition of linked list
  ```c
  struct node {
  int data;
  struct node* next;
  };
  ```

### 1. Count()
```c
/*
 Given a list and an int, return the number of times that int occurs
 in the list.
*/
int Count(struct node* head, int searchFor) {
// Your code
```
### 2. GetNth()
```c
// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
int GetNth(struct node* head, int index) {
// Your code
```
### 3. DeleteList()
```c
/*
takes a list, deallocates all of its memory and sets its
head pointer to NULL (the empty list).
*/
void DeleteList(struct node** headRef) {
// Your code
```
### 4. Pop()
```c
/*
The opposite of Push(). Takes a non-empty list
and removes the front node, and returns the data
which was in that node.
*/
int Pop(struct node** headRef) {
// your code...
```
### 5. InsertNth()
```c
/*
A more general version of Push().
Given a list, an index 'n' in the range 0..length,
and a data element, add a new node to the list so
that it has the given index.
*/
void InsertNth(struct node** headRef, int index, int data) {
// your code...
 ```
### 6. SortedInsert()
```c
/*
Given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list.
*/
void SortedInsert(struct node** headRef, struct node* newNode) {
// Your code...
```

### 7. InsertSort()
```c
// Given a list, rearrange its nodes so they are sorted in increasing order (using SortedInsert()).
void InsertSort(struct node** headRef) { 
// Your code...
```

### 8. Append()
```c
// Append 'b' onto the end of 'a', and then set 'b' to NULL.
void Append(struct node** aRef, struct node** bRef) {
// Your code...
```

</details>
