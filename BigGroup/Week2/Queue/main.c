#include "header.h"

// �˵�����
void menu() {
    printf("===== ���в˵� ==========\n");
    printf("1. ���\n");
    printf("2. ����\n");
    printf("3. �鿴��ͷԪ��\n");
    printf("4. �������Ƿ�Ϊ��\n");
    printf("5. �������Ƿ�����\n");
    printf("6. ��ȡ���г���\n");
    printf("7. ��ת����\n");
    printf("8. ��ն���\n");
    printf("9. �鿴����Ԫ��\n");
    printf("10. �˳�\n");
    printf("=========================\n");
    printf("����������ѡ��");
}

int main() {
    LinkedListQueue* queue = createQueue();
    int choice;
    int value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // ���
            	system("cls");
                printf("������Ҫ��ӵ�ֵ:");
                scanf("%d", &value);
                enqueue(queue, value);
                printf("��ӳɹ�\n");
                system("pause");
                system("cls");
                break;
            case 2: // ����
            	system("cls");
                if (dequeue(queue, &value)) {
                    printf("���ӵ�ֵΪ:%d\n", value);
                } else {
                    printf("����Ϊ�գ��޷�����\n");
                }
                system("pause");
                system("cls");
                break;
            case 3: // �鿴��ͷ
            	system("cls");
                if (peek(queue, &value)) {
                    printf("��ͷԪ��Ϊ:%d\n", value);
                } else {
                    printf("����Ϊ�գ�û�ж�ͷԪ��\n");
                }
                system("pause");
                system("cls");
                break;
            case 4: // ����Ƿ�Ϊ��
            	system("cls");
                if (isEmpty(queue)) {
                    printf("����Ϊ��\n");
                } else {
                    printf("���в�Ϊ��\n");
                }
                system("pause");
                system("cls");
                break;
            case 5: // ����Ƿ�����
            	system("cls");
                if (isFull(queue, 10)) { // �����������Ϊ10
                    printf("��������\n");
                } else {
                    printf("����δ��\n");
                }
                system("pause");
                system("cls");
                break;
            case 6: // ��ȡ����
            	system("cls");
                printf("���г���Ϊ:%d\n", getLength(queue));
                system("pause");
                system("cls");
                break;
            case 7: // ��ת����
            	system("cls");
                reverse(queue);
                printf("�����ѷ�ת\n");
                system("pause");
                system("cls");
                break;
            case 8: // ��ն���
            	system("cls");
                clearQueue(queue);
                printf("���������\n");
                system("pause");
                system("cls");
                break;
            case 9: // �鿴����Ԫ��
				system("cls");
				displayQueue(queue);
				system("pause");
                system("cls");
                break;
            case 10: // �˳�
            	system("cls");
                printf("�˳�����\n");
                freeQueue(queue);
                return 0;
            default:
            	system("cls");
                printf("��Ч��ѡ������������\n");
                system("pause");
                system("cls");
        }
    }

    return 0;
}
