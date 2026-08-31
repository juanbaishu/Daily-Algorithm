//#include <iostream>
//using namespace std;
//// 本题不能直接使用嵌套循环输出，因为 n 的个数决定了 for 循环的嵌套层数，也就是循环层数不能固定，因此不能这么遍历
//// 考虑抽象成二叉树，然后进行递归深度优先遍历
//
//int n;
//int ans[10];
//int flag[10];	// 标记位
//
//void prin() {
//	for (int i = 1; i <= n; ++i) {
//		printf("%5d", ans[i]);
//	}
//	cout << endl;
//}
//
//void dfs(int x) {
//	if (x > n) {
//		prin();
//		return ;
//	}
//	for (int i = 1; i <= n; ++i) {
//		if (flag[i] == 0) {		// 未标记
//			ans[x] = i;
//			flag[i] = 1;	// 标记
//			dfs(x + 1);		// 继续遍历下一位
//			flag[i] = 0;	// 返回这一层时标记消失，便于向后遍历
//		}
//	}
//	return ;
//}
//
//
//int main() {
//	cin >> n;
//	dfs(1);		// dfs(x)表示第几位的操作
//
//	return 0;
//}


// 二刷
#include <iostream>
using namespace std;
int n;
int res[10];
int flag[10] = { 0 };		// 数字是否被访问过
void print() {
	for (int i = 1; i <= n; ++i) {
		cout << "    " << res[i];
	} cout << endl;
}

void dfs(int x) {
	// 终止条件
	if (x > n) {
		print();		// 填满后输出当前结果
		return;
	}

	// 分配第 x 位的数
	for (int i = 1; i <= n; ++i) {				// 每次循环回来到循环(x==1)时，第一位分配向后走，2、3、4...
		if (flag[i] == 0) {
			res[x] = i;
			flag[i] = 1;
			dfs(x + 1);		// 继续填剩下没改的数
			flag[i] = 0;	// 回退
		}

	}
	return;
}

int main() {
	cin >> n;
	// 实现 n 个 for循环，通过 dfs
	dfs(1);

	return 0;
}