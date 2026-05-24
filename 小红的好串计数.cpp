// 这个直接算肯定很难搞，既然这样，可以反过来想，结果 = 总子集数 - 相同数子集个数
// 相同块：相同数字的一块地方
#include <iostream>
#define ll long long
using namespace std;
ll n;
string s;

int main() {
	cin >> n >> s;
	s = ' ' + s;

	ll bad_num = 0;		// 相同数子集个数
	ll cnt = 1;		// 用于累加相同数 步长，==> 每块的bad_num数
	for (int i = 2; i <= n; ++i) {
		if (s[i] == s[i - 1]) cnt++;
		else {	// 遇到不同字符了，结算上一块中的数量
			bad_num += (cnt + 1) * cnt / 2;
			cnt = 1;
		}
	}
	// 注意结尾如果有相同块，那么不会进行结算，这里要手动结算一下
	bad_num += (cnt + 1) * cnt / 2;

	ll total = (n + 1) * n / 2;
	ll res = total - bad_num;
	cout << res << endl;

	return 0;
}