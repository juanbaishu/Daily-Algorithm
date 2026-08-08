// 常规 尺取法 做法, 未解出
//#define _CRT_SECURE_NO_WARNINGS
//#define ll long long
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> p;			// 位置信息
//
//int main() {
//	int n, d;		// 个数、声距
//	cin >> n >> d;
//	int x;
//	for (int i = 1; i <= n; ++i) {
//		cin >> x;
//		p.push_back(x);
//	}
//	sort(p.begin(), p.end());
//	
//	int l = 0, r = 0;
//	ll sum = 0;
//	while (r <= (int)(p.size()) - 2) {			// r 最大到 .end() 位置，end()是索引位置
//		r++;
//		l = r - 1;
//		while (l >= 0 && p[r] - p[l] <= d) {
//				sum++;
//				l--;
//			}
//	}
//	cout << sum;
//
//	return 0;
//}



/* 二刷
 * 注意到，直接使用双指针，时间复杂度为 O(n^2)，超出 10^8，所以遍历得出结果只能使用单指针，判断是否能构建出单指针表 ---> 似乎构建不出来
 * 如果使用单指针，右边使用二分定位，时间可以 ---> 可以
 */
// 常规双指针  ——  基本除了第一次 右指针移动多点，后面每轮移动一两位 判断范围就行，所以时间复杂度接近 O(n)
//                   左边的不用再算了，因为往右移动时已经将情况都算进去了
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, d;
vector<int> p(1000008, 0);		// 用 .resize() 方法提前申请 初始化为0 的空间
ll sum;

int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	sort(p.begin()+1, p.begin()+n+1);		// 左闭右开

	int l = 1, r = 1;		// 指向p中第 l/r 个
	while (l <= r) {
		while (r + 1 <= n && p[r + 1] - p[l] <= d) r++;		// r --> 极限位置
		sum += r - l;	// 累加结果，每次累加 l数 --> 右边的每个数
		if (l == r && r + 1 <= n) r++;		// 防止 r 不走
		l++;
	}
	cout << sum << endl;

	return 0;
}