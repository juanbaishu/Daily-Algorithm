#include <iostream>
using namespace std;
// 分别利用算术公式求出 每行的min和max，再求它们的并集即可
int n;
int a, b;
int maxx = INT_MAX, minn = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int ma = 0, mi = INT_MIN;
		cin >> a >> b;
		ma = (a / b);
		mi = (a / (b + 1)) + 1;
		// 找交集
		maxx = min(ma, maxx);
		minn = max(mi, minn);
	}
	cout << maxx << " " << minn << endl;

	return 0;
}