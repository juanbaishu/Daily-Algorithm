#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MOD 1000000009
typedef long long LL;
using namespace std;
int n, k, t;
LL ans = 1;
vector<LL> v;


int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());		// 递增排序

	int l = 0, r = n - 1;
	// 全负数情况
	if (v[r] < 0) { 
		for (int i = r; i > r - k; --i) { ans = -(-(ans * v[i])) % MOD; } 
		cout << ans << endl;
		return 0;
	}

	// 非全负数情况
	if (k % 2 == 1) { ans = (v[r] * ans) % MOD; r--; k--; }
	for (int i = 1; i <= k / 2; ++i) {			// 每轮选两个
		if (v[l] * v[l + 1] > v[r] * v[r - 1]) { ans = (ans * ((v[l] * v[l + 1]) % MOD)) % MOD; l += 2; }			// 取左边两个
		else {ans = (ans * ((v[r] * v[r - 1]) % MOD)) % MOD; r -= 2; }												// 取右边两个
	}
	cout << ans << endl;

	return 0;
}