#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n, d;
string s;
int sum_ = 0;		// +
int sum__ = 0;		// -
int sum = 0;
int re = 0;		// 回到 原处 的次数

int main() {
	cin >> n >> d;
	cin >> s;
	for (char i : s) {
		if (i == '+') sum_++;
		else sum__++;
		if (abs(sum_ - sum__) % 10 == 0) re++;
	}
	sum = sum_ - sum__;
	// sum --> 对 10 求模结果
	while (sum < 0) sum += 10;		// sum --> 正数 / 0
	sum %= 10;
	d = (d + sum) % 10;
	cout << d << ' ' << re << endl;

	return 0;
}