#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          
    struct Node* next; 
} Node;

typedef Node* LinkedList;

void InitList(LinkedList* L);       // 初始化链表
void add(LinkedList L, int e);      // 添加新节点
void addMultiple(LinkedList L);     // 输入多个值并添加到链表
int Insert(LinkedList L, int i, int e); // 在指定位置插入新节点
int Delete(LinkedList L, int i, int* e); // 删除指定位置的节点
void Traverse(LinkedList L);        // 遍历链表
Node* FindMiddle(LinkedList L);     // 找到链表的中点
int GetLength(LinkedList L);        // 获取链表长度
int getIntInput();                  // 获取用户输入的正整数
void Begin(LinkedList L);           // 主菜单函数

#endif 
