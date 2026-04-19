#include <iostream>
using namespace std;
int n;		// Î»Êý
int m[108];
long long res;

void dfs(int x) {
	if (x > n) { cout << res << endl; return; }
	for (int i = 1; i <= n; ++i) {
		if (m[i] == -1) continue;
		res *= 10; res += i;
		int t = m[i];	m[i] = -1;
		dfs(x + 1);
		m[i] = t;		// »ØËÝ
		res /= 10;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= 100; ++i) m[i] = i;
	dfs(1);

	return 0;
}