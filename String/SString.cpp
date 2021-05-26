#include <stdlib.h>
#include <iostream>

using namespace std;

//采用静态数组实现, 定长, 不需要malloc
const int MaxLen = 255;
typedef struct {
    char ch[MaxLen];  // ch[0]不存放数据
    int length;
} SString;

//求子串
//参数分别表示 要求的子串, 主串, 起始点, 子串长度
bool SubString(SString& Sub, SString S, int pos, int len) {
    //防止子串越界
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (int i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

//比较操作
int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    //运行至此,说明扫描过的所有字符串都相同, 则开始比较串的长度
    return S.length - T.length;
}

//定位子串的位置
int Index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;
    SString sub;
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    return 0;
}