// 普通模拟，只不过判定条件有点难搞
// 判定 是否当前数(x) 的质因子仅含2/3 --> 唯一分解定理 --> 所有合数都能拆分成质数积
// 其实就是刷干净质因子，看看还省什么 --> 确定是否还含其他质因子
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<bool> arr(200008, 0);

bool correct(int x) {
	while (x % 2 == 0) x /= 2;			// 除净因子2
	while (x % 3 == 0) x /= 3;			// 除净因子3
	if (x == 1) return true;		// 若结果为1 --> 结果不含其他质因子
	return false;
}

void change(int x) {
	int t = x;
	for (int i = 2; t <= n; ++i) {
		arr[t] ? arr[t] = false : arr[t] = true;		// 改变对应位置 开关状态

		t = i * x;
	}
}

int main() {
	// init
	cin >> n;

	// judge
	for (int i = 1; i <= n; ++i) {
		if (correct(i)) {		// 判定
			change(i);			// 改变i的所有倍数 开关状态
		}
	}
	int sum = 0;
	for (auto i : arr) if (i) sum++;

	// cout
	cout << sum << endl;

	return 0;
}