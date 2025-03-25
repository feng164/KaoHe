#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 链栈的节点结构
typedef struct Node {
    int data; 
    struct Node* next;
} Node;

// 链栈结构
typedef struct {
    Node* top; // 栈顶指针
} LinkStack;

// 初始化链栈
void InitStack(LinkStack* S);

// 判断链栈是否为空
int StackEmpty(LinkStack S);

// 入栈操作
void Push(LinkStack* S, int e);

// 出栈操作
int Pop(LinkStack* S, int* e);

// 获取栈顶元素
int GetTop(LinkStack S, int* e);

// 操作符优先级表
int priority(char op);

// 中缀表达式转后缀表达式
void InfixToPostfix(char* infix, char* postfix);

// 后缀表达式求值
int EvaluatePostfix(char* postfix);

#endif 

