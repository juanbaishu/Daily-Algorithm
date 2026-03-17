#include <iostream>
using namespace std;
// 确保最后结果为 a->c 递增

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


	// 但到多项时就不行了，👇 是冒泡的雏形
	int a, b, c, d, e, f, g, t;
	cin >> a >> b >> c >> d >> e >> f >> g;
	if (a > b) { t = a; a = b; b = t; }		// 使 a <= b
	if (b > c) { t = b; b = c; c = t; }
	if (c > d) { t = c; c = d; d = t; }
	if (d > e) { t = d; d = e; e = t; }
	if (e > f) { t = e; e = f; f = t; }
	if (f > g) { t = f; f = g; g = t; }		// 一次排序并不能确保排序结果，因为关系项太多，上面的单一逻辑无法继续延申，就像，a <= b后，不能确保 b <= c 后，依旧使 a <= b
	if (g > a) { t = g; g = a; a = t; }

	return 0;
}