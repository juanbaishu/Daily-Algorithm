#include <iostream>
using namespace std;
int t, k;
int a, b, c;

int chang(int x, int y) {
	return (x + y) / 2;
}

int main() {
	cin >> t;
	int t_a, t_b, t_c;
	while (t--) {
		cin >> a >> b >> c >> k;
		for (int i = 1; i <= k; ++i) {
			t_a = chang(b, c);
			t_b = chang(a, c);
			t_c = chang(b, c);
			a = t_a; b = t_b; c = t_c;
			if (a == b && b == c) break;
		}
		cout << a << " " << b << " " << c << endl;
	}

	return 0;
}