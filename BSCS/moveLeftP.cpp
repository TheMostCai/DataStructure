/*
2010年题
将n个整数存放到一维数组R中. 
试设计一个在时间和空间两方面都尽可能高效的算法. 
将R中保存的序列循环左移p(o<p<n)个位置.
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
算法1:
    设置一个大小为p的辅助数组temp, 先将前p个元素移动至此, 
    R中剩余元素左移p位, 最后将temp前p位元素移动到R的后p位
复杂度:
    时间O(n)
    空间O(n)

    很明显该算法有缺陷,空间复杂度过大
*/
int moveLeftP(int R[],int p,int RLength){
    int temp[p];
    for(int i=0;i<p;i++){
        temp[i]=R[i];
        cout<<temp[i]<<endl;
    }
    for(int i=p;i<RLength;i++){
        R[i-p]=R[i];
    }
    
    for(int i =0;i<p;i++){
        R[RLength-p+i]=temp[i];
    }
    return 1;
}


/*
算法2:
    数组前p位原地逆置, 剩余位数原地逆置.
    之后再整体原地逆置
复杂度:
    时间O(n)
    空间O(1)
*/
int reverse(int[],int,int);
int reverseToMove(int R[],int p,int RLength){
    reverse(R,0,p-1);
    reverse(R,p,RLength-1);
    reverse(R,0,RLength-1);
    return 1;
}

//将数组R从下标start开始,到下标end为止逆置
int reverse(int R[],int start,int end){
    for(int i=0;i<(end-start+1)/2;i++){
        int temp = R[start+i];
        R[start+i]=R[end-i];
        R[end-i]=temp;
    }
    return 1;
}

int main(){
    int R[10];
    for(int i=0;i<10;i++){
        R[i]=i;
    }

    reverseToMove(R,0,10);
    for(int i =0;i<10;i++){
        cout<<R[i]<<",";
    }
    // moveLeftP(R, 5,sizeof(R)/sizeof(R[0]));
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<R[i]<<",";
    // }
    return 1;
}
