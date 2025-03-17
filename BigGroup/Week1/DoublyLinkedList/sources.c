#include <stdio.h>
#include <stdlib.h>
#include "Headers.h"

// ��ʼ������
void initList(DoublyLinkedList *list) {
    list->head = NULL;
}

// ��������
void createList(DoublyLinkedList *list) {
    int n, value;
    printf("����������ڵ����:");
    scanf("%d", &n);
	int i;
    for (i = 0; i < n; i++) {
        printf("����ڵ�%d��ֵ:", i + 1);
        scanf("%d", &value);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        //�ж��Ƿ�Ϊͷ��� 
        if (list->head == NULL) {
            list->head = newNode;// �������Ϊ��,���½ڵ�����Ϊͷ���
        } else {
            Node *temp = list->head; // ��ͷ��㿪ʼ��������
            while (temp->next) {// �ҵ���������һ���ڵ�

                temp = temp->next;
            }
            temp->next = newNode;// ���½ڵ����ӵ������ĩβ
            newNode->prev = temp;// �����½ڵ��ǰָ��ָ�����һ���ڵ�
        }
    }
    printf("�����ɹ�\n");
}

// ��ȡ������ 
int getListLength(DoublyLinkedList *list) {
    int length = 0;
    Node *temp = list->head;
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

//������ 
void insertNode(DoublyLinkedList *list, int value, int position) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("�ڴ����ʧ�ܣ��޷�����ڵ�\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    int length = getListLength(list);
    // ������λ���Ƿ���Ч
    if (position < 1 || position > length + 1) {
        printf("ָ��λ����Ч��������1��%d֮���λ��\n", length + 1);
        free(newNode);
        return;
    }
    // �������Ϊ��
    if (list->head == NULL) {
        if (position != 1) {
            printf("����Ϊ�գ�ֻ����λ��1����\n");
            free(newNode);
            return;
        }
        list->head = newNode;
        printf("����ɹ�\n");
        return;
    }
     // ���뵽����ͷ��
    if (position == 1) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        printf("����ɹ�\n");
        return;
    }
    // ���뵽�����м��β��
    Node *temp = list->head;// ��ͷ��㿪ʼ����
    int currentPosition = 1;// ��ǰ��������λ��
    while (temp != NULL && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }
    newNode->next = temp->next;// �½ڵ�ĺ�ָ��ָ��ԭλ�õĽڵ�
    newNode->prev = temp;// �½ڵ��ǰָ��ָ��ԭλ�õ�ǰһ���ڵ�
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("����ɹ�\n");
}

// ɾ���ڵ�
void deleteNode(DoublyLinkedList *list, int value) {
    if (list->head == NULL) {
        printf("����Ϊ��,�޷�ɾ��\n");
        return;
    }
    // ��ͷ��㿪ʼ����ֵΪvalue�Ľڵ�
    Node *temp = list->head;
    while (temp && temp->data != value) {
        temp = temp->next;
    }
     // ���δ�ҵ�ֵΪvalue�Ľڵ�
    if (!temp) {
        printf("δ�ҵ�ֵΪ%d�Ľڵ�\n", value);
        return;
    }
    // ����ҵ��Ľڵ㲻��ͷ���
    if (temp->prev) {
        temp->prev->next = temp->next;// ��ǰ�ڵ�ĺ�ָ��ָ��ǰ�ڵ�ĺ�ڵ�
    } else {
        list->head = temp->next;// ����ͷ���Ϊ��ǰ�ڵ�ĺ�ڵ�
    }
     // ����ҵ��Ľڵ��к�ڵ�
    if (temp->next) {
        temp->next->prev = temp->prev;// ����ڵ��ǰָ��ָ��ǰ�ڵ��ǰ�ڵ�
    }
    free(temp);
    printf("ɾ���ɹ�!\n");
    if (list->head == NULL) {
        printf("������Ϊ�ա�\n");
    }
}

// ��������
void traverseList(DoublyLinkedList *list) {
    if (list->head == NULL) {
        printf("����Ϊ��\n");
        return;
    }
    Node *temp = list->head;
    int count = 0;
    printf("����:");
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
}

// ��ת����
void reverseList(DoublyLinkedList *list) {
    if (list->head == NULL || list->head->next == NULL) {
        printf("����Ϊ�ջ�ֻ��һ���ڵ�,���跴ת\n");
        return;
    }
    Node *current = list->head;// ��ǰ�ڵ�ָ���ͷ��㿪ʼ
    Node *temp = NULL;// ��ʱָ�룬���ڽ���ָ����
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    // ����ͷָ��
    if (temp != NULL) {
        list->head = temp->prev;// ����ͷָ��Ϊ��ת��ĵ�һ���ڵ�
    }
    printf("��ת�ɹ�\n");
} 

// �ͷ�����
void freeList(DoublyLinkedList *list) {
    Node *temp = list->head;
    while (temp) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}

