#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
vector<int> a, b;
map<int, int> ma;			// value --> index，unordered_map不能sort排序，map排序是比较 key 不是 value

int main() {
	// init
	int n;	cin >> n;	int t;
	for (int i = 0; i < n; ++i) { cin >> t; a.push_back(t); ma[t] = i; }
	for (int i = 0; i < n; ++i) { cin >> t; b.push_back(t); }
	// 更新 ma，使每个项的 value变成排序后的索引
	int index = 0;
	for (auto &i : ma) i.second = index++;			// 取pair默认是拷贝
	
	// judge
	for (int i = 0; i < n; ++i) {
		// 每轮
		int compare = a[i];
		int num = b[i];
		// 找 < ai 的元素个数
		int sum = ma[compare];		// value --> index --> 小于 compare 的个数
		// 数学运算
		int res = 0;
		if (2 * num <= sum) res = 0;
		else if (num <= sum) res = 2 * num - sum;
		else res = sum;
		cout << res << " ";
	}
	cout << endl;


	return 0;
}