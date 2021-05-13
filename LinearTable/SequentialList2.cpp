#include <stdlib.h>
#include <iostream>

#define InitSize 10  //

using namespace std;

//定义动态分配的顺序表
typedef struct {
    int* data;    //动态分配数组的指针
    int MaxSize;  //顺序表的最大容量
    int length;   //顺序表的当前长度
} SqList;

// 初始化顺序表
void InitList(SqList& L) {
    //申请一片连续的存储空间,函数定义在stdlib.h中
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加顺序表的长度
void IncreaseSize(SqList& L, int len) {  //要增加的顺序表, 增加的长度
    int* p = L.data;
    L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);  //释放p占用的内存空间
}