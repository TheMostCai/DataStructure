#include <iostream>
using namespace std;
long sum = 0;
int T(int);
int main() {
    T(1024);
    return 0;
}

int T(int n) {
    sum++;
    if (n == 1) {
        return 1;
    } else {
        int temp = n / 2;
        sum++;
        temp = T(temp);
        sum++;
        temp *= 2;
        sum++;
        temp += n;
        sum++;
        cout << sum << endl;
        return temp;
    }
    return -1;
}