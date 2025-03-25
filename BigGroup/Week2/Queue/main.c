#include "header.h"

// 菜单界面
void menu() {
    printf("===== 队列菜单 ==========\n");
    printf("1. 入队\n");
    printf("2. 出队\n");
    printf("3. 查看队头元素\n");
    printf("4. 检查队列是否为空\n");
    printf("5. 检查队列是否已满\n");
    printf("6. 获取队列长度\n");
    printf("7. 反转队列\n");
    printf("8. 清空队列\n");
    printf("9. 查看队列元素\n");
    printf("10. 退出\n");
    printf("=========================\n");
    printf("请输入您的选择：");
}

int main() {
    LinkedListQueue* queue = createQueue();
    int choice;
    int value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // 入队
            	system("cls");
                printf("请输入要入队的值:");
                scanf("%d", &value);
                enqueue(queue, value);
                printf("添加成功\n");
                system("pause");
                system("cls");
                break;
            case 2: // 出队
            	system("cls");
                if (dequeue(queue, &value)) {
                    printf("出队的值为:%d\n", value);
                } else {
                    printf("队列为空，无法出队\n");
                }
                system("pause");
                system("cls");
                break;
            case 3: // 查看队头
            	system("cls");
                if (peek(queue, &value)) {
                    printf("队头元素为:%d\n", value);
                } else {
                    printf("队列为空，没有队头元素\n");
                }
                system("pause");
                system("cls");
                break;
            case 4: // 检查是否为空
            	system("cls");
                if (isEmpty(queue)) {
                    printf("队列为空\n");
                } else {
                    printf("队列不为空\n");
                }
                system("pause");
                system("cls");
                break;
            case 5: // 检查是否已满
            	system("cls");
                if (isFull(queue, 10)) { // 假设最大容量为10
                    printf("队列已满\n");
                } else {
                    printf("队列未满\n");
                }
                system("pause");
                system("cls");
                break;
            case 6: // 获取长度
            	system("cls");
                printf("队列长度为:%d\n", getLength(queue));
                system("pause");
                system("cls");
                break;
            case 7: // 反转队列
            	system("cls");
                reverse(queue);
                printf("队列已反转\n");
                system("pause");
                system("cls");
                break;
            case 8: // 清空队列
            	system("cls");
                clearQueue(queue);
                printf("队列已清空\n");
                system("pause");
                system("cls");
                break;
            case 9: // 查看队列元素
				system("cls");
				displayQueue(queue);
				system("pause");
                system("cls");
                break;
            case 10: // 退出
            	system("cls");
                printf("退出程序\n");
                freeQueue(queue);
                return 0;
            default:
            	system("cls");
                printf("无效的选择，请重新输入\n");
                system("pause");
                system("cls");
        }
    }

    return 0;
}
