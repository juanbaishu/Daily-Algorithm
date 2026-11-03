#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m;
vector<int> arr(200008, 0);
vector<ll> sum(200008, 0);
int res = 0;		// 结果

int main() {
	// init
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) { cin >> arr[i]; sum[i] = sum[i - 1] + arr[i]; }

	// judge
	int sur_f = 0, sur_b = 0;
	for (int i = 1; i <= n; ++i) {
		ll sum_f = sum[i] - sum[0];		 ll sum_b = sum[n] - sum[i-1];		// 前一部分、后一部分 值
		// 判断两值余数 是否同余
		sur_f = (sum_f % m + m) % m;		// 如果只是 sum_f < 0 时 --> sum_f % m + m --> 对付不了 m == 1 的情况
 		sur_b = (sum_b % m + m) % m;

		if (sur_f == sur_b) res++;
	}

	// cout
	cout << res << endl;

	return 0;
}