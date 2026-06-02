//#include <iostream>
//#include <cmath>
//using namespace std;
//int n1 = 123;	// 只用第一部分，模拟后面两个结果
//int com[9];		// 重复集，验证是否重复
//int flag = 1;		// 不重复标志
//
//int main() {
//	for (; n1 <= 329; ++n1) {		// 因为第三个是 3 倍，所以n1在不重复的情况下，最大为 329
//		// 推断 n2、n3
//		int n2 = 2 * n1;
//		int n3 = 3 * n1;
//		// 判断 n2、n3 中无重复数
//		for (int i = 0; i < 3; ++i) {					// (int)pow(10, 0) 为 1
//			com[i] = (n1 / (int)pow(10, i)) % 10;		// 取出各项的公式
//			if (com[i] == 0) flag = 0;						// 保证不存在 0
//		}
//		for (int i = 0; i < 3; ++i) {
//			com[i + 3] = (n2 / (int)pow(10, i)) % 10;
//			if (com[i + 3] == 0) flag = 0;
//		}
//		for (int i = 0; i < 3; ++i) {
//			com[i + 6] = (n3 / (int)pow(10, i)) % 10;
//			if (com[i + 6] == 0) flag = 0;
//		}
//		for (int i = 0; i < 9; ++i) {	// i 代表指针位置
//			for (int j = i + 1; j < 9; ++j) {
//				if (com[i] == com[j]) {
//					flag = 0;
//				}
//			}
//		}
//		// 输出 n2、n3
//		if (flag) {
//			printf("%d %d %d", n1, n2, n3);
//			printf("\n");
//		}
//		flag = 1;
//	}
//
//	return 0;
//}







// 二刷
// 一眼枚举，但是时间复杂度太高不行，而且不能出现重复数，比较麻烦

// dfs做法
//#include <iostream>
//#include <stack>
//#include <vector>
//using namespace std;
//int a[10];
//int flag[10];
//
//
//int resume(int x, int y, int z) {
//	return x * 100 + y * 10 + z;
//}
//
//void dfs(int x) {		// 填入第 x 位的数
//	if (x == 10) {
//		if (2 * resume(a[1], a[2], a[3]) == resume(a[4], a[5], a[6]) && 3 * resume(a[1], a[2], a[3]) == resume(a[7], a[8], a[9])) {
//			printf("%d%d%d %d%d%d %d%d%d", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
//			cout << endl;
//		}
//		return;
//	}
//	for (int i = 1; i <= 9; ++i) {
//		if (flag[i] == 0) {
//			a[x] = i;
//			flag[i] = 1;
//			dfs(x + 1);
//			// 回溯
//			flag[i] = 0;
//			a[x] = 0;
//		}
//	}
//}
//
//int main() {
//
//	dfs(1);
//
//	return 0;
//}


// 更简单做法，枚举前三个数，找满足条件的后六位数，时间更短
#include <iostream>
using namespace std;
int num1, num2, num3;

bool check(int x, int y, int z) {
	int a[10] = { 0, x / 100, x / 10 % 10,x % 10, y / 100, y / 10 % 10,y % 10 , z / 100, z / 10 % 10,z % 10 };
	int flag = 0;
	for (int i = 1; i <= 8; ++i) {
		for (int j = i + 1; j <= 9; ++j) {
			if (a[i] == a[j] || a[i] == 0) flag = 1;		// 防重复 和 出现0
		}
	}
	if (flag == 0) return true;
	return false;
}

int main() {
	num1 = 123;
	for (; num1 <= 329; ++num1) {
		num2 = 2 * num1;
		num3 = 3 * num1;
		if (check(num1, num2, num3)) {
			cout << num1 << ' ' << num2 << ' ' << num3 << endl;
		}
	}

	return 0;
}
