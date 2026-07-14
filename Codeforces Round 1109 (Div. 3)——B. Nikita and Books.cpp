// 注意到，逐位检测是否满足 最低等差数列 即可
#include <iostream>
#define ll long long
using namespace std;

bool compere(ll sum, ll i) {
	if (sum < ((i+1)*i/2)) return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int a;
		ll sum = 0;
		int flag = 0;
		cin >> a;
		for (int i = 1; i <= a; ++i) {
			int t; cin >> t;
			sum += t;
			if (compere(sum, i) == false) flag = 1;
		}
		if (flag == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}