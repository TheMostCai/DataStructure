#include <stdlib.h>
#include <iostream>

using namespace std;

const int MaxSize = 10;  //栈中最大元素的个数

typedef struct {  //定义一个顺序栈
    int data[MaxSize];
    int top;  //栈顶元素位置
} SqStack;

//初始化栈
void InitStack(SqStack& S) {
    S.top = -1;  //栈顶元素位置为-1, 表示栈为空
}

//判断栈是否为空
bool isStackEmpty(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    return false;
}

//向栈中插入元素
bool Push(SqStack& S, int e) {
    if (S.top == MaxSize - 1) {  //判断栈是否满
        return false;
    }
    S.data[++S.top] = e;  //先让栈顶元素位置+1, 插入新元素;
    return true;
}

//出栈操作
bool Pop(SqStack& S, int& e) {
    if (S.top == -1) {
        return false;
    }
    e = S.data[S.top--];  //先出栈再移动栈顶元素位置
    return true;
}

//读取栈顶元素
bool GetTop(SqStack& S, int& e) {
    if (S.top == -1) {
        return false;
    }
    e = S.data[S.top];
    return true;
}