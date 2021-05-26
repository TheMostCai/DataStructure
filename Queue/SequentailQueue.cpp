#include <stdlib.h>
#include <iostream>

using namespace std;

const int MaxSize = 10;

typedef struct SqQueue {
    int data[MaxSize];
    int front, rear;  //分别标志队头和队尾
    //队头指向第一个元素,队尾指向最后一个元素的后一个
};

//初始化队列
bool InitSqQueue(SqQueue& Q) {
    Q.rear = 0;
    Q.front = 0;
}

//判断是否为空
bool IsSqQueueEmpty(SqQueue& Q) {
    if (Q.rear == Q.front) {
        return true;
    }
    return false;
}

//入队操作
bool EnQueue(SqQueue& Q, int e) {
    if ((Q.rear + 1) % MaxSize == Q.front) {  //判断队列是否已满
        return false;
    }
    Q.data[Q.rear] = e;
    //队尾指针指向最后一个位置时, 让队尾指针回到第一个位置
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//出队操作
bool DeQueue(SqQueue& Q, int& e) {
    if (IsSqQueueEmpty(Q)) {
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//取队列第一个
bool GetHead(SqQueue& Q, int& e) {
    if (IsSqQueueEmpty(Q)) {
        return false;
    }
    e = Q.data[Q.front];
    return true;
}

//求队列长度
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MaxSize) & MaxSize;
}