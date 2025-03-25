#include "headers.h"

// 初始化链栈
void InitStack(LinkStack* S) {
    S->top = NULL;
}

// 判断链栈是否为空
int StackEmpty(LinkStack S) {
    return S.top == NULL;
}

// 入栈操作
void Push(LinkStack* S, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = S->top;
    S->top = newNode;
}

// 出栈操作
int Pop(LinkStack* S, int* e) {
    if (StackEmpty(*S)) {
        return 0; // 栈为空，无法出栈
    }
    Node* temp = S->top;
    *e = temp->data;
    S->top = temp->next;
    free(temp);
    return 1;
}

// 获取栈顶元素
int GetTop(LinkStack S, int* e) {
    if (StackEmpty(S)) {
        return 0; // 栈为空，无法获取栈顶元素
    }
    *e = S.top->data;
    return 1;
}

// 操作符优先级表
int priority(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '(': return 0; 
        default: return -1; // 非操作符
    }
}

// 中缀表达式转后缀表达式
void InfixToPostfix(char* infix, char* postfix) {
    LinkStack S;
    InitStack(&S);
    int i = 0, j = 0;
    char ch;
    int topOp;

    while (infix[i] != '\0') {
        ch = infix[i];
        if (isdigit(ch)) { // 如果是操作数，直接加入后缀表达式
            postfix[j++] = ch;
        } else { // 如果是操作符
            switch (ch) {
                case '(': // 左括号直接入栈
                    Push(&S, ch);
                    break;
                case ')': // 右括号，弹出栈顶操作符直到遇到左括号
                    while (GetTop(S, &topOp) && topOp != '(') {
                        postfix[j++] = topOp;
                        Pop(&S, &topOp);
                    }
                    Pop(&S, &topOp); // 弹出左括号
                    break;
                default: // 其他操作符
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

    // 将栈中剩余的操作符加入后缀表达式
    while (!StackEmpty(S)) {
        GetTop(S, &topOp);
        Pop(&S, &topOp);
        postfix[j++] = topOp;
    }
    postfix[j] = '\0'; // 添加字符串结束符
}

// 后缀表达式求值
int EvaluatePostfix(char* postfix) {
    LinkStack S;
    InitStack(&S);
    int i = 0;
    char ch;
    int op1, op2, result;

    while (postfix[i] != '\0') {
        ch = postfix[i];
        if (isdigit(ch)) { // 如果是操作数，直接入栈
            Push(&S, ch - '0'); // 将字符转换为整数
        } else { // 如果是操作符
            Pop(&S, &op2); // 弹出两个操作数
            Pop(&S, &op1);
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            Push(&S, result); // 将计算结果入栈
        }
        i++;
    }

    Pop(&S, &result); // 最终结果在栈顶
    return result;
}

int main() {
    char infix[100], postfix[100];
    printf("请输入中缀表达式(包含数字和操作符):");
    scanf("%s", infix);

    InfixToPostfix(infix, postfix);
    printf("后缀表达式为:%s\n", postfix);

    int result = EvaluatePostfix(postfix);
    printf("计算结果为:%d\n", result);

    return 0;
}

