#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          
    struct Node* next; 
} Node;

typedef Node* LinkedList;

void InitList(LinkedList* L);       // ��ʼ������
void add(LinkedList L, int e);      // ����½ڵ�
void addMultiple(LinkedList L);     // ������ֵ����ӵ�����
int Insert(LinkedList L, int i, int e); // ��ָ��λ�ò����½ڵ�
int Delete(LinkedList L, int i, int* e); // ɾ��ָ��λ�õĽڵ�
void Traverse(LinkedList L);        // ��������
Node* FindMiddle(LinkedList L);     // �ҵ�������е�
int GetLength(LinkedList L);        // ��ȡ������
int getIntInput();                  // ��ȡ�û������������
void Begin(LinkedList L);           // ���˵�����

#endif 
