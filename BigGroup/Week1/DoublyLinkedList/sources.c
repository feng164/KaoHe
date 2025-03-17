#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

// 初始化链表
void initList(DoublyLinkedList *list) {
    list->head = NULL;
}

// 创建链表
void createList(DoublyLinkedList *list) {
    int n, value;
    printf("请输入链表节点个数:");
    scanf("%d", &n);
	int i;
    for (i = 0; i < n; i++) {
        printf("输入节点%d的值:", i + 1);
        scanf("%d", &value);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        //判断是否为头结点 
        if (list->head == NULL) {
            list->head = newNode;// 如果链表为空,将新节点设置为头结点
        } else {
            Node *temp = list->head; // 从头结点开始遍历链表
            while (temp->next) {// 找到链表的最后一个节点

                temp = temp->next;
            }
            temp->next = newNode;// 将新节点链接到链表的末尾
            newNode->prev = temp;// 设置新节点的前指针指向最后一个节点
        }
    }
    printf("创建成功\n");
}

// 获取链表长度 
int getListLength(DoublyLinkedList *list) {
    int length = 0;
    Node *temp = list->head;
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

//插入结点 
void insertNode(DoublyLinkedList *list, int value, int position) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("内存分配失败，无法插入节点\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    int length = getListLength(list);
    // 检查插入位置是否有效
    if (position < 1 || position > length + 1) {
        printf("指定位置无效，请输入1到%d之间的位置\n", length + 1);
        free(newNode);
        return;
    }
    // 如果链表为空
    if (list->head == NULL) {
        if (position != 1) {
            printf("链表为空，只能在位置1插入\n");
            free(newNode);
            return;
        }
        list->head = newNode;
        printf("插入成功\n");
        return;
    }
     // 插入到链表头部
    if (position == 1) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        printf("插入成功\n");
        return;
    }
    // 插入到链表中间或尾部
    Node *temp = list->head;// 从头结点开始遍历
    int currentPosition = 1;// 当前遍历到的位置
    while (temp != NULL && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }
    newNode->next = temp->next;// 新节点的后指针指向原位置的节点
    newNode->prev = temp;// 新节点的前指针指向原位置的前一个节点
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("插入成功\n");
}

// 删除节点
void deleteNode(DoublyLinkedList *list, int value) {
    if (list->head == NULL) {
        printf("链表为空,无法删除\n");
        return;
    }
    // 从头结点开始查找值为value的节点
    Node *temp = list->head;
    while (temp && temp->data != value) {
        temp = temp->next;
    }
     // 如果未找到值为value的节点
    if (!temp) {
        printf("未找到值为%d的节点\n", value);
        return;
    }
    // 如果找到的节点不是头结点
    if (temp->prev) {
        temp->prev->next = temp->next;// 将前节点的后指针指向当前节点的后节点
    } else {
        list->head = temp->next;// 更新头结点为当前节点的后节点
    }
     // 如果找到的节点有后节点
    if (temp->next) {
        temp->next->prev = temp->prev;// 将后节点的前指针指向当前节点的前节点
    }
    free(temp);
    printf("删除成功!\n");
    if (list->head == NULL) {
        printf("链表已为空。\n");
    }
}

// 遍历链表
void traverseList(DoublyLinkedList *list) {
    if (list->head == NULL) {
        printf("链表为空\n");
        return;
    }
    Node *temp = list->head;
    int count = 0;
    printf("链表:");
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
}

// 反转链表
void reverseList(DoublyLinkedList *list) {
    if (list->head == NULL || list->head->next == NULL) {
        printf("链表为空或只有一个节点,无需反转\n");
        return;
    }
    Node *current = list->head;// 当前节点指针从头结点开始
    Node *temp = NULL;// 临时指针，用于交换指针域
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    // 调整头指针
    if (temp != NULL) {
        list->head = temp->prev;// 更新头指针为反转后的第一个节点
    }
    printf("反转成功\n");
} 

// 释放链表
void freeList(DoublyLinkedList *list) {
    Node *temp = list->head;
    while (temp) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}

