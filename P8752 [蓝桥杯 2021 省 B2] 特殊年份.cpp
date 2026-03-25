#include <iostream>
using namespace std;
int arr[5];
int a;
int ans;

int main() {
	for (int i = 0; i < 5; ++i) {
		cin >> a;
		for (int j = 1; j <= 4; ++j) {
			arr[j] = a % 10;
			a /= 10;
		}
		if (arr[2] == arr[4] && arr[1] == arr[3] + 1) ans++;
	}
	cout << ans << endl;

	return 0;
}