// 1个16进制 --> 4个2进制数，十进制：1200 --> 能被10^2整除，101000 --> 能被 2^3 整除
// 所以这题，只需要依次转化16-->2进制，数末尾连续0个数就行
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i) if ('A' <= s[i] && s[i] <= 'F') s[i] += 32;		// 转化成小写
	int k;
	cin >> k;

	// 转化成2进制
	long long cnt = 0;
	for (char c : s) {
		// 0特殊对待，--> 全0时才需要继续往后统计
		if (c == '0') cnt += 4;
		else {
			if (c == '8') cnt += 3;
			else if (c == '4' || c == 'c') cnt += 2;
			else if (c == '2' || c == '6' || c == 'a' || c == 'e') cnt += 1;
			else cnt += 0;
			// 进行判定
			if (cnt >= k) { cout << "YES" << endl; return 0; }			// 1000000 能被 2^1 整除，所以应该是 >=
			else { cout << "NO" << endl; return 0; }
		}
	}
	// 全0需要特判
	cout << "YES" << endl;		// 走到这里说明是全0

	return 0;
}