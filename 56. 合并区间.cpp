#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 差分写法不行，一直有漏洞
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		int a[10008] = { 0 };		// 记录差分影响
//		int p[10008] = { 0 };		// 记录差分位置，1 --> 头，-1 --> 尾
//		int l, r;	// 区间索引
//		for (vector<int>& v : intervals) {		// 取出 一维vector
//			// 只有两项，区间
//			l = v[0]+1, r = v[1]+1;					// 取出 一维vector每个项，这题从0开始，差分0项不能填，所以统一向后移动一位，计算结果时再矫正
//			p[l] += 1;
//			p[r+1] -= 1;		// 专门设计，为这题
//		}
//		// 计算 差分影响
//		for (int i = 1; i <= 10000; ++i) {
//			a[i] = a[i - 1] + p[i];
//			//cout << a[i] << ' ';
//		}
//		cout << endl;
//		int s = -1, e = -1;
//		vector<vector<int> > res;
//		for (int i = 1; i <= 10000; ++i) {
//			if (s == -1 && a[i] > 0) s = i-1;		// 找第一个 正数
//			else if (s != -1 && a[i] == 0) {				// 找到起点后，找第一个终点
//				e = i-2;
//				if (s != -1 && e != -1) res.push_back(vector<int>{s, e});		// 放入结果
//				s = -1;		// 重置起点，找下一个区间
//				e = -1;
//			}
//		}
//		
//		return res;
//    }
//};

class Solution {
public:
	vector<vector<int> > merge(vector<vector<int>>& intervals) {
		// sort --> 默认比较第一项的值，如果相等，比较后一项的值
		sort(intervals.begin(), intervals.end());		// 排序
		vector<vector<int> > res;
		
		// 判断是否可合并
		int x_l, x_r, y_l, y_r;		// 左区间、右区间
		x_l = intervals[0][0];
		x_r = intervals[0][1];
		for (int i = 1; i < intervals.size(); ++i) {
			y_l = intervals[i][0];
			y_r = intervals[i][1];
			if (x_r >= y_l) {		// 可合并
				// 合并，结果记录到 x 中
				x_r = max(x_r, y_r);
			}
			else {			// 不可合并，计入结果中
				res.push_back(vector<int>{x_l, x_r});
				x_l = y_l, x_r = y_r;
			}
		}
		res.push_back(vector<int>{x_l, x_r});	// 最后的结果还少填一个

		return res;
	}
};

int main() {
	vector<vector<int> > ve{
		//{ 1,3 }, { 2, 6 }, { 8, 10 }, { 15,18 }
		{1, 4}, {5, 7}
	};
	// 按差分写
	Solution s;
	vector<vector<int> > res = s.merge(ve);
	for (vector<int>& v : res) {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << endl;
	}

	return 0;
}