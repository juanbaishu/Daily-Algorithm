#include <iostream>
#include <cstring>
using namespace std;
int n;
int dp[308][308];			// 合并某区间时 的 最优情况
int sum[308];

int main() {
	cin >> n;
	memset(dp, 0x7f, sizeof(dp));
	int a[308];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		dp[i][i] = 0;					// 每个区间为 1 区域的代价 初始化为 0
	}

	for (int len = 2; len <= n; ++len) {				// 枚举区间长度
		for (int l = 1; l + len - 1 <= n; ++l) {		// 枚举区间左端点，右端点 <= n
			int r = l + len - 1;
			for (int mid = l; mid + 1 <= r; ++mid) {	// 枚举分割线
				dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r] + (sum[r] - sum[l-1]));		// 状态转移方程，子区间1最优解 + 子区间2最优解 + 合并代价
			}
		}
	}
	cout << dp[1][n] << endl;		// 区间 1 -- n 合并后的结果

	return 0;
}