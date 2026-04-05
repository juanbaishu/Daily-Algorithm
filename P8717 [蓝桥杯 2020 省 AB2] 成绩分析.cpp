#include <iostream>
using namespace std;
int n;
double sum, avg;
int t;
int min_ = 2e9, max_ = -2e9;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		sum += t;
		min_ = min(min_, t);
		max_ = max(max_, t);
	}
	avg = sum / n;
	cout << max_ << endl << min_ << endl;
	printf("%.2lf", avg);

	return 0;
}