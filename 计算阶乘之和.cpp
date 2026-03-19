#include <iostream>
using namespace std;
// 输入正整数 n，输出 S = 1! + 2! + 3! + ... + n! 的末六位数字
int n;
int sum;

void work() {
	for (int i = 1; i <= n; ++i) {			// 轮第 i 个数字
		int tmp = 1;
		for (int j = i; j >= 1; --j) {		// 计算第 j 位数字
			tmp = (tmp % 1000000) * j;
		}
		sum = (sum % 1000000) + tmp;
	}
}

void out() {
	sum %= 1000000;		// 因为 两个六位数字相加可能变成 七位
	cout << sum << endl;
}

int main() {	// 最核心的地方是 溢出，因为只要求 末六位，所以可以只保留末六位的数，防止溢出
	cin >> n;
	work();
	out();

	return 0;
}			// 测试过了，不会溢出