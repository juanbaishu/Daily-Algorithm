#include <iostream>
#include <time.h>
using namespace std;
// 输入正整数 n，输出 S = 1! + 2! + 3! + ... + n! 的末六位数字
int n;
int sum;

// 普通算法，时间复杂度为 O(n^2)
void work_1() {
	const int MOD = 1000000;
	for (int i = 1; i <= n; ++i) {			// 轮第 i 个数字
		long long tmp = 1;
		for (int j = i; j >= 1; --j) {		// 计算第 j 位数字
			tmp = tmp * j % MOD;
		}
		sum = (sum + tmp) % MOD;
	}
}

// 优化算法，时间复杂度为 O(n)，因为每轮的 tmp 继续乘就是下一个要加的数，所以就不用单独加循环了
void work_2() {
	const int MOD = 1000000;
	long long tmp = 1;
	for (int i = 1; i <= n; ++i) {			// 轮第 i 个数字
		tmp = tmp * i % MOD;
		sum = (sum + tmp) % MOD;
	}
}

void out(clock_t time) {
	cout << sum << endl;
	printf("%.6f\n", (double)time / CLOCKS_PER_SEC);	// 输出时间
}

int main() {	// 最核心的地方是 溢出，因为只要求 末六位，所以可以只保留末六位的数，防止溢出
	cin >> n;
	clock_t begin = clock();	// clock_t 就是 long
	work_2();
	clock_t end = clock();
	out(end - begin);

	return 0;
}			// 测试过了，不会溢出