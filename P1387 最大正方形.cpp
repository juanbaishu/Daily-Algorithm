// 前缀和减少重复计算的时间
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int n, m;
//int a[105][105];
//int sum[105][105];
//int res;
//
//int main() {
//	// 接收数据
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//	// 获取 前缀和 数据 (sum 数组)
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];	// 前缀和公式
//		}
//	}
//// 遍历计算正方形的情况
//	int l = 1;
//	// 控制边长 l
//	while (l <= min(n, m)) {
//		// 控制右下角坐标 i, j ，此时进行遍历，i、j 初始值刚好为 l
//		for (int i = l; i <= n; ++i) {
//			for (int j = l; j <= m; ++j) {
//				// 控制左上角坐标 x, y
//				int x = i - l + 1;
//				int y = j - l + 1;		
//				// 判断结果
//				if (sum[i][j] - sum[i][y - 1] - sum[x - 1][j] + sum[x - 1][y - 1] == l * l) {	// 判断 正方形内数字和 是否等于 面积
//					res = max(l, res);		// 新值 vs 旧值
//				}
//			}
//		}
//		l++;
//	}
//		// 输出结果
//	printf("%d", res);
//
//	return 0;
//}





// 二刷
// 尝试使用 DP 解题
#include <iostream>
using namespace std;
int n, m;
int arr[108][108];
int dp[108][108];		// 作为形成正方形的右下角处，保存对应正方形边长
int res = 0;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;			// 可以结合图像推导
			}
			else dp[i][j] = 0;
			if (dp[i][j] > res) res = dp[i][j];
		}
	}

	cout << res << endl;

	return 0;
}