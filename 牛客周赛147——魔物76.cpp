#include <iostream>
#include <cstring>
using namespace std;
int n, q;
int sum[200008];
int dif[200008];		// 只保存后减前的差值，不求模
long long res = 0;

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> sum[i];
		dif[i] = sum[i];
	}

	for (int i = n; i >= 2; --i) {
		dif[i] -= dif[i - 1];
		res += ((dif[i] % 5) + 5) % 5;
		//cout << res << endl;

	}

	// 标记差分位置
	int l, r;
	for (int i = 1; i <= q; ++i) {
		cin >> l >> r;
		// 经过这一轮，res会因为 dif[] 的变化而改变，而 dif[] 可能变化的地方只分布在 dif[l] 和 dif[r]
		if (l > 1) {
			res -= ((dif[l] % 5) + 5) % 5;
			dif[l] = dif[l] + 1;
			res += ((dif[l] % 5) + 5) % 5;
		}
		if (r < n) {
			res -= ((dif[r + 1] % 5) + 5) % 5;
			dif[r + 1] = dif[r + 1] - 1;
			res += ((dif[r + 1] % 5) + 5) % 5;
		}
		cout << res << endl;
	}

	return 0;
}