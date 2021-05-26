#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct DNode {
    int data;
    DNode *prior, *next;  //分别表示前驱结点, 后继结点
} DNOde, *DLinkList;

//初始化双链表(带头结点)
bool InitDLinkList(DLinkList& L) {
    L = (DNode*)malloc(sizeof(DNode));  //头结点
    L->next = NULL;
    L->prior = NULL;
    return true;
}

//在双链表中位序为i的位置插入元素e
bool DListInsert(DLinkList& L, int i, int e) {
    DNode* p = GetElem(L, i);
    if (p == NULL) {
        return false;
    }
    DNode* pp = p->prior;                      // p的前驱结点
    DNode* s = (DNode*)malloc(sizeof(DNode));  //要插入的结点
    s->data = e;

    pp->next = s;
    s->prior = pp;

    s->next = p;
    p->prior = s;

    return true;
}

//删除双链表中位序为i的结点
bool DListDelete(DLinkList& L, int i) {
    DNode* p = GetElem(L, i);
    if (p == NULL) {
        return false;
    }
    p->prior->next = p->next;   // p前驱的后继指向p的后继
    p->next->prior = p->prior;  // p后继的前驱指向p的前驱
    free(p);                    //删除p占用的内存空间
    return true;
}

//获取双链表D中位序为i的结点
DNode* GetElem(DLinkList& L, int i) {
    if (i < 0) {
        return NULL;
    }
    DNode* p = L;
    int j = 0;

    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return NULL;
    }
    return p;
}