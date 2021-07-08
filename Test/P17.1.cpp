#include <stdlib.h>
#include <iostream>
#include "..\LinearTable\SequentialList.cpp"

int deleteMin(SqList& S) {
    if (S.length == 0) {
        return false;
    }
    int min = S.data[0];
    int index = 0;
    for (int i = 0; i < S.length; i++) {
        min < S.data[0] ? min = min : min = S.data[i], index = i;
    }
    S.data[index] = S.data[S.length - 1];
    return min;
}