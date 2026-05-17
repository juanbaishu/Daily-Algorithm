#include <iostream>
#include <cmath>
using namespace std;
int n, m;

int main() {
	cin >> n >> m;
	if (n < m) swap(n, m);		// 保证 n > m

	// 输出最小值
	int flag = 0;	// 为 1 时需要输出 0
	if (n == m) cout << 0;
	else {
		int cnt_9 = n-m-1, cnt_0 = m-1;
		if (cnt_9 != 0) flag = 1;
		while (cnt_9--) cout << 9;
		if (flag)
		while (cnt_0--) cout << 0;			// 这里要注意防备 前导零出现
		cout << 1;
	}

	cout << ' ';

	// 输出最大值
	int pre_cnt_9 = n-m, lat_cnt_9 = m-1;
	while (pre_cnt_9--) cout << 9;
	cout << 8;
	while (lat_cnt_9--) cout << 9;

}

// 1		1
// 0		8

// 1		2
// 1		98

// 1		3
// 91		998

// 1		4
// 991		9998

// 2		4
// 901		9989

// 3		4
// 1		9899

// 4		4
// 0		8999