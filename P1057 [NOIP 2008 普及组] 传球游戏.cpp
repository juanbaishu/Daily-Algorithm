//// dp解法，当前位置情况数 == 上一步位置情况数 累加
///*	上一步位置 --> 左右两侧  ==>   dp[i][j] = dp[i-1][j左边] + dp[i-1][j右边]，不存在不能取的情况			--------------------------------正推
//*/
//#include <iostream>
////#define r(x) ((x-1)%n+1)   // x --> [1, n]，这个在 x-1 == 0时没用，0%n == 0
//using namespace std;
//long long dp[38][38];		// 第i次传球，球在j号位置的情况数
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//
//	// 计算
//	dp[0][1] = 1;		// init，其他位置都为0
//	for (int i = 1; i <= m; ++i) {		// 第0次不传球，所以从1开始
//		for (int j = 1; j <= n; ++j) {
//			int left = (j == 1) ? n : j - 1;
//			int right = (j == n) ? 1 : j + 1;
//			dp[i][j] = dp[i-1][left] + dp[i-1][right];
//		}
//	}
//	cout << dp[m][1] << endl;
//
//	return 0;
//}


// 记忆化dfs解法，当前位置情况数 == 后续成功情况数 累加
/*																												---------------------------------倒推
*/
#include <iostream>
#include <cstring>
//#define r(x) ((x-1)%n+1)   // x --> [1, n]，这个在 x-1 == 0时没用，0%n == 0
using namespace std;
long long memo[38][38];		// 第i次传球，球在j号位置能成功情况数
int n, m;

int dfs(int x, int y) {
	if (y < 1) y = n;			// 确保位置正确
	else if (y > n) y = 1;
	// 终止条件
	if (x > m) return 0;	// 越界

	// 成立条件
	if (x == m && y == 1) return 1;
	if (memo[x][y] != -1) return memo[x][y];			// 记忆化

	// 回溯
	return memo[x][y] = dfs(x + 1, y - 1) + dfs(x + 1, y + 1);		// 倒推

}

int main() {
	cin >> n >> m;

	// 计算
	memset(memo, -1, sizeof(memo));
	cout << dfs(0, 1) << endl;

	return 0;
}