////#include <stdio.h>
////
////typedef struct{
////	char no[20];
////}SqList;
////
////void InitList(SqList &l){
////
////}
//
//#include <iostream>
//
//using namespace std;
//
//int main(){
//	int sum = 0;
//
//	cout << "������һ��������������Ŀ�Ŀո�:";
//	int i;
//	while ( cin>>i ){
//		sum += i;
//		while ( cin.peek()==' ' ){
//			cin.get();
//		}
//		if ( cin.peek()=='\n' )	{
//			break;
//		}
//	}
//	cout << "�����:" << sum << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void main(){
//	int num[10];
//
//	cout << "������10����������:\n";
//	for ( int i = 0; i < 10; i++ )		{
//		cout << "�������" << i + 1 << "������:";
//		cin >> num[i];
//	}
//
//	int total = 0;
//	for ( int i = 0; i < 10; i++ )		{
//		total += num[i];
//	}
//
//	cout << "�������ֵ��ܺ���:" << total;
//	cout << "ƽ��ֵ��:" << (float)total / 10;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(){
//	string str;
//	cout << "���������һ���ַ�";
//	getline(cin, str);
//	cout << str;
//	return 0;
//} 

#include <iostream>

using namespace std;

void test(int &x){
	x = 1024;
}

int main(){
	int x = 1;
	cout << x << "\n";
	test(x);
	cout << x << "\n";
	return 0;
}