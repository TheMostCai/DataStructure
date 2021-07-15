#include <stdlib.h>
#include <iostream>
#include "../LinearTable/SequentialList.cpp"

using namespace std;

//直接插入排序
//本算法没有设置哨兵
void InsertSort(SqList& S) {
    int temp, i, j;
    for (i = 1; i < S.length; i++) {
        if (S.data[i] < S.data[i - 1]) {
            temp = S.data[i];
            S.data[i] = S.data[i - 1];
            for (j = i - 1; j >= 0 && temp < S.data[j]; --j) {
                S.data[j + 1] = S.data[j];
            }
            S.data[j + 1] = temp;
        }
    }
}

int main() {
    SqList S;
    InitList(S);
    S.data[0] = 3;
    S.data[1] = 1;
    S.data[2] = 4;
    S.data[3] = 2;
    S.data[4] = 5;
    S.data[5] = 8;
    S.data[6] = 7;
    S.data[7] = 6;
    S.length = 8;
    for (int i = 0; i < S.length; i++) {
        cout << S.data[i] << ",";
    }
    cout << endl;
    InsertSort(S);

    int i;
    for (i = 0; i < S.length; i++) {
        cout << S.data[i] << ",";
    }
    cout << endl;
    return 0;
}