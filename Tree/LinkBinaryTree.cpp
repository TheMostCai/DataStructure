#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct BiTNode {
    int data;         //结点数据域
    BiTNode* lChild;  //左孩子
    BiTNode* rChild;  //右孩子
} BiTNode, *BiTree;

//初始化一个二叉树
bool InitTree(BiTree& root) {
    root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = 1;
    root->lChild = NULL;
    root->rChild = NULL;
    return true;
}

//先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}

//中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lChild);
        visit(T);
        InOrder(T->rChild);
    }
}

//后序遍历
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        visit(T);
    }
}

//输出结点的值
int visit(BiTNode* P) {
    cout << P->data << " " << endl;
    return P->data;
}