#include <iostream>
using namespace std;
int n, k;
int ans;

// 单调不递减，last <= last + 1
void dfs(int lat, int stp, int sum) {		// last 上一个位置的值，step 当前位置，sum 之前值累和
	if (stp > k) {		// 结束条件
		if (sum == n) ans++;
		return;
	}
	for (int i = lat; i <= n - k + 1; ++i) {	// 形成了树状结构，单调不递减
		if (sum + (i * (k - stp + 1)) > n) break;									// 剪枝重点，预测后面能不能成立
		dfs(i, stp + 1, sum + i);
	}
	return;	// 写不写都行
}

void out() {
	cout << ans << endl;
}

int main() {
	cin >> n >> k;
	dfs(1, 1, 0);	// 每个值的取值范围 [1, n-(k-1)], max情况是其他位置都为1时
	out();
	return 0;
}