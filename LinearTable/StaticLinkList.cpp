#include <stdlib.h>
#include <iostream>

using namespace std;

const int MaxSize = 10;  //静态链表长度

typedef struct Node {
    int data;
    int next;          //存储下一个结点的数组下标
} SLinkList[MaxSize];  //即为最大长度为MaxSize的Node数组,
                       //这个数组名为SLinkList(也就是静态链表)
