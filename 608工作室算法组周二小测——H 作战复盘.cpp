#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>
#define ll long long
#define TII tuple<int, int, int, int, int>
using namespace std;
int n, k;
vector<ll> hp;
vector<TII> notes;

int main() {
	// init
	cin >> k >> n;
	for (int i = 1; i <= n; ++i) {
		ll t; cin >> t;
		hp.push_back(t);
	}
	for (int i = 0; i < k; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		notes.emplace_back(b, i, a, c, d );
	}

	sort(notes.begin(), notes.end());

	// judge
	vector<ll> hp_c(hp);		// 拷贝干员血量副本
	for (auto i = notes.begin(); i != notes.end(); ++i) {
		int ty = get<2>(*i), op = get<3>(*i), val = get<4>(*i);		op--;	// op序号 --> 对应索引
		if (hp[op]) {
			if (ty == 1) {
				hp[op] -= val;
				if (hp[op] <= 0) hp[op] = 0;
			}
			else {
				hp[op] += val;
				if (hp[op] >= hp_c[op]) hp[op] = hp_c[op];
			}
		}
	}

	// cout
	for (auto i = hp.begin(); i != hp.end(); ++i) {
		cout << *i << ' ';
	}

	return 0;
}