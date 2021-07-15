#include <stdlib.h>
#include <iostream>
#include "../LinearTable/SequentialList.cpp"

using namespace std;

void ShellSort(SqList& L) {
    // 0号位置为暂存单元
    int d, i, j;
    for (d = L.length / 2; d >= 1; i++) {
        if (L.data[i] < L.data[i - d]) {
            L.data[0] = L.data[i];
            for (j = i - d; j > 0 && L.data[0] < L.data[j]; j -= d) {
                L.data[j + d] = L.data[j];
            }
            L.data[j + d] = L.data[0];
        }
    }
}