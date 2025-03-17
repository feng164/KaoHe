#ifndef HEADERS_H
#define HEADERS_H

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
} DoublyLinkedList;

void initList(DoublyLinkedList *list);
void createList(DoublyLinkedList *list);
int getListLength(DoublyLinkedList *list);
void insertNode(DoublyLinkedList *list, int value, int position);
void deleteNode(DoublyLinkedList *list, int value);
void reverseList(DoublyLinkedList *list);
void traverseList(DoublyLinkedList *list);
void freeList(DoublyLinkedList *list);

#endif 

