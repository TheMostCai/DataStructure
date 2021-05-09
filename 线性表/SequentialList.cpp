#include <stdio.h>
#include <iostream>

#define MaxSize 10

using namespace std;

//定义顺序表
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//初始化顺序表
void InitList(SqList& L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] == 0;  //为顺序表设置默认值
    }
    L.length = 0;  //设置顺序表长度为0
}

//顺序表插入元素
//在位序为i的地方插入元素e
bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    if (L.length >= MaxSize) {
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;  //更新顺序表长度
    return true;
}

//顺序表删除操作
//删除位序为i的元素,并将被删除的值放到e中
bool ListDelete(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length) {  //判断合法性
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//找到顺序表中第一个值为e的元素
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

//找到顺序表中位序为i的元素,将它的值放到e中
bool GetElem(SqList L, int i, int& e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    return true;
}