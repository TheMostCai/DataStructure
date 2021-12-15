#include <stdlib.h>
#include <iostream>

using namespace std;

// const int MaxSize = 20;

// typedef struct {
//     char data[MaxSize];
//     int top;
// } SqStack;

/*bool bracketCheck(char str[], int length) {
    SqStack S;

    S.top = -1;  // InitStack(S);

    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            // Push(S, str[i]);
            if (S.top > MaxSize - 1) {
                return false;
            }
            S.data[++S.top] = str[i];

        } else {
            if (S.top == -1) {  // isStackEmpty(S)
                return false;
            }
            char topElem;
            // Pop(S, topElem);
            if (S.top == -1) {
                return false;
            }
            topElem = S.data[S.top--];

            if (str[i] == ')' && topElem != '(') {
                return false;
            }
            if (str[i] == ']' && topElem != '[') {
                return false;
            }

            if (str[i] == '}' && topElem != '{') {
                return false;
            }
        }
    }
    return S.top == -1;
}*/
int sum=0;

typedef struct Node{
    int data;
    Node* next;
}Node, *List;

int printList(List L){
    Node *p=L;
    while(L->next!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
    return 0;
}
int main() {
    List L = new Node;
    Node* last=L;
    for (int i = 0; i < 5; i++){
        Node* p = new Node;
        p->data=i;
        last->next=p;
        last=p;
    }
    last->next=NULL;
    Node* d=L->next->next->next;
    L->next->next->next=d->next;
    delete d;
    printList(L);
    return 0;
}
