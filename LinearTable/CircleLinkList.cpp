#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    LNode* next;
} LNode, *CLinkList;

//初始化一个循环链表
bool InitCLinkList(CLinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    L->next = L;  //初试循环链表, 需要头结点的后继指向自己
    return true;
}

//判断循环链表是否为空
bool isEmpty(CLinkList& L) {
    if (L->next = L) {
        return true;
    }
    return false;
}

//判断结点是否是最后一个结点
bool isTail(CLinkList& L, LNode* p) {
    if (p->next == L) {
        return true;
    }
    return false;
}