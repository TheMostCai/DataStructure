#include <iostream>
#include <stdio.h>

#define MaxSize 10

using namespace std;

//���徲̬�����˳���ṹ
typedef struct{
	int data[MaxSize];
	int length;
}SqList;

//��ʼ��˳���
void InitList(SqList &L){
	for ( int i = 0; i < MaxSize; i++ ){
		L.data[i] == 0;//Ϊ˳�������Ĭ��ֵ(����ʡ��)
	}
	L.length = 0;//����˳���ĳ���Ϊ0
}

//��˳�����в������
bool ListInsert(SqList &L, int i, int e){//��i��λ�򴦲���Ԫ��e
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
	L.length++;//����˳�����
	return true;
}

//ɾ��˳�����λ��Ϊi��Ԫ��
bool ListDelete(SqList &L, int i, int &e){//ɾ��λ��Ϊi��Ԫ��, ����ɾ��Ԫ�ص�ֵ����e
	if ( i < 1 || i>L.length ){//�ж�i�ĺϷ���
		return false;
	}
	e = L.data[i - 1];
	for ( int j = i; j < L.length; j++ ){
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

//����˳����е�һ��ֵΪe��Ԫ��.
int LocateElem(SqList L, int e){
	for ( int i = 0; i < L.length; i++ )		{
		if ( L.data[i] == e ){
			return i + 1;
		}
	}
	return 0;
}

//ȡ˳�����λ��Ϊi��Ԫ��,���������e��
bool GetElem(SqList L, int i,int &e){
	if ( i<1||i>L.length )	{
		return false;
	}
	e = L.data[i - 1];
	return true;
}