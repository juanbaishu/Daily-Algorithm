#include <iostream>
using namespace std;
long long n;

int main() {
	cin >> n;
	while (n > 0) {
		cout << n << " ";
		n /= 2;
	}

	return 0;
}