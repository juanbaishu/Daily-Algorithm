//// DP解法，当前位置情况数 == 上一步到达这里的情况数 累加
///* 卒 --> 向下/向右移动 ==>       1.如果当前位置能到 --> 当前位置只能从 左边/上方 过来，所以 dp[i][j] = dp[i-1][j] + dp[i][j-1];
// *                                2.如果当前位置不能到 --> dp[i][j] = 0;
//*/
//#include <iostream>
//#include <utility>
//#define PII pair<int, int>
//#define ll long long
//#define check(y, x) (1<=y&&y<=n&&1<=x&&x<=m)
//using namespace std;
//ll dp[28][28];			// 最大结果为 40!/20!*20! > INT_MAX		----------------------------------------------------------------- 前面 --> 当前位置记录
//int bad[28][28];		// 记录不能走的地方
//PII horse, dest;
//int n, m;		// 总行/列
//
//int main() {
//	// 录入数据
//	cin >> dest.first >> dest.second >> horse.first >> horse.second;	dest.first++, dest.second++, horse.first++, horse.second++;		// 坐标变成从 (1, 1) 开始
//	n = dest.second, m = dest.first;
//	bad[horse.second][horse.first] = 1;
//	int y = horse.second, x = horse.first;
//	int t[8][2] = { {y - 2, x - 1}, {y - 2, x + 1}, {y - 1, x - 2}, {y - 1, x + 2}, {y + 1, x - 2}, {y + 1, x + 2}, {y + 2, x - 1},{y + 2,x + 1} };
//	for (int i = 0; i < 8; ++i) if (check(t[i][0], t[i][1])) bad[t[i][0]][t[i][1]] = 1;
//
//	// 计算数据
//	dp[1][1] = 1;		// 起始点不会是马控制点
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			if (i == 1 && j == 1) continue;		// 跳过计算起始点
//			if (bad[i][j] == 1) dp[i][j] = 0;				// 2 情况
//			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];	// 1 情况
//		}
//	}
//	cout << dp[n][m] << endl;
//
//	return 0;
//}


// 记忆化dfs解法，当前位置情况 == 后续情况返还									
/*	卒 --> 向下/向右移动 ==>      dfs(y,x) = dfs(y+1,x) + dfs(y, x+1)		==记忆化==>		 1. if(memo[y][x]) return memo[y][x];
																							 2. return memo[y][x] = dfs(y+1, x) + dfs(y, x+1)
*/
#include <iostream>
#include <utility>
#include <cstring>
#define PII pair<int, int>
#define ll long long
#define check(y, x) (1<=y&&y<=n&&1<=x&&x<=m)
using namespace std;
ll memo[28][28];			// 记录后续情况数		----------------------------------------------------------------- 当前位置记录 <--- 后续
int bad[28][28];		// 记录不能走的地方
PII horse, dest;
int n, m;		// 总行/列

ll dfs(int y, int x) {
	// 终止条件
	if (y > n || x > m) return 0;				// 越界
	if (bad[y][x]) return 0;					// 此路径不能走
	if (y == n && x == m) return 1;				// 到达终点	---> 返还

	// 累加情况
	if (memo[y][x] != -1) return memo[y][x];		// 当前位置计算过 --> 记忆化

	// 回溯
	return memo[y][x] = dfs(y + 1, x) + dfs(y, x + 1);		// 向后走，记忆化
}

int main() {
	// 录入数据
	cin >> dest.first >> dest.second >> horse.first >> horse.second;	dest.first++, dest.second++, horse.first++, horse.second++;		// 坐标变成从 (1, 1) 开始
	n = dest.second, m = dest.first;
	bad[horse.second][horse.first] = 1;
	int y = horse.second, x = horse.first;
	int t[8][2] = { {y - 2, x - 1}, {y - 2, x + 1}, {y - 1, x - 2}, {y - 1, x + 2}, {y + 1, x - 2}, {y + 1, x + 2}, {y + 2, x - 1},{y + 2,x + 1} };
	for (int i = 0; i < 8; ++i) if (check(t[i][0], t[i][1])) bad[t[i][0]][t[i][1]] = 1;

	// 计算数据
	memset(memo, -1, sizeof(memo));			// -1 --> 未算过当前位置
	cout << dfs(1, 1) << endl;

	return 0;
}