// 直接用 unordered_map 存 数值-->位置，每轮查找就输出对应结果即可
#include <iostream>
#include <unordered_map>
using namespace std;

int n, t;
unordered_map<int, int> m;		// 数 --> 位置

int main() {
	// init
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tt;	cin >> tt;
		m[tt] = i;		// 存储位置
	}

	// judge
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int tt;	cin >> tt;
		int res = m[tt];
		cout << res << endl;
	}

	return 0;
}