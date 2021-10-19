#include "LinearTable/SinglyLinkList.cpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

bool isObb(int num) {
    if (num / 2 == 0) {
        return true;
    } else {
        return false;
    }
}

long get(int number, int n) {
    if (isObb(number)) {
    }
}

int main() {
    LinkList list = new LNode;
    InitLinkList(list);
    for(int i =1;i<=10;i++){
        ListInsert(list,i,i);
    }
    toString(list);
    delete list;
    toString(list);
    return 0;
}