#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll ans;

bool check(ll b_2) {
	ll b = sqrt(b_2);
	if (b * b == b_2) {			// 得到了一致的 n，虽然看着有点抽象
		return true;
	}
	return false;
}

int main() {
	for (ll a = 4500; a <= 5005502; ++a) {
		ll a_2 = a * a;
		if (check((a_2 - 20255202) + 10244201)) {		// 传入的值为 b^2		(a_2 - 20255202) ==> n    n + 10244201 ==>  b^2
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}