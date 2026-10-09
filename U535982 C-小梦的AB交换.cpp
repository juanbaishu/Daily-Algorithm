// 最后s肯定为 ABAB... OR BABA... 其中一种，所以遍历一遍找到不匹配的数量/2 --> 结果
#include <iostream>
#include <cstring>
using namespace std;

int T, n;
string s;

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> s;
		int res = 0;
		// ABAB... 情况 和 BABA... 情况
		int res1 = 0, res2 = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (i % 2 == 0) {
				if (s[i] != 'A') res1++;
				else res2++;
			}
			else {
				if (s[i] != 'B') res1++;
				else res2++;
			}
		}
		
		// 计算 res
		res = min(res1, res2);
		res /= 2;
		cout << res << endl;
	}

	return 0;
}