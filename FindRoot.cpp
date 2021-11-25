//给定二叉排序树T,结点A,B. 寻找结点AB的第一个公共祖先
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct TreeNode {
    int data;
    TreeNode *lChild, *rChild;
} TNode, *Tree;

typedef struct StackNode {  //定义链表栈
    TNode node;
    StackNode* next;
} SNode, *LinkStack;

//入栈
//头插法
bool Push(LinkStack& S, TNode tnode) {
    StackNode* p = (StackNode*)malloc(sizeof(StackNode));
    p->node = tnode;
    p->next = S;
    S = p;
    return true;
}

//出栈操作
bool Pop(LinkStack& S, TNode& tnode) {
    tnode = S->node;
    StackNode* p = S;
    S = S->next;
    free(p);
    return true;
}

int findRoot(Tree T, TNode A, TNode B, TNode& common) {
    LinkStack S = new SNode;
    TNode* p = T;
    while (p->data != A.data) {  //根节点到节点A路径上所有结点入栈
        if (p->data > A.data) {
            Push(S, *p);
            p = p->lChild;
        } else if (p->data < A.data) {
            Push(S, *p);
            p = p->rChild;
        }
    }
    while (true) {  //找到第一个数值大于B的结点,即为AB第一个公共祖先
        Pop(S, *p);
        if (p->data > B.data) {
            common = *p;
            break;
        }
    }
}