// 这个题最关键的区间，正常思路都不行  -->  关键是 ai <= 30 --> 首尾元素乘积 max == 900 --> 即使端点内每个元素为 1，最大区间也是 902 --> 遍历次数(移动左端点，枚举右端点) 2*10^5 * 902 --> O(10^8) 能过
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int n;
vector<int> arr(200008, 0);
vector<ll> sum(200008, 0);
int res = 0;

int main() {
	// init
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	// judge
	int product = 0;
	ll sum_arr = 0;
	for (int i = 1; i <= n-2; ++i) {			// 枚举 左端点
		for (int j = i+2; j <= n && j <= i+901; ++j) {		// 枚举 右端点
			product = arr[i] * arr[j];
			sum_arr = sum[j-1] - sum[i];
			if (product == sum_arr) res++;
		}
	}

	// cout
	cout << res << endl;

	return 0;
}