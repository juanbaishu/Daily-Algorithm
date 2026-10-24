// 核心是 计算某处被包含的个数 --> 常用思路是 Li <= d(x) <= Ri --> 累加得到结果
// 但是其实可以变成  ==>  d(x) == n(区间总数) - 所有区间中 Li > d(x) 的个数 - 所有区间中 d(x) <= Ri 的个数  -->  本质上，n - 补集 --> 集合数
// 正因如此，可以将 Li 和 Ri 都单独存在数组中，并 sort 排序，二分查找
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, p;
vector<int> lv, rv;
vector<pair<int, int> > vp;
int res = 0;

int main() {
	// init
	cin >> n >> p;
	for (int i = 0; i < n; ++i) { int t; cin >> t; lv.push_back(t); cin >> t; rv.push_back(t); vp.push_back({ lv[i], rv[i] }); }
	sort(lv.begin(), lv.end());
	sort(rv.begin(), rv.end());

	// judge
	for (int i = 0; i < n; ++i) {
		int l = vp[i].first, r = vp[i].second;
		// 对于每一个样例的 两个端点 d(l)、d(r) 来说，分别判断 d(l)、d(r) 的集合数
		// 二分查找 第一个大于 d(x) 的 lv 的索引位置，籍此找到 Li > d(x) 个数 --> lv.end() - upper_bound()	  ==>  找到中间那个首个大于的数，此时右边包括自身都是 > 的
		// 二分查找 的一个小于 d(x) 的 rv 的索引位置，籍此找到 Ri < d(x) 个数 --> lower_bound() - rv.begin()  ==>  找到中间那个首个大于等于的数，此时左边的都是 < 的
		int l_res = n - (lv.end() - upper_bound(lv.begin(), lv.end(), l)) - (lower_bound(rv.begin(), rv.end(), l) - rv.begin());
		int r_res = n - (lv.end() - upper_bound(lv.begin(), lv.end(), r)) - (lower_bound(rv.begin(), rv.end(), r) - rv.begin());
		if (abs(l_res - r_res) >= p) res++;
	}

	// cout
	cout << res << endl;


	return 0;
}