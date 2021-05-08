#include <iostream>
#include <stdio.h>

#define MaxSize 10

using namespace std;

//定义静态分配的顺序表结构
typedef struct{
	int data[MaxSize];
	int length;
}SqList;

//初始化顺序表
void InitList(SqList &L){
	for ( int i = 0; i < MaxSize; i++ ){
		L.data[i] == 0;//为顺序表设置默认值(可以省略)
	}
	L.length = 0;//设置顺序表的长度为0
}

//对顺序表进行插入操作
bool ListInsert(SqList &L, int i, int e){//在i的位序处插入元素e
	if ( i<1 || i>L.length + 1 ){
		return false;
	}
	if ( L.length >= MaxSize ){
		return false;
	}
	for ( int j = L.length; j >= i; j-- ){
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;//更正顺序表长度
	return true;
}

//删除顺序表中位序为i的元素
bool ListDelete(SqList &L, int i, int &e){//删除位序为i的元素, 将被删除元素的值赋给e
	if ( i < 1 || i>L.length ){//判断i的合法性
		return false;
	}
	e = L.data[i - 1];
	for ( int j = i; j < L.length; j++ ){
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

//查找顺序表中第一个值为e的元素.
int LocateElem(SqList L, int e){
	for ( int i = 0; i < L.length; i++ )		{
		if ( L.data[i] == e ){
			return i + 1;
		}
	}
	return 0;
}

//取顺序表中位序为i的元素,并将其放在e中
bool GetElem(SqList L, int i,int &e){
	if ( i<1||i>L.length )	{
		return false;
	}
	e = L.data[i - 1];
	return true;
}