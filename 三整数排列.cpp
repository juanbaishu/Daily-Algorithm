#include <iostream>
using namespace std;

int main() {
	int a, b, c, t;							// 核心：确保 a、b、c 的大小递增，交换值来改变
	cin >> a >> b >> c;
	// 错误样例 如果输入值 a > b > c就不行了
	//if (a > b) { t = a; a = b; b = t; }		// 使 a <= b
	//if (b > c) { t = b; b = c; c = t; }		// 使 b <= c，这里破坏了前面建立的 a最小 的关系，因此逻辑计算有问题
	//if (a > c) { t = a; a = c; c = t; }		// 使 a <= c
	// 正确样例
	if (a > b) { t = a; a = b; b = t; }		// 使 a <= b		确保了建立的关系未被破坏(a 最小)
	if (a > c) { t = a; a = c; c = t; }		// 使 a <= c，前两步确保了 a 最小，不影响后面 b 与 c 比较
	if (b > c) { t = b; b = c; c = t; }		// 使 b <= c
	// 延申
	//if (c < b) { t = c; c = b; b = t; }
	//if (c < a) { t = c; c = a; a = t; }
	//if (b < a) { t = b; b = a; a = t; }	// 了解正确逻辑后自然就能变形正确了
	cout << a << " " << b << " " << c;

	return 0;
}