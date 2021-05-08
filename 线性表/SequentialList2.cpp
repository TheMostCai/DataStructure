#include <iostream>
#include <stdlib.h>

#define InitSize 10//

using namespace std;

//���嶯̬�����˳���
typedef struct{
	int *data;//��̬���������ָ��
	int MaxSize;//˳�����������
	int length;//˳���ĵ�ǰ����
}SqList;

// ��ʼ��˳���
void InitList(SqList &L){
	L.data = (int *)malloc(InitSize * sizeof(int));//����һƬ�����Ĵ洢�ռ�,����������stdlib.h��
	L.length = 0;
	L.MaxSize = InitSize;
}

//����˳���ĳ���
void IncreaseSize(SqList &L, int len){//Ҫ���ӵ�˳���, ���ӵĳ���
	int *p = L.data;
	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
	for ( int i = 0; i < L.length; i++ ){
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);//�ͷ�pռ�õ��ڴ�ռ�
}