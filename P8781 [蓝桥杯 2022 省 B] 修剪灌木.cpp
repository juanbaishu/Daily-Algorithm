#include <iostream>
using namespace std;
// 计算每棵的最大高度，由规律知：位置为 x，左右两端为 l, r，则 max_h = 2 * max(x-l, r-x)     ==      2 * 长边步长
int n;
int max_h;

int main() {
	cin >> n;
	int r = n; int l = 1;
	for (int x = 1; x <= n; ++x) {
		max_h = 2 * max(x - l, r - x);
		cout << max_h << endl;
	}

	return 0;
}