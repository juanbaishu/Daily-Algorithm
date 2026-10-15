// 需要常数级遍历 --> 正确节点
// 两个条件：
// 翻转后节点 满足 右增 --> [1,k] 左增，[k+1,n] 右增
// 翻转后交接处 右增 --> [1] <= [k+1]
// 关键：找能让 k 满足上述条件的位置
// 方法：1.计算前半段合适的终点 --> L --> k <= L ==> 此时[0,L]一定是左增的，因此[0,k]也是左增的
//		 2.计算后半段合适的起点 --> R --> R <= (k+1) ==> 此时[R,n]一定是右增的，因此[(k+1),n]也是右增的
//		 3.R-1 <= k <= L
//		 3.依次筛选符合上述条件的 k，同时满足 arr[1] <= arr[k+1] --> 找到答案，ans++
#include <iostream>
#include <vector>
using namespace std;
int T, n;
vector<int> arr(200008, 0);

int main() {
	cin >> T;
	while (T--) {
		// 1.init
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> arr[i];

		// 检查前半段
		int L = 1;
		while (L+1 <= n && arr[L] >= arr[L + 1]) L++;

		// 检查后半段
		int R = n;
		while (R-1 >= 1 && arr[R - 1] <= arr[R]) R--;

		// 2.judge
		// 检查交界处
		int l = max(R - 1, 1);		// R-1 可能到 0
		int r = L;
		int ans = 0;
		int k = l;
		for (; k <= r; ++k) {
			if (k + 1 <= n && arr[1] <= arr[k + 1]) {
				ans++;
			}

			// k+1 > n 的情况也需要算上，因为此时是 全左增
			if (k + 1 > n) ans++;
		}

		// 3.cout
		cout << ans << endl;
	}

	return 0;
}