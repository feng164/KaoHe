#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ������нڵ�
typedef struct Node {
    int data;                
    struct Node* next;       
} Node;

// ������ʽ����
typedef struct LinkedListQueue {
    Node* front;             
    Node* rear;              
    int size;                
} LinkedListQueue;

// ��������
LinkedListQueue* createQueue();
void enqueue(LinkedListQueue* queue, int value);
bool dequeue(LinkedListQueue* queue, int* value);
bool peek(LinkedListQueue* queue, int* value);
bool isEmpty(LinkedListQueue* queue);
bool isFull(LinkedListQueue* queue, int maxCapacity);
int getLength(LinkedListQueue* queue);
void reverse(LinkedListQueue* queue);
void clearQueue(LinkedListQueue* queue);
void freeQueue(LinkedListQueue* queue);
void displayQueue(LinkedListQueue* queue); 

#endif 
