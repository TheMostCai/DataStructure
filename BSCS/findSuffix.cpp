/*
2012年
采用带头结点的单链表保存单词, 两个单词有相同后缀时, 可共享相同的后缀存储空间
如, "loding"和"being"
设str1和str2分别指向两个单词所在单链表的头结点, 链表结构为(data,next)
设计一个时间上尽可能高效的算法,找出二者的共同后缀起始位置p
*/

/*
基本思想:
    遍历一遍第一个单词, 将其长度记为length1. 遍历第二个单词, 长度记为length2
    相减得长度差offset, 长度长的先走offset位, 之后短的再走.
    每遍历一个结点, 判断一次是否相同, 相同的即为共同后缀 
 */

//没有验证准确性
#include <iostream>
#include <stdlib.h>
#include "../LinearTable/SinglyLinkList.cpp"

using namespace std;

int abs(int,int);
LNode* findSuffix(LinkList,LinkList);

LNode* findSuffix(LinkList str1, LinkList str2){
    int length1=0,length2=0;
    LNode* p1 = str1;
    LNode* p2 = str2;
    while(p1->next!=NULL){//计算str1长度
        p1=p1->next;
        length1++;
    }
    while(p2->next!=NULL){//计算str2长度
        p2=p2->next;
        length2++;
    }
    int offset = abs(length1,length2);//求二者长度的差值
    p1=str1;
    p2=str2;
    if(length1>length2){
        for(int i=0;i<offset;i++){
            p1=p1->next;
        }
    }else{
        for(int i=0;i<offset;i++){
            p2=p2->next;
        }
    }
    while(true){
        p1=p1->next;
        p2=p2->next;
        if(p1==p2){
            return p1;
        }
    }
}

int abs(int a,int b){
    if(a>=b){
        return a-b;
    }else{
        return b-a;
    }
}

int main(){
    LinkList str1=new LNode;
    LinkList str2=new LNode;
    InitLinkList(str1);
    InitLinkList(str2);
    List_TailInsert(str1,7);
    List_TailInsert(str2,5);
    toString(str1);
    toString(str2);
    return 1;
}