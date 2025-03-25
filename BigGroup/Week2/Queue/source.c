#include "header.h"

// ��������
LinkedListQueue* createQueue() {
    LinkedListQueue* queue = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
    if (queue == NULL) {
        perror("Ϊ���з����ڴ�ʧ��\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// ��Ӳ���
void enqueue(LinkedListQueue* queue, int value) {
    if (isFull(queue, INT_MAX)) {
        printf("�����������޷����\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Ϊ�½ڵ�����ڴ�ʧ��\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {  // ����Ϊ��
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// ���Ӳ���
bool dequeue(LinkedListQueue* queue, int* value) {
    if (isEmpty(queue)) {
        return false;  // ����Ϊ�գ��޷�����
    }

    Node* temp = queue->front;
    *value = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {  // ���б�Ϊ��
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return true;
}

// �鿴��ͷԪ��
bool peek(LinkedListQueue* queue, int* value) {
    if (isEmpty(queue)) {
        return false;  // ����Ϊ�գ��޷��鿴��ͷ
    }
    *value = queue->front->data;
    return true;
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(LinkedListQueue* queue) {
    return queue->front == NULL;
}

// �ж϶����Ƿ�����
bool isFull(LinkedListQueue* queue, int maxCapacity) {
    return queue->size >= maxCapacity;
}

// ��ȡ���г���
int getLength(LinkedListQueue* queue) {
    return queue->size;
}

// ��ת����
void reverse(LinkedListQueue* queue) {
    if (isEmpty(queue) || queue->size == 1) {
        return;  // ����Ϊ�ջ�ֻ��һ��Ԫ�أ����跴ת
    }

    Node* prev = NULL;
    Node* current = queue->front;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // ������һ���ڵ�
        current->next = prev;  // ��ת��ǰ�ڵ��ָ��
        prev = current;        // �ƶ�prev��current
        current = next;
    }

    // ����front��rearָ��
    queue->front = prev;
    queue->rear = current;
}

// ��ն���
void clearQueue(LinkedListQueue* queue) {
    while (!isEmpty(queue)) {
        int temp;
        dequeue(queue, &temp);
    }
}

// �ͷŶ����ڴ�
void freeQueue(LinkedListQueue* queue) {
    clearQueue(queue);
    free(queue);
}

// ��ʾ�����е�����Ԫ��
void displayQueue(LinkedListQueue* queue) {
    if (isEmpty(queue)) {
        printf("����Ϊ��\n");
        return;
    }

    printf("�����е�Ԫ��Ϊ:");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
