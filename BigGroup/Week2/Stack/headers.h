#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ��ջ�Ľڵ�ṹ
typedef struct Node {
    int data; 
    struct Node* next;
} Node;

// ��ջ�ṹ
typedef struct {
    Node* top; // ջ��ָ��
} LinkStack;

// ��ʼ����ջ
void InitStack(LinkStack* S);

// �ж���ջ�Ƿ�Ϊ��
int StackEmpty(LinkStack S);

// ��ջ����
void Push(LinkStack* S, int e);

// ��ջ����
int Pop(LinkStack* S, int* e);

// ��ȡջ��Ԫ��
int GetTop(LinkStack S, int* e);

// ���������ȼ���
int priority(char op);

// ��׺���ʽת��׺���ʽ
void InfixToPostfix(char* infix, char* postfix);

// ��׺���ʽ��ֵ
int EvaluatePostfix(char* postfix);

#endif 

