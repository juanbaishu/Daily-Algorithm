//#include <iostream>
//using namespace std;
//int n, k;
//int ans;
//
//// 单调不递减，last <= last + 1
//void dfs(int lat, int stp, int sum) {		// last 上一个位置的值，step 当前位置，sum 之前值累和
//	if (stp > k) {		// 结束条件
//		if (sum == n) ans++;
//		return;
//	}
//	for (int i = lat; i <= n - k + 1; ++i) {	// 形成了树状结构，单调不递减
//		if (sum + (i * (k - stp + 1)) > n) break;									// 剪枝重点，预测后面能不能成立
//		dfs(i, stp + 1, sum + i);
//	}
//	return;	// 写不写都行
//}
//
//void out() {
//	cout << ans << endl;
//}
//
//int main() {
//	cin >> n >> k;
//	dfs(1, 1, 0);	// 每个值的取值范围 [1, n-(k-1)], max情况是其他位置都为1时
//	out();
//	return 0;
//}


// 二刷
//[起点] 将 7 分成 3 份
//│
//├─ 第1份取 1 (剩余6, 还要分2份)
//│    │
//│    ├─ 第2份取 1 (必须 ≥ 第1份的1。剩余5, 还要1份) ── 第3份只能取 5 = > 【方案: 1, 1, 5】
//│    │
//│    ├─ 第2份取 2 (必须 ≥ 第1份的1。剩余4, 还要1份) ── 第3份只能取 4 = > 【方案: 1, 2, 4】
//│    │
//│    └─ 第2份取 3 (必须 ≥ 第1份的1。剩余3, 还要1份) ── 第3份只能取 3 = > 【方案: 1, 3, 3】
//│
//└─ 第1份取 2 (剩余5, 还要分2份)
//│
//└─ 第2份取 2 (必须 ≥ 第1份的2。剩余3, 还要1份) ── 第3份只能取 3 = > 【方案: 2, 2, 3】
//
//【注意】：第1份为什么不能取 3？
//如果第1份取 3，剩余 4 还要分 2 份，且后面两份都必须 ≥ 3，至少需要 3 + 3 = 6，但只剩下 4 了，不够分。这就是“剪枝”。

#include <iostream>
using namespace std;
int max_val, min_val = 1;
int n, k;
int res = 0;

void dfs(int las_val, int step, int sum) {	// 上一位取值、当前第几位、目前累计值
	// 终止条件
	if (step > k) {
		if (sum == n) res++;
		return;
	}
	// 进行当前位 取值的循环
	for (int i = las_val; i <= max_val; i++) {
		// 剪枝，预测后面能不能成立，核心
		if (sum + (i * (k - step + 1)) > n) break;
		// 取下一位的值
		dfs(i, step + 1, sum + i);
	}

	return;
}

int main() {
	cin >> n >> k;
	max_val = n - k + 1;		// 每项最大的取值
	dfs(1, 1, 0);

	cout << res << endl;

	return 0;
}