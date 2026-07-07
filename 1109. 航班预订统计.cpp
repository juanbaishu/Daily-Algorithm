// 基础差分题
#include <iostream>
#include <vector>
using namespace std;

// 一维数组version
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
	int m = bookings.size();	// 行数
	vector<int> v(n + 2, 0);		// 结果数组，从索引1开始，初始化值为0
	vector<int> a(n + 2, 0);		// 增量数组
	// 依次取数据放入计算
	for (int i = 0; i < m; ++i) {
		int firs = bookings[i][0];	int las = bookings[i][1];	int seats = bookings[i][2];
		a[firs] += seats;	a[las + 1] += -seats;		// 累加增量
	}
	// 得到结果
	for (int i = 1; i <= n; ++i) {
		v[i] = v[i - 1] + a[i];
	}
	return vector<int>(v.begin()+1, v.end()-1);
}

// 二维数组version
//vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
//	int m = bookings.size();	// 行数
//	vector<vector<int> > v(m+1, vector<int>(n+2, 0));			// 直接写差分数组就行，原数组就是全0的，叠加上去就行，所以这里就不写了		初始化大小，值都为0
//	// 依次取出做差分标记
//	for (int i = 0; i < m; ++i) {		// 取出行数
//		int first = bookings[i][0];	int las = bookings[i][1];	int seats = bookings[i][2];	// 填入的个数
//		v[i+1][first] = seats; v[i+1][las + 1] = -seats;
//	}
//	// 算出最后结果
//	vector<int> res;
//	for (int i = 1; i <= n; ++i) {		// 列
//		for (int j = 1; j <= m; ++j) {		//  行
//			v[j][i] = v[j][i - 1] + v[j - 1][i] - v[j-1][i-1] + v[j][i];
//		}
//		res.push_back(v[m][i]);
//	}
//}

int main() {


	return 0;
}