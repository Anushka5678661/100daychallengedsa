#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* push(Node* top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top, int* value) {
    if (top == NULL) return NULL;
    *value = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            stack = push(stack, atoi(token));
        } else {
            int val2, val1;
            stack = pop(stack, &val2);
            stack = pop(stack, &val1);
            int result;
            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: result = 0;
            }
            stack = push(stack, result);
        }
        token = strtok(NULL, " ");
    }
    int finalResult;
    stack = pop(stack, &finalResult);
    return finalResult;
}

int main() {
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    return 0;
}