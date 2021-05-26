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
// using namespace std;
//
// int main(){
//	int sum = 0;
//
//	cout <<
//"鐠囩柉绶崗銉ょ娑撳弶鏆ｉ弫鏉挎嫲娴犵粯鍓伴弫鎵窗閻ㄥ嫮鈹栭弽锟�:"; 	int i;
//	while ( cin>>i ){
//		sum += i;
//		while ( cin.peek()==' ' ){
//			cin.get();
//		}
//		if ( cin.peek()=='\n' )	{
//			break;
//		}
//	}
//	cout << "缂佹挻鐏夐弰锟�:" << sum << endl;
//
//	return 0;
//}

//#include <iostream>
//
// using namespace std;
//
// void main(){
//	int num[10];
//
//	cout << "鐠囩柉绶崗锟�10娑擃亝鏆ｉ崹瀣殶閹癸拷:\n";
//	for ( int i = 0; i < 10; i++ )		{
//		cout << "鐠囩柉绶崗銉ь儑" << i + 1 << "娑擃亝鏆熼幑锟�:";
//		cin >> num[i];
//	}
//
//	int total = 0;
//	for ( int i = 0; i < 10; i++ )		{
//		total += num[i];
//	}
//
//	cout << "鏉堟挸鍙嗛弫鏉跨摟閻ㄥ嫭鈧鎷伴弰锟�:" << total;
//	cout << "楠炲啿娼庨崐鍏兼Ц:" << (float)total / 10;
//}

//#include <iostream>
//#include <string>
//
// using namespace std;
//
// int main(){
//	string str;
//	cout << "鐠囩兘娈㈡笟鑳翻閸忋儰绔存稉鎻掔摟缁楋拷";
//	getline(cin, str);
//	cout << str;
//	return 0;
//}

// #include <iostream>

// using namespace std;

// void test(int &x){
// 	x = 1024;
// }

// int main(){
// 	int x = 1;
// 	cout << x << "\n";
// 	test(x);
// 	cout << x << "\n";
// 	return 0;
// }