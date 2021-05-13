#include <stdlib.h>
#include <iostream>
#include "LinearTable\SinglyLinkList.cpp"

int main() {
    LinkList L;
    InitLinkList(L);

    List_TailInsert(L, 5);
    toString(L);
    int e;
    ListDelete(L, 3, e);
    toString(L);
    system("pause");

    return 0;
}