// 01背包问题
// 最优子结构 --> 状态转移方程
#include <iostream>
#include <cstring>
using namespace std;
int t, m;
int tim[108];
int value[108];
int dp[108][1008];

int main() {
	cin >> t >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> tim[i];
		cin >> value[i];
	}

	// 01背包求解
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; ++i) {			// 第 i 个物品
		for (int j = 1; j <= t; ++j) {		// 剩余 j 时间
			// 拿不下的情况
			if (j < tim[i]) { dp[i][j] = dp[i - 1][j]; }
			// 拿得下的情况
			else {	// 分为 拿得下 和 拿不下 两种情况
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - tim[i]] + value[i]);
			}
		}
	}

	cout << dp[m][t] << endl;

	return 0;
}