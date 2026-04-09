#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, m;
vector<int> v;
int dif[100008];
ll sum[100008];
ll res = 1e18;

int main() {
	cin >> n >> m;
	int t;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i < n; ++i) {
		dif[i] = v[i] * v[i] - v[i - 1] * v[i - 1];
		sum[i] = dif[i] + sum[i - 1];
	}
	for (int i = m - 1; i < n; ++i) {
		res = min(res, (sum[i] - sum[i - m + 1]));		// sum 要减位置前一个
	}
	cout << res << endl;

	return 0;
}