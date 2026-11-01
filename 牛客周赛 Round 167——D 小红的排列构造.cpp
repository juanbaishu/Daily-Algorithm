// 三者和 --> 奇偶性相同 --> 奇+奇+奇 / 偶+偶+偶 --> 对应结果 奇 / 偶
// 因此，可以通过n, 直接确定三者奇偶性
// 通过分配，结果中存在的奇数/偶数 即可
// 奇数：每个至少分配一个 奇数，后续 两个两个地给
// 偶数：每个的奇数必须是偶数个
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int n;
string s;
stack<int> av, bv, cv;
vector<int> res(200008, 0);		// res放 原来位置的数应该挪到的位置

int main() {
	// init
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'a') av.push(i + 1);
		else if (s[i] == 'b') bv.push(i + 1);
		else cv.push(i + 1);
	}

	// judge
	size_t a_n = av.size(), b_n = bv.size(), c_n = cv.size();		// 奇数个数
	int t = n % 4;
	int cnt = (n + 1) / 2;	// 奇数个数
	if (cnt % 2 == 0) {	// 偶数情况
		// 分配
		while (cnt) {
			if (a_n >= 2) { a_n -= 2; cnt -= 2; if (!cnt) break; }
			if (b_n >= 2) { b_n -= 2; cnt -= 2; if (!cnt) break; }
			if (c_n >= 2) { c_n -= 2; cnt -= 2; if (!cnt) break; }
			if (a_n < 2 && b_n < 2 && c_n < 2) { cout << "-1" << endl; return 0; }		// 找不到结果情况
		}
		a_n = av.size() - a_n;	b_n = bv.size() - b_n;	c_n = cv.size() - c_n;		// 奇数分配情况
	}
	else {			// 奇数情况
		if (av.size() == 0 || bv.size() == 0 || cv.size() == 0) { cout << "-1" << endl; return 0; }		// 找不到结果情况
		// 分配
		--a_n; --b_n; --c_n;
		cnt -= 3;
		while (cnt) {
			if (a_n >= 2) { a_n -= 2; cnt -= 2; if (!cnt) break; }
			if (b_n >= 2) { b_n -= 2; cnt -= 2; if (!cnt) break; }
			if (c_n >= 2) { c_n -= 2; cnt -= 2; if (!cnt) break; }
			if (a_n < 2 && b_n < 2 && c_n < 2) { cout << "-1" << endl; return 0; }		// 找不到结果情况
		}
		a_n = av.size() - a_n;	b_n = bv.size() - b_n;	c_n = cv.size() - c_n;		// 奇数分配情况
	}
	// 为得到的奇数 分配序号
	for (int i = 1; i <= n; i += 2) {
		if (a_n) { res[av.top()] = i; av.pop(); a_n--; }
		else if (b_n) { res[bv.top()] = i; bv.pop(); b_n--; }
		else { res[cv.top()] = i; cv.pop(); c_n--; }
	}
	// 分配偶数
	for (int i = 2; i <= n; i += 2) {
		if (!av.empty()) { res[av.top()] = i; av.pop(); }
		else if (!bv.empty()) { res[bv.top()] = i; bv.pop(); }
		else { res[cv.top()] = i; cv.pop(); }
	}

	// cout
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}

	return 0;
}