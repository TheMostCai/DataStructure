//找到链表倒数第K个结点,若查找成功,则输出data的值并返回1,若查找不成功,则返回0
/*
事先设置两个指针p1和p2, p1先走,经过k个结点之后p2再走. 否则返回0;
*/

#include <iostream>
#include <stdlib.h>
#include "../LinearTable/SinglyLinkList.cpp"

using namespace std;

int findK(LinkList list, int k, int &data){
    LNode *p1 = list->next;
    LNode *p2 = list->next;
    int pass=1;//p1指向的是第几个结点
    while (p1->next!=NULL&&pass<k){
        p1=p1->next;
        pass++;
    }
    if(pass<k){//结点不足k个, 返回0
        return 0;
    }
    while(p1->next!=NULL){
        p1=p1->next;
        p2=p2->next;
    }
    data=p2->data;
    cout<<p2->data<<endl;
    return 1;
}

//测试程序
int main(){
    LinkList list = new LNode;
    InitLinkList(list);
    for(int i=1;i<=10;i++){
        ListInsert(list,i,i);
    }
    int data;
    cout<<findK(list,11,data)<<endl;
    return 1;
}