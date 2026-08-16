#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<p> v;
int n;
int sum = 0;

int main() {
	cin >> n;
	int t;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		v.push_back({ t, i });		// 数, index
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i) {
		int l, r = 0;	// index
		l = v[i].second;
		while (i + 1 < v.size() && v[i + 1].first == v[i].first) i++;		// 后一位值 == 当前值，往后走
		r = v[i].second;
		if (r != l && (r - l) % 2 == 0) sum++;
	}
	cout << sum << endl;

	return 0;
}