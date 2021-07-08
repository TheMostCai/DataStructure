#include <stdlib.h>
#include <iostream>
#include "../LinearTable/SequentialList2.cpp"

using namespace std;

//顺序查找, 返回值为key在动态数组的位置
int Search_Seq(SqList S, int key) {
    for (int i = 0; i < S.length && S.data[i] != key; i++) {
        return i;
    }
    return -1;
}

//一种设置"哨兵"的更高效算法, 若返回0则没有值为key的数据
int Search_Seq_E(SqList S, int key) {
    S.data[0] = key;  // S.data的第一个位置不存数据, 存入key用作"哨兵"
    for (int i = S.length; S.data[i] != key;
         i--) {  //不用每次都检测是否遍历完了表
        return i;
    }
}