//#define _CRT_SECURE_NO_WARNINGS
//#define ll long long
//#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//
//int main() {
//	int n;
//	cin >> n;
//	ll sum = 0;		// 总数
//	//ll i = 1;
//	//for (; i <= 10000000; ++i) {		// i 用于 确定位置，这里也可以换成等差数列公式
//	//	sum += i;
//	//	if (sum >= n) {
//	//		sum -= i;
//	//		break;
//	//	}
//	//}			下方为公式版👇
//
//	int i = ceil(0.5 * (sqrt(8 * n + 1) - 1));
//	sum = (i - 1) * i / 2;		// 求 i 对角线前的个数 总和
//
//	int row = 1, col = 1;
//	int s = n - sum - 1;		// 需要移动的 步长
//	if (i % 2 == 1) {		// 奇数位置,斜向上计数
//		row = i;
//		while (s != 0) {
//			s--;
//			row--;
//			col++;
//		}
//	}
//	else {		// 偶数情况，斜向下计数
//		col = i;
//		while (s != 0) {
//			s--;
//			col--;
//			row++;
//		}
//	}
//	cout << to_string(row) + '/' + to_string(col);
//
//	return 0;
//}




// 二刷
// 二分定位 --> 斜着第几列 --> 枚举定位
#include <iostream>
#define ll long long
using namespace std;
int n;			// 第几个数

bool check(ll sum, int x) {
	// 判断该行是否可行
	if (n <= sum) return true;
	return false;
}

int binary_search(int n) {
	// 根据 等差数列 的性质				1 --> 3 --> 6 --> 10    <===>     平均数 * 个数 ==> [(n + 1) / 2] * n ==> n(n+1)/2
	ll res;
	int ans;		// 返回行号结果
	ll mid;			// 枚举第 mid 行
	int l = 1, r = 1e7;
	while (l <= r) {
		mid = (l + r) / 2;
		res = mid * (mid + 1) / 2;
		if (check(res, mid)) {			// 最小化最大值
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}

	}
	return ans;
}

void enumeration(int n, int up_num, ll sum) {
	int dif = sum - n;
	if (up_num % 2 == 1) {		// 偶数向下走
		cout << 1 + dif << '/' << up_num - dif;
	}
	else {
		cout << up_num - dif << '/' << 1 + dif;
	}

}

int main() {
	cin >> n;
	int top_num = binary_search(n);
	ll sum = (ll)top_num * (top_num + 1) / 2;
	enumeration(n, top_num, sum);

	return 0;
}