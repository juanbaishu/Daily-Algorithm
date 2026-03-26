#include <iostream>
using namespace std;
// 666，这么考我，诈骗题，除了1都能表示
// 形如：-2 -1 0 1 2，为0，表示3，就能写成 -2 -1 0 1 2 3，绝对都能表示
int n;
int a[100008];
int ans;


int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 1) ans++;
	}
	cout << ans << endl;

	return 0;
}