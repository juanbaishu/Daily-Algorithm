// A - B = C  -->  A = B + C，对于 ai，找到数列中等于 ai+C 的数 --> 即为一个结果，使用 unordered_map 存储
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;

int n, c;
vector<ll> v(200008, 0);		// --> 数列
unordered_map<ll, int> m;		// --> 数值个数统计
ll res;

int main() {
	// init
	cin >> n >> c;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		m[v[i]]++;
	}

	// judge
	for (int i = 1; i <= n; ++i) {
		int dest = c + v[i];
		res += m[dest];
	}

	// cout
	cout << res << endl;

	return 0;
}