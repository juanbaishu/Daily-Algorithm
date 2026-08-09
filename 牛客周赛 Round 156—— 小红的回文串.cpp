#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
string s;

int main() {
	cin >> n >> s;
	// 确认字符种类个数
	int a[27] = {};
	for (char x : s) {
		a[x - 'a' + 1] = 1;
	}

	// 循环测试
	int sum = 0;	// 结果数量
	for (int i = 1; i <= 26; ++i) {
		if (a[i] == 1) {
			char c = 'a' + i - 1;		// 需要跳过的字母
			// 每次都跳过该字母，假删除
			string r_s = s;
			reverse(r_s.begin(), r_s.end());
			int f_c = 0, s_c = 0;	// 遍历中每轮的对应字符的索引位置
			int len = s.length();
			while (f_c <= len - 1 && s_c <= len - 1) {
				while (f_c + 1 <= len - 1 && s[f_c] == c) f_c++;
				while (s_c + 1 <= len - 1 && r_s[s_c] == c) s_c++;
				// 判断是否为 回文串
				if (s[f_c] != r_s[s_c]) {
					sum--;		// 这个不行，直接抵消掉 sum++
					break;
				}
				f_c++;
				s_c++;
			}
			sum++;	// 这个是 回文串
		}
	}

	cout << sum << endl;

	return 0;
}