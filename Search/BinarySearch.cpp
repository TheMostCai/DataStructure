#include <stdlib.h>
#include <iostream>
#include "../LinearTable/SequentialList2.cpp"

using namespace std;

//折半查找
int Binary_Search(SqList S, int key) {
    int low = 0, high = S.length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (S.data[mid] == key) {
            return mid;
        } else if (S.data[mid] < key) {  // low或者high不取mid
            high = mid - 1;
        } else if (S.data[mid] > key) {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    SqList S;
    InitList(S);
    S.data[0] = 1;
    S.data[1] = 2;
    S.data[2] = 3;
    S.data[3] = 4;
    S.data[4] = 5;
    S.data[5] = 6;
    S.data[6] = 7;
    S.data[7] = 8;
    S.length = 8;
    cout << "???" << endl;
    cout << Binary_Search(S, 4) << endl;
    return 0;
}