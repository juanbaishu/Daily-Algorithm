// 直接开数组找 n 肯定不行，空间不够。关键是 n 由三个质数组成，所以其中相对较小的质数范围为 2 -- 10^6，如果能被整除，则说明找到了
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll n;

int main() {
	cin >> n;
	// 埃氏筛法
	for (ll i = 2; i <= 1000000; ++i) {
		if (n % i == 0) {				// 首次找到的 i 一定是质数，因为若i为合数，设 i = a x b，那么第一次找到的就应该是 min(a, b)而不是 i，但是第一次找到的就是 i，所以第一次找到的 i 一定不是合数，是质数
			// i 为 p 的情况
			if (n % (i * i) == 0) {
				cout << i << ' ' << n / (i * i) << endl;
				break;
			}
			// i 为 q 的情况
			else {
				ll cons = n / i;
				ll p = sqrt(cons);
				// 浮点数微调
				while (p * p < cons) p++;
				while (p * p > cons) p--;
				cout << p << ' ' << i << endl;
				break;
			}
		}
	}

	return 0;
}