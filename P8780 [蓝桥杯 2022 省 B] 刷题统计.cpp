#include <iostream>
using namespace std;
long long a, b, n, x, time_, all;
int flag;

int main() {
	cin >> a >> b >> n;
	all = a * 5 + b * 2;
	time_ = n / all * 7;
	x = n / all * all;
	for (int i = 1; i <= 7; ++i) {
		if (i <= 5 && x < n) { x += a; time_++; }
		else if (x < n) { x += b; time_++; }
	}
	
	cout << time_ << endl;

	return 0;
}