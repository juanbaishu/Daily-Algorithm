#include <iostream>
#include <cstring>
using namespace std;
string s;
int dp[58][58];			// i --- j 区间的最优解

int main() {
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; ++i) dp[i][i] = 1;
	for (int len = 2; len <= n; ++len) {				// 枚举区间长度
		for (int l = 1; l + len - 1 <= n; ++l) {			// 枚举左端点
			int r = l + len - 1;	// 右端点
			// 要求只能连续段
			if (s[l] == s[r]) { dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]); }		// 两端相同 --> 不用再涂
			else
				for (int mid = l; mid < r; ++mid) {		// 枚举分割线
					dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
				}
		}
	}

	cout << dp[1][n] << endl;

	return 0;
}