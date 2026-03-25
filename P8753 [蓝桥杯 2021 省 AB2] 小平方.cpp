#include <iostream>
using namespace std;
int n;
int ans;

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		if (i * i % n <= n / 2) ans++;		// 这样省去了浮点数比较，简便写法
	}
	cout << ans << endl;

	return 0;
}