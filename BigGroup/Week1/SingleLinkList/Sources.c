#include "Headers.h"

// 初始化链表
void InitList(LinkedList* L) {
    *L = (Node*)malloc(sizeof(Node));
    if (*L == NULL) {
        printf("内存分配失败!\n");
        exit(1);
    }
    (*L)->next = NULL;
}

// 添加新节点
void add(LinkedList L, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
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

// 输入多个值并添加到链表
void addMultiple(LinkedList L) {
    printf("请输入数字（输入非数字结束）：\n");
    int data;
    while (scanf("%d", &data) == 1) {
        add(L, data);
    }
    while (getchar() != '\n') {}  // 清空缓冲区
    printf("添加完成。\n");
}

// 在指定位置插入新节点
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
        printf("内存分配失败\n");
        return 0;
    }
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return 1;
}

// 删除节点
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

// 遍历链表
void Traverse(LinkedList L) {
    Node* p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 找到链表的中点
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
                printf("请输入正数:");
            } else {
                return num;  
            }
        } else {
            while (getchar() != '\n');  
            printf("您输入的不是数字，请重新输入:");
        }
    }
}

void Begin(LinkedList L) {
    int choice;
    do {
        printf("\n请选择操作：\n");
        printf("1. 添加多个值\n");
        printf("2. 插入值\n");
        printf("3. 删除值\n");
        printf("4. 遍历链表\n");
        printf("5. 找到链表中点\n");
        printf("6. 退出\n");
        printf("请输入你的选择:");
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
                printf("请输入插入位置：");
                int pos = getIntInput();
                printf("请输入插入值：");
                int val;
                scanf("%d", &val);
                if (Insert(L, pos, val)) {
                    printf("插入成功。\n");
                } else {
                    printf("插入失败。\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case 3: {
            	system("cls");
            	Traverse(L);
                printf("请输入删除位置：");
                int delPos = getIntInput();
                int delVal;
                if (Delete(L, delPos, &delVal)) {
                    printf("删除成功，删除的值为：%d\n", delVal);
                } else {
                    printf("删除失败。\n");
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
                    printf("链表中点值：%d\n", middle->data);
                } else {
                    printf("链表为空或无效。\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case 6:
            	system("cls");
                printf("退出程序。\n");
                system("pause");
                break;
            default:
            	system("cls");
                printf("无效选择。\n");
                system("pause");
                system("cls");
        }
    } while (choice != 6);
}

int main() {
	//初始化 
    LinkedList L;
    InitList(&L);
    
    Begin(L);
    
    return 0;
}
