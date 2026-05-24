// 注意到：若两字符串末尾字符相等，则一定被包含在最长公共子序列中
#include <iostream>
using namespace std;
string a;
string b;
int dp[1008][1008];		// 历史最优情况，对应最长的公共子序列长度，a中1--i区域 和 b中1--j区域  的最长公共子序列长度

int main() {
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	a = ' ' + a;		// 整体后移1位，这样就能从索引1开始
	b = ' ' + b;

	// 1. a[n] == b[m]  ==>  dp[n][m] = dp[n-1][m-1] + 1
	
	// 2. a[n] != b[m] ==>   1) dp[n][m] = dp[n-1][m]    2) dp[n][m] = dp[n][m-1]   3) dp[n][m] = dp[n-1][m-1]    分别对应三种情况：a[n]不在结果中、b[m]不在结果中、a[n]和b[m]都不在结果中
							// ==> dp[n][m] = max(dp[n-1][m], dp[n][m-1], dp[n-1][m-1])      ===>      dp[n][m] = max(dp[n-1][m], dp[n][m-1]) 
																								// 因为 3) 情况代表 a[n]和b[m]都不在结果中，和 2) 情况进入下轮循环 dp[n][m] = dp[n-1][m] 时的情况等价
																								// 也就是 dp[n-1][m-1]     <==>     dp[n][m-1] = dp[(n)-1][(m-1)]
	dp[0][0] = dp[1][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n][m] << endl;



	return 0;
}