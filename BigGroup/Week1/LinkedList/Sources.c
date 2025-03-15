#include "Headers.h"

// ��ʼ������
void InitList(LinkedList* L) {
    *L = (Node*)malloc(sizeof(Node));
    if (*L == NULL) {
        printf("�ڴ����ʧ��!\n");
        exit(1);
    }
    (*L)->next = NULL;
}

// ����½ڵ�
void add(LinkedList L, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        return;
    }
    newNode->data = e;
    newNode->next = NULL;

    Node* p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

// ������ֵ����ӵ�����
void addMultiple(LinkedList L) {
    printf("���������֣���������ֽ�������\n");
    int data;
    while (scanf("%d", &data) == 1) {
        add(L, data);
    }
    while (getchar() != '\n') {}  // ��ջ�����
    printf("�����ɡ�\n");
}

// ��ָ��λ�ò����½ڵ�
int Insert(LinkedList L, int i, int e) {
    Node* p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1) {
        return 0; 
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        return 0;
    }
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return 1;
}

// ɾ���ڵ�
int Delete(LinkedList L, int i, int* e) {
    Node* p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i - 1) {
        return 0;
    }
    Node* q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;
}

// ��������
void Traverse(LinkedList L) {
    Node* p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// �ҵ�������е�
Node* FindMiddle(LinkedList L) {
    Node* slow = L->next;
    Node* fast = L->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int GetLength(LinkedList L) {
    int count = 0;
    Node* p = L->next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int getIntInput() {
    int num;
    while (1) {
        if (scanf("%d", &num) == 1) {  
            if (num <= 0) {  
                printf("����������:");
            } else {
                return num;  
            }
        } else {
            while (getchar() != '\n');  
            printf("������Ĳ������֣�����������:");
        }
    }
}

void Begin(LinkedList L) {
    int choice;
    do {
        printf("\n��ѡ�������\n");
        printf("1. ��Ӷ��ֵ\n");
        printf("2. ����ֵ\n");
        printf("3. ɾ��ֵ\n");
        printf("4. ��������\n");
        printf("5. �ҵ������е�\n");
        printf("6. �˳�\n");
        printf("���������ѡ��:");
        choice = getIntInput();
        switch (choice) {
            case 1:
            	system("cls");
                addMultiple(L);
                system("pause");
                system("cls");
                break;
            case 2: {
            	system("cls");
                printf("���������λ�ã�");
                int pos = getIntInput();
                printf("���������ֵ��");
                int val;
                scanf("%d", &val);
                if (Insert(L, pos, val)) {
                    printf("����ɹ���\n");
                } else {
                    printf("����ʧ�ܡ�\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case 3: {
            	system("cls");
            	Traverse(L);
                printf("������ɾ��λ�ã�");
                int delPos = getIntInput();
                int delVal;
                if (Delete(L, delPos, &delVal)) {
                    printf("ɾ���ɹ���ɾ����ֵΪ��%d\n", delVal);
                } else {
                    printf("ɾ��ʧ�ܡ�\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case 4:
            	system("cls");
                Traverse(L);
                system("pause");
                system("cls");
                break;
            case 5: {
            	system("cls");
                Node* middle = FindMiddle(L);
                if (middle) {
                    printf("�����е�ֵ��%d\n", middle->data);
                } else {
                    printf("����Ϊ�ջ���Ч��\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case 6:
            	system("cls");
                printf("�˳�����\n");
                system("pause");
                break;
            default:
            	system("cls");
                printf("��Чѡ��\n");
                system("pause");
                system("cls");
        }
    } while (choice != 6);
}

int main() {
	//��ʼ�� 
    LinkedList L;
    InitList(&L);
    
    Begin(L);
    
    return 0;
}
