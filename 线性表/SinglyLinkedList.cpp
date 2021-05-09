#include <stdlib.h>
#include <iostream>

typedef struct LNode {
    int data;
    LNode* next;
} LNode, *LinkList;

//初始化单链表
void InitLinkList(LinkList& L) {
    LNode L;
    L->next = NULL;
}

//在第i个位置插入元素e(带头结点)
//如果不带头结点,在第一个结点进行插入式需要单独处理
//第i个位置插入元素,意味着i-1结点的后继指向新的i结点,新的i结点指向旧的i结点
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1) {
        return false;
    }
    LNode* p;   //指向当前扫描到的结点
    int j = 0;  //当前指针指向的结点
    p = L;      // L指向头结点, 头结点是第0个结点(不存数据)

    while (p != NULL && j < i - 1) {  //循环找到第i-1个结点
        p = p->next;
        j++;
    }

    if (p == NULL) {  // i值不合法
        return false;
    }

    LNode* s = (LNode*)malloc(sizeof(LNode));
    //插入新的结点
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}