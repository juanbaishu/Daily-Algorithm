// 前缀和问题
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(100008, 0);
vector<int> sum(100008, 0);

int main() {
	// init
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	// execute
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << endl;
	}

	return 0;
}