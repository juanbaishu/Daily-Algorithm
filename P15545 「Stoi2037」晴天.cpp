#include <iostream>
using namespace std;
long long sum, time_;
int n, s, x;


int main() {
	cin >> n >> s >> x;
	int t;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		time_++;
		if (t == 0) { sum += x; if (sum >= s) { cout << time_ << endl; return 0; } }
		if (t >= 1) { 
			if (x >= t) { sum += x - t; if (sum >= s) { cout << time_ << endl; return 0; } }		// x < t时，只增加time_
		}
	}
	cout << -1 << endl;

	return 0;
}