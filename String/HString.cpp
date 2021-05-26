#include <stdlib.h>
#include <iostream>

using namespace std;

//采用动态数组实现, 不定长, 堆分配, 需要手动malloc和free
typedef struct {
    char* ch;
    int length;
} HString;