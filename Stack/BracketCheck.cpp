//括号匹配算法

#include <stdlib.h>
#include <iostream>

using namespace std;

const int MaxSize = 20;

typedef struct {
    char data[MaxSize];
    int top;
} SqStack;

bool bracketCheck(char str[], int length) {
    SqStack S;

    S.top = -1;  // InitStack(S);

    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            // Push(S, str[i]);
            if (S.top > MaxSize - 1) {
                return false;
            }
            S.data[++S.top] = str[i];

        } else {
            if (S.top == -1) {  // isStackEmpty(S)
                return false;
            }
            char topElem;
            // Pop(S, topElem);
            if (S.top == -1) {
                return false;
            }
            topElem = S.data[S.top--];

            if (str[i] == ')' && topElem != '(') {
                return false;
            }
            if (str[i] == ']' && topElem != '[') {
                return false;
            }

            if (str[i] == '}' && topElem != '{') {
                return false;
            }
        }
    }
    return S.top == -1;
}