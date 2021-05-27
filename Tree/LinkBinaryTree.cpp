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

//求二叉树深度
int treeDepth(BiTree T) {
    if (T == NULL) {
        return 0;
    } else {
        int l = treeDepth(T->lChild);
        int r = treeDepth(T->rChild);
        //树的深度=max{左子树深度,右子树深度}+1
        return l > r ? l + 1 : r + 1;
    }
}

//定义层次遍历中所需的队列结点
typedef struct QNode {
    BiTree* data;
    QNode* nexe;
} QNode;

//定义层次遍历中所需要的队列
typedef struct {
    QNode *front, *rear;
} LinkQueue;

//层序遍历树
void LevelOrder(BiTree T) {
    LinkQueue Q;
    //初始化Q
    // InitQueue(Q);
    BiTree p;
    //向队列中插入根节点
    // EnQueue(Q,T)
    while (1) {  //队列非空
        //根节点出队
        // DeQueue(Q, p);
        visit(p);
        if (p->lChild != NULL) {
            //左孩子结点入队
            // EnQueue(Q,p->lChild);
        }
        if (p->rChild != NULL) {
            //右孩子入队
            // EnQueue(Q,p->rChild);
        }
    }
}