#include <stdio.h>
#include "Headers.h"

// 菜单界面
void menu() {
    printf("\n===== 双向链表操作 =====\n");
    printf("1. 创建链表\n");
    printf("2. 插入节点\n");
    printf("3. 删除节点\n");
    printf("4. 反转链表\n");
    printf("5. 显示链表\n");
    printf("6. 退出\n");
    printf("========================\n");
}

int main() {
    DoublyLinkedList list;
    //初始化 
    initList(&list);
    int choice, value, position;
    while (1) {
        menu();
        printf("请输入你的选择:");
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
            	printf("请输入要插入的位置:");
            	scanf("%d",&position);
                printf("输入要插入的值:");
                scanf("%d", &value);
                insertNode(&list, value,position);
                system("pause");
                system("cls");
                break;
            case 3:
            	system("cls");
                printf("输入要删除的值:");
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
                printf("退出程序\n");
                system("pause");
                system("cls");
                return 0;
            default:
            	system("cls");
                printf("无效输入，请重新输入\n");
                system("pause");
                system("cls");
        }
    }
    return 0;
}

