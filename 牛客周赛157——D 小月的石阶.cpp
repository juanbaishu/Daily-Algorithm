#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n, k;
vector<int> v;
int res;

int main() {
	cin >> n >> k;
	int t;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		v.push_back(t);
	}
	for (int i = 1; i < v.size(); ++i) {
		v[i - 1] = abs(v[i] - v[i - 1]);
	}
	for (int i = 1; i < v.size(); ++i) {
		v[i] = v[i] + v[i - 1];				// 前缀和
	}
	v.push_back(0);
	sort(v.begin(), v.end());		// 在 v[0] 插入值 0

	int l = 1, r = 1;		// index
	while (r < v.size()) {
		while (r + 1 < v.size() && v[r + 1] - v[l - 1] <= k) r++;
		if (r == l) r++;
		res = max(res, (r - l + 1 + 1));
		if (l < r) l++;
	}
	cout << res << endl;

	return 0;
}