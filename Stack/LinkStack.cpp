#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct StackNode {  //定义链表栈
    int data;
    StackNode* next;
} StackNode, *LinkStack;

//初始化链表栈
// S为栈顶指针
bool InitLinkStack(LinkStack& S) {
    S = NULL;
    return true;
}

//入栈
//头插法
bool Push(LinkStack& S, int e) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

//出栈操作
bool Pop(LinkStack& S, int& e) {
    e = S->data;
    StackNode* p = S;
    S = S->next;
    free(p);
    return true;
}

//判断是否为空
bool IsLinkStackEmpty(LinkStack& S) {
    if (S == NULL) {
        return true;
    }
    return false;
}

//取栈顶元素
bool GetTop(LinkStack& S, int& e) {
    if (S == NULL) {
        return false;
    }
    e = S->data;
    return true;
}