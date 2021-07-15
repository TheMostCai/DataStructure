#include <stdlib.h>
#include <iostream>

using namespace std;

//直接插入排序
void InsertSort(int A[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        if (A[i] < A[i - 1]) {  // A[i]小于其前驱
            temp = A[i];        //将A[i]存储在temp中
            for (j = i - 1; j > 0 && A[j] > temp; --j) {
                A[j + 1] = A[j];  // temp左边的元素向后挪一位
            }
            A[j + 1] = temp;  //将temp插入到位置
        }
    }
}