#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    LNode* next;
} LNode, *LinkList;

//初始化单链表(带头结点)
void InitLinkList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
}

//在第i个位置插入元素e(带头结点)
//如果不带头结点,在第一个结点进行插入式需要单独处理
//第i个位置插入元素,意味着i-1结点的后继指向新的i结点,新的i结点指向旧的i结点
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1) {
        return false;
    }

    /*
    如果不带头结点,在第一个结点进行插入时需要进行特殊处理
    if (i == 1) {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->next = L;
        s->data = e;
        L = s;
        return true;
    }
    LNode* p;
    int j = 1;
    p = L;
    */

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

//在p结点之后插入元素e
bool InsertNextNode(LNode* p, int e) {
    if (p == NULL) {  //判断p结点是否合法
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = e;
    return true;
}

//在p结点之前插入元素e
//操你妈这个算法真的牛逼
bool InsertPreviousNode(LNode* p, LinkList L, int e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    /*
    用s结点代替p结点
    p结点的后继结点改为s
    p结点的元素改为e
    相当于完成了实际的在p结点之前插入
    */
    s->next = p->next;
    s->data = p->data;
    p->next = s;
    p->data = e;
}

//按位序删除(带头结点),将被删除结点的数据给e
bool ListDelete(LinkList& L, int i, int& e) {
    if (i < 1) {
        return false;
    }
    LNode* p;
    int j = 0;
    p = L;

    for (int j = 0; j < i && p != NULL; j++) {
        p = p->next;
    }

    if (p == NULL) {
        return false;
    }

    if (p->next == NULL) {  //判断p之后是否有结点
        return false;
    }
    LNode* q = p->next;  // q为要被删除的结点
    p->next = q->next;
    e = q->data;
    //释放被删除结点占用的内存! 这一步很重要!
    // C/C++没有内存自动回收机制!!!
    free(q);
    return true;
}

//删除指定结点p
bool DeleteNode(LinkList& L, LNode* p) {
    if (p == NULL) {
        return false;
    }
    //原理同上方前插算法
    //直接删除p,会丢失p的后继结点(没有p的前驱结点,这样p的前驱就无法指向p的后继结点)
    //找到p的后继q,令p代替q,之后删除q即可
    //如果p为最后一个结点,那么这段代码将会无法使用,故而需要考虑p为最后一个结点的情况
    LNode* q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//按位查找,返回第i个元素(带头结点的算法)
LNode* GetElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    LNode* p;
    int j = 0;  //当前p指向第几个结点
    p = L;

    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找,找到数据为e的结点
LNode* LocateElem(LinkList L, int e) {
    LNode* p = L->next;

    while (p != NULL && p->data != e) {
        p = p->next;
    }

    return p;
}

//求表的长度
int Length(LinkList L) {
    int length = 0;
    LNode* p = L;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

//尾插法建立单链表,n表示要插入的结点个数(带头结点)
LinkList List_TailInsert(LinkList& L, int n) {
    L = (LinkList)malloc(sizeof(LinkList));
    L->next = NULL;
    LNode *p, *r = L;  // r为表尾指针,p为新增结点的指针

    for (int i = 0; i < n; ++i) {
        p = (LNode*)malloc(sizeof(LNode));
        cin >> p->data;
        r->next = p;
        p->next = NULL;
        r = p;
    }
    return L;
}

// 头插法建立单链表,n表示要插入的结点个数(带头结点)
LinkList List_HeadInsert(LinkList& L, int n) {
    L = (LinkList)malloc(sizeof(LinkList));
    L->next = NULL;

    for (int i = 0; i < n; ++i) {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        cin >> p->data;
        p->next = L->next;  // p的后继指向头结点的后继
        L->next = p;        //头结点的后继再指向p
    }
    return L;
}