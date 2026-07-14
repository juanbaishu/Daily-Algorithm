// 碰到 * / END 前，累加 # --> cnt，找到cnt最大值，cnt/2 + 1 ==> 结果
#include <iostream>
using namespace std;

int up(double x) {
	if (x > (int)x) return (int)x + 1;
	else return (int)x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a;
		char tt;
		int cnt = 0;
		int temp = 0;
		cin >> a;
		for (int i = 1; i <= a; ++i) {
			cin >> tt;
			if (tt == '*') { cnt = max(cnt, temp); temp = 0; }	// *
			else temp++;		// tt == '#'
		}
		cnt = max(cnt, temp);							// END
		cout << up((double)cnt/2) << endl;
	}

	return 0;
}