#include <iostream>
using namespace std;
// 经典dfs题，参数带 层数 和 剩余糖果数量
long long ans;
void dfs(int dep, int a, int b) {
	// 终止条件
	if (dep == 8) {
		if (a == 0 && b == 0) ans++;
		return;
	}
	// slove，枚举所有分剩余糖果给当前层数的方式
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			if (i + j >= 2 && i + j <= 5) {
				dfs(dep + 1, a - i, b - j);
			}
		}
	}
	return;
}

int main() {
	dfs(1, 9, 16);
	cout << ans << endl;

	return 0;
}