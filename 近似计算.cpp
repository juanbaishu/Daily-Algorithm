#include <iostream>
using namespace std;
// Π/4 = 1 - 1/3 + 1/5 - 1/7...		要求结果求到小数点后六位

double work() {
	double tmp, sum = 0;
	for (int i = 0; ; i++) {
		tmp = 1.0 / (i * 2 + 1);			// 这是要点，递增i，套用 i*2+1 ==> 1 3 5 7 9 11
		if (tmp < 1e-6) break;
		if (i % 2 == 0) { sum += tmp; }
		if (i % 2 == 1) { sum -= tmp; }
	}
	return sum;
}

void out(double result) {
	printf("%.6f", result);
}

int main() {
	double result = work();
	out(result);

	return 0;
}