#include <iostream>
#include <vector>
#define ll long long
using namespace std;
// 进制转换的本质：321，尽管进制不一样，但就3而言，代表存在 3 份 右边的部分，而 2 为 10进制，1 为 2进制，所以 3 * 10 * 2 就是 3 位置对应的值，有点像补码 1000 0000 == 0111 1111 + 1
const ll MAX_size = 1e5 + 8;
const ll MOD = 1e9 + 7;
int n;
int ma, mb;
int a[MAX_size];
int b[MAX_size];
ll ans;

void work() {
	for (int i = max(ma, mb); i >= 1; --i) {
		ans = ans * max(2, max(a[i] + 1, b[i] + 1)) + (a[i] - b[i]) % MOD;
		//ans += MOD;		ans %= MOD;
	}
	cout << ans << endl;
}


int main() {
	cin >> n;
	cin >> ma;
	for (int i = ma; i >= 1; --i) {		// 倒着输入，倒着运算，可以帮 B 补上前面的零，用于对齐
		cin >> a[i];
	}
	cin >> mb;
	for (int i = mb; i >= 1; --i) {
		cin >> b[i];
	}
	
	work();

	return 0;
}

