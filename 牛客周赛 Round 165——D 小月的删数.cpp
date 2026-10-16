#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <climits>
#define ll long long
using namespace std;
int n;
vector<int> arr(200008, 0);						// 原始序列
set<int> st;							// 全数字
unordered_map<int, set<int> > mp;				// 3 --> 序号 1、3、8...处
vector<ll> sum(200008, 0);
ll res = LLONG_MAX;

int main() {
	// init
	cin >> n;
	for (int i = 1; i <= n; ++i) { 
		cin >> arr[i]; 
		st.insert(arr[i]); 
		if (i % 2) sum[i] = sum[i - 1] + arr[i];
		else sum[i] = sum[i - 1] - arr[i];
		mp[arr[i]].insert(i); 
	}

	// judge
	for (auto i : st) {
		// i 消失的情况
		int cnt = 1;
		ll res_i = 0;
		int last_pos = 0;		// 上一个 j 的值
		for (auto j : mp[i]) {
			// 取出每一个数字 i 的序号
			// 计算 j 前面那一块的 sum
			if (cnt % 2) {		// 奇数情况
				res_i += sum[j - 1] - sum[last_pos];
			}
			else {				// 偶数情况
				res_i -= sum[j - 1] - sum[last_pos];
			}

			last_pos = j;
			cnt++;
		}
		// 计算剩余尾部
		res_i += ((cnt % 2) ? (sum[n] - sum[last_pos]) : (-sum[n] + sum[last_pos]));
		res = min(res, abs(res_i));
	}

	// cout
	cout << res << endl;

	return 0;
}