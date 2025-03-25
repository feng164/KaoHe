#include "headers.h"

// ��ʼ����ջ
void InitStack(LinkStack* S) {
    S->top = NULL;
}

// �ж���ջ�Ƿ�Ϊ��
int StackEmpty(LinkStack S) {
    return S.top == NULL;
}

// ��ջ����
void Push(LinkStack* S, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = S->top;
    S->top = newNode;
}

// ��ջ����
int Pop(LinkStack* S, int* e) {
    if (StackEmpty(*S)) {
        return 0; // ջΪ�գ��޷���ջ
    }
    Node* temp = S->top;
    *e = temp->data;
    S->top = temp->next;
    free(temp);
    return 1;
}

// ��ȡջ��Ԫ��
int GetTop(LinkStack S, int* e) {
    if (StackEmpty(S)) {
        return 0; // ջΪ�գ��޷���ȡջ��Ԫ��
    }
    *e = S.top->data;
    return 1;
}

// ���������ȼ���
int priority(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '(': return 0; 
        default: return -1; // �ǲ�����
    }
}

// ��׺���ʽת��׺���ʽ
void InfixToPostfix(char* infix, char* postfix) {
    LinkStack S;
    InitStack(&S);
    int i = 0, j = 0;
    char ch;
    int topOp;

    while (infix[i] != '\0') {
        ch = infix[i];
        if (isdigit(ch)) { // ����ǲ�������ֱ�Ӽ����׺���ʽ
            postfix[j++] = ch;
        } else { // ����ǲ�����
            switch (ch) {
                case '(': // ������ֱ����ջ
                    Push(&S, ch);
                    break;
                case ')': // �����ţ�����ջ��������ֱ������������
                    while (GetTop(S, &topOp) && topOp != '(') {
                        postfix[j++] = topOp;
                        Pop(&S, &topOp);
                    }
                    Pop(&S, &topOp); // ����������
                    break;
                default: // ����������
                    while (GetTop(S, &topOp) && priority(topOp) >= priority(ch)) {
                        postfix[j++] = topOp;
                        Pop(&S, &topOp);
                    }
                    Push(&S, ch);
                    break;
            }
        }
        i++;
    }

    // ��ջ��ʣ��Ĳ����������׺���ʽ
    while (!StackEmpty(S)) {
        GetTop(S, &topOp);
        Pop(&S, &topOp);
        postfix[j++] = topOp;
    }
    postfix[j] = '\0'; // ����ַ���������
}

// ��׺���ʽ��ֵ
int EvaluatePostfix(char* postfix) {
    LinkStack S;
    InitStack(&S);
    int i = 0;
    char ch;
    int op1, op2, result;

    while (postfix[i] != '\0') {
        ch = postfix[i];
        if (isdigit(ch)) { // ����ǲ�������ֱ����ջ
            Push(&S, ch - '0'); // ���ַ�ת��Ϊ����
        } else { // ����ǲ�����
            Pop(&S, &op2); // ��������������
            Pop(&S, &op1);
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            Push(&S, result); // ����������ջ
        }
        i++;
    }

    Pop(&S, &result); // ���ս����ջ��
    return result;
}

int main() {
    char infix[100], postfix[100];
    printf("��������׺���ʽ(�������ֺͲ�����):");
    scanf("%s", infix);

    InfixToPostfix(infix, postfix);
    printf("��׺���ʽΪ:%s\n", postfix);

    int result = EvaluatePostfix(postfix);
    printf("������Ϊ:%d\n", result);

    return 0;
}

