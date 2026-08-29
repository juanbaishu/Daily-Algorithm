#include <iostream>
using namespace std;
int n;

int main() {
    cin >> n;
    // 过程
    // p1 p2
    //  ↓ ↓
    //  1 2 3 4 --> 3 3 4 --> 6 4 --> 10
    // sum:      3   --->  9   --> 19
    // sum变化量: 3   --->  6  -->  10，sum累加变化量就行
    int y = 0;      // 记录 sum变化值
    int x = 0;      // 记录下一堆的值
    int sum = 0;    // 记录结果
    if (n == 1) { cout << sum << endl; return 0; }
    cin >> y;
    for (int i = 1; i <= n-1; ++i) {
        cin >> x;
        y = y + x;
        sum += y;
    }

    cout << sum << endl;

    return 0;
}