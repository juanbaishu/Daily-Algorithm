// 注意到：每次清除都是坐标轴：小 --> 大，并且第二项能一直牵制，并且最后第二项剩 两个存活，
// 所以可以直接令初始项每一项填充 k 时间内分裂区域 [ai, ai + k]，最后消除该消除区域即可，毕竟该被消除的影响不到后面不该被消除的，又不统计数量
//										优化 👆 这个部分，可以直接存区间 起点 和 终点
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n, t;
vector<int> v;						// 存储位置
vector<pair<int, int> > vp;			// 存储区间

int main() {
	cin >> n >> t;
	if (t == 0) { cout << n << endl; return 0; }
	if (n == 1) { cout << 0 << endl; return 0; }
	// 录入各点
	for (int i = 0; i < n; ++i) {
		int tt;	cin >> tt; v.push_back(tt);
	}
	sort(v.begin(), v.end());

	// 计算各个区间
	for (int i = 0; i < n; ++i) {
		vp.push_back({ v[i], v[i] + t });
	}

	// 遍历累计各个符合的区间值
	long long sum = 0;	// 累加区间总数

	// 累减 k -- n-1 所有空区间
	int L = vp[1].second - 1;	// 连续区间左端 从第二项存活两个中第一个作为区间左端点
	int R = vp[1].second;		// 第二项的尾区间
	for (int i = 2; i < n; ++i) {			// 从 第三项 开始枚举，计算 2尾 -- 3头 间的区间
		// 重叠情况，连续
		if (vp[i].first <= R) {
									// 刚好消除到 第二项尾 前一个位置，所以对于第二项能成立
			R = vp[i].second;
		}
		// 不重叠情况
		else {
			sum += (R - L + 1);
			L = vp[i].first;
			R = vp[i].second;
		}
	}
	// 将最后一项留的加上
	sum += (R - L + 1);
	
	cout << sum << endl;

	return 0;
}