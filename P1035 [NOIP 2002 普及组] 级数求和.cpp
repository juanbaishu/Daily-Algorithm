#include <iostream>
using namespace std;
double k;
double n = 1;
double sum;

int main() {
	cin >> k;
	while (sum <= k) {
		sum += 1 / n;
		n++;
	}
	cout << --n << endl;

	return 0;
}