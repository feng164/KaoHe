#include "header.h"

// 创建队列
LinkedListQueue* createQueue() {
    LinkedListQueue* queue = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
    if (queue == NULL) {
        perror("为队列分配内存失败\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// 入队操作
void enqueue(LinkedListQueue* queue, int value) {
    if (isFull(queue, INT_MAX)) {
        printf("队列已满，无法入队\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("为新节点分配内存失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {  // 队列为空
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// 出队操作
bool dequeue(LinkedListQueue* queue, int* value) {
    if (isEmpty(queue)) {
        return false;  // 队列为空，无法出队
    }

    Node* temp = queue->front;
    *value = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {  // 队列变为空
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return true;
}

// 查看队头元素
bool peek(LinkedListQueue* queue, int* value) {
    if (isEmpty(queue)) {
        return false;  // 队列为空，无法查看队头
    }
    *value = queue->front->data;
    return true;
}

// 判断队列是否为空
bool isEmpty(LinkedListQueue* queue) {
    return queue->front == NULL;
}

// 判断队列是否已满
bool isFull(LinkedListQueue* queue, int maxCapacity) {
    return queue->size >= maxCapacity;
}

// 获取队列长度
int getLength(LinkedListQueue* queue) {
    return queue->size;
}

// 反转队列
void reverse(LinkedListQueue* queue) {
    if (isEmpty(queue) || queue->size == 1) {
        return;  // 队列为空或只有一个元素，无需反转
    }

    Node* prev = NULL;
    Node* current = queue->front;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // 保存下一个节点
        current->next = prev;  // 反转当前节点的指针
        prev = current;        // 移动prev和current
        current = next;
    }

    // 交换front和rear指针
    queue->front = prev;
    queue->rear = current;
}

// 清空队列
void clearQueue(LinkedListQueue* queue) {
    while (!isEmpty(queue)) {
        int temp;
        dequeue(queue, &temp);
    }
}

// 释放队列内存
void freeQueue(LinkedListQueue* queue) {
    clearQueue(queue);
    free(queue);
}

// 显示队列中的所有元素
void displayQueue(LinkedListQueue* queue) {
    if (isEmpty(queue)) {
        printf("队列为空\n");
        return;
    }

    printf("队列中的元素为:");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
