#include <iostream>
using namespace std;
int n, m;
int arr[100008];
int sum[100008];
int l, r;
int res;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] += arr[i] + sum[i - 1];		// Ç°×ººÍÀÛ¼Ó
	}

	cin >> m;
	for (int j = 1; j <= m; ++j) {
		cin >> l >> r;
		res = sum[r] - sum[l - 1];
		cout << res << endl;
	}

	return 0;
}