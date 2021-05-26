/*
链表队列也可以带头结点或者不带头结点
*/
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct QNode {  //定义队列结点
    int data;
    QNode* next;
} QNode;

typedef struct {          //定义队列
    QNode *front, *rear;  //队列的队头和队尾指针
} LinkQueue;

//初始化队列(带头结点)
bool InitQueue(LinkQueue& Q) {
    //初始时队头和队尾指针都指向头结点
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    Q.front->next == NULL;
}

//判断是否为空
bool IsEmpty(LinkQueue Q) {
    if (Q.front == NULL) {
        return true;
    }
    return false;
}

//新元素入队
void EnQueue(LinkQueue& Q, int e) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;  //新结点插入到rear之后
    Q.rear = p;        //让rear指向新节点
}

//出队操作
bool DeQueue(LinkQueue& Q, int& e) {
    if (Q.front == Q.rear) {
        return false;
    }
    QNode* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {  //判断是否为最后一个元素出队
        Q.rear = Q.front;
    }
    free(p);
    return true;
}