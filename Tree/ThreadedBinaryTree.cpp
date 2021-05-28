/*先序线索化时记得
visit(T);
if(T->ltag==0){
InThread(T->lChild, pre); } //对T的左子树进行线索化
InThread(T->rChild, pre);  //对T的右子树进行线索化
防止死循环
*/
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct ThreadNode {
    int data;
    ThreadNode *lChild, *rChild;
    int ltag, rtag;  //左右线索标志, 为0表示子树,为1表示线索
} ThreadNode, *ThreadTree;

//中序线索化. pre表示当前结点的前驱. 加&符号, 防止第二次线索化时pre又为NULL.
void InThread(ThreadTree T, ThreadNode*& pre) {
    if (T != NULL) {
        InThread(T->lChild, pre);  //对T的左子树进行线索化

        //对T进行线索化, T的前驱指向pre, pre的后继指向T
        if (T->lChild == NULL) {
            T->lChild = pre;
            T->ltag = 1;
        }
        if (pre->rChild == NULL) {
            pre->rChild = T;
            pre->rtag = 1;
        }
        pre = T;  // T线索化完成之后,pre移动到下一个结点

        InThread(T->rChild, pre);  //对T的右子树进行线索化
    }
}

//中序线索化二叉树
void CreateInThread(ThreadTree T) {
    ThreadNode* pre;
    if (T != NULL) {
        InThread(T, pre);
        //在T线索化完成之后, 设置最后一个结点的后继为NULL
        pre->rChild = NULL;
        pre->rtag = 1;
    }
};