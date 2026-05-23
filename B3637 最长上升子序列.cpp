/*
// dfs暴力做法								但是时间复杂度为 O(2^n)，肯定会超时，数据量 n<=5000，至少应该优化到 n^2
#include <iostream>
using namespace std;
int n;
int a[5008];
int a_len_t[5008];		// 暂时最大长度
int a_max[5008];		// 最后最大长度
int res = 0;

void dfs(int x) {
	a_max[x] = max(a_max[x], a_len_t[x]);
	if (x + 1 > n) return;
	for (int i = x + 1; i <= n; ++i) {
		if (a[i] > a[x]) { a_len_t[i] = a_len_t[x]+1; dfs(i); }
	}
	a_len_t[x]--;	return;		// 回溯
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a_len_t[i] = 1;		// 都初始化为 1
	}
	// 找以第 i 个数为结尾的上升子序列中，最大的长度
	for (int i = 1; i <= n; ++i)	dfs(i);
	
	for (int i = 1; i <= n; ++i) res = max(res, a_max[i]);
	cout << res << endl;

	return 0;
}
*/

// 动态规划做法								时间复杂度为 O(n^2)
// 核心是 状态数组dp[] ==> 存历史最优情况      站在现在-->过去，找状态转移方程，有点想递归
#include <iostream>
#define N 5008
using namespace std;
int dp[N];		// 只需要保留 历史最优解，到当前位置的最长长度
int a[N];		// 当前位置对应的数
int n;
int res;

// 站在过去 --> 未来
void DP_1() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] > a[i]) { dp[j] = max(dp[j], dp[i] + 1); }			// 状态传递方程，只需要保存最长情况-->dp[]
		}
	}
}

// 站在现在 --> 过去
void DP_2() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (a[j] < a[i]) { dp[i] = max(dp[i], dp[j] + 1); }
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) { cin >> a[i]; dp[i] = 1; }

	DP_2();
	for (int i = 1; i <= n; ++i) res = max(res, dp[i]);
	cout << res << endl;
	return 0;
}
