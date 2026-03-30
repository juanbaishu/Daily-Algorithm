#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// 因为数据量较小，可以采用尺取法做这道题
string s;
int arr[5008];
int n;
int ans;

void work();
bool check(int L, int R);

int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i <= n - 1; ++i) {
		arr[i + 1] = s[i] - '0';		// 字符转换成数字
	}

	work();

	cout << ans << endl;

	return 0;
}

void work() {
	int l = 1, r;
	for (; l <= n - 1; ++l) {
		r = l;
		while (r <= n - 1) {
			r++;
			if (check(l, r)) ans++;
		}
	}
}

bool check(int L, int R) {		// 倒着比来检查
	for (; R > L; --R) {
		if (arr[R] < arr[L]) return true;
		if (arr[R] > arr[L]) return false;
		L++;
	}
	return false;	// 全等的情况
}