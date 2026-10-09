// 按二维差分 --> 累计前缀和 --> 计算区间和
#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;

int T, n, m, q;
vector<vector<ull> > sum(1008, vector<ull>(1008, 0));
//vector<ull> res;

//template <class T>
//T getXorSum(T* begin, T* end) {
//	T ret = 0;
//	for (T* it = begin; it != end; ++it) ret ^= *it;
//	return ret;
//}

int main() {
	// init
	cin >> T;
	while (T--) {
		//res.clear();
		// init
		cin >> n >> m >> q;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				ull t; cin >> t;
				sum[i][j] = t + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];		// 差分传递
			}
		}

		// execute
		ull ans = 0;
		while (q--) {
			int x_l, y_l, x_r, y_r;
			cin >> y_l >> x_l >> y_r >> x_r;
			ull res = sum[y_r][x_r] - sum[y_r][x_l - 1] - sum[y_l - 1][x_r] + sum[y_l - 1][x_l - 1];		// 差分计算公式
			//::res.push_back(res);		// 调用全局作用域中的res
			ans ^= res;
		}

		// cout
		//ull ans = getXorSum(res.data(), res.data() + res.size());		// 左闭右开，.data() --> 返回首地址 <==> &res[0]，为空时返回nullptr
		cout << ans << endl;

	}

	return 0;
}