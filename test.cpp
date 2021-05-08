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
//	cout << "请输入一串整数和任意数目的空格:";
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
//	cout << "结果是:" << sum << endl;
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
//	cout << "请输入10个整型数据:\n";
//	for ( int i = 0; i < 10; i++ )		{
//		cout << "请输入第" << i + 1 << "个数据:";
//		cin >> num[i];
//	}
//
//	int total = 0;
//	for ( int i = 0; i < 10; i++ )		{
//		total += num[i];
//	}
//
//	cout << "输入数字的总和是:" << total;
//	cout << "平均值是:" << (float)total / 10;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(){
//	string str;
//	cout << "请随便输入一串字符";
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