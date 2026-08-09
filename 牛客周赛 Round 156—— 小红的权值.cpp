#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int n, q;
ll x;
vector<ll> a;

ll binary(ll t) {		// 操作次数最少 --> r最大 --> 最大化最小值 --> mid最大 --> 优先增加l
	int l = 0, r = a.size() - 1;
	int mid;
	ll res = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= t) { l = mid + 1; res = mid; }
		else if (a[mid] == t) break;
		else { r = mid - 1; }
	}
	return (a.size() - 1) - res;
}

int main() {
	cin >> n >> q >> x;
	for (int i = 1; i <= n; ++i) {
		ll t;	cin >> t;
		t = abs(x - t);		// 得到差值
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	// 整理成前缀和
	for (int i = 1; i <= a.size() - 1; ++i) a[i] += a[i - 1];

	for (int i = 1; i <= q; ++i) {
		ll t;
		cin >> t;
		ll res = 0;
		res = binary(t);
		cout << res << endl;
	}

	return 0;
}