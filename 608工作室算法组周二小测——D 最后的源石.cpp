// 博弈论
// 先手状态下，假设剩余源石为以下数量：
// 0 --> 输
// 1、2 --> 赢
// 3 --> 输
// 4、5 --> 可以把对手逼到 3 --> 赢
// 6 --> 到 4、5 --> 会被对手逼到 3 --> 输
// ==> 剩余3的倍数个 --> 输
#include <iostream>
using namespace std;
long long n;

int main() {
	cin >> n;
	if (n % 3) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}