#include <stdio.h>
#include "Headers.h"

// �˵�����
void menu() {
    printf("\n===== ˫��������� =====\n");
    printf("1. ��������\n");
    printf("2. ����ڵ�\n");
    printf("3. ɾ���ڵ�\n");
    printf("4. ��ת����\n");
    printf("5. ��ʾ����\n");
    printf("6. �˳�\n");
    printf("========================\n");
}

int main() {
    DoublyLinkedList list;
    //��ʼ�� 
    initList(&list);
    int choice, value, position;
    while (1) {
        menu();
        printf("���������ѡ��:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            	system("cls");
                createList(&list);
                system("pause");
                system("cls");
                break;
            case 2:
            	system("cls");
            	printf("������Ҫ�����λ��:");
            	scanf("%d",&position);
                printf("����Ҫ�����ֵ:");
                scanf("%d", &value);
                insertNode(&list, value,position);
                system("pause");
                system("cls");
                break;
            case 3:
            	system("cls");
                printf("����Ҫɾ����ֵ:");
                scanf("%d", &value);
                deleteNode(&list, value);
                system("pause");
                system("cls");
                break;
            case 4:
            	system("cls");
                reverseList(&list);
                system("pause");
                system("cls");
                break;
            case 5:
            	system("cls");
                traverseList(&list);
                system("pause");
                system("cls");
                break;
            case 6:
            	system("cls");
                freeList(&list);
                printf("�˳�����\n");
                system("pause");
                system("cls");
                return 0;
            default:
            	system("cls");
                printf("��Ч���룬����������\n");
                system("pause");
                system("cls");
        }
    }
    return 0;
}

