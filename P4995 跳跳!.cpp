//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//int a[305];
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		cin >> a[i];
//	}
//	sort(a, a+n+1);			// 从小到大排，地址从 0 到 n，左闭右开，所以右边要填到 .end() 的位置
//
//	long long sum = 0;
//	int l = 0, r = n;
//	while (l < r) {
//		sum += pow((a[l] - a[r]), 2);
//		l++;
//		sum += pow((a[l] - a[r]), 2);
//		r--;
//	}
//	cout << sum << endl;
//
//
//	return 0;
//}




// 二刷，贪心写法
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
long long sum = 0;	// 结果

int main() {
	vector<int> v;
	v.push_back(0);		// 地面加进去
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t; cin >> t; v.push_back(t);
	}
	sort(v.begin(), v.end());

	int l = 0, r = n;	// 分别指向当前 最小值、最大值
	while (l != r) {
		// 累加 l --> r
		sum += pow((v[r] - v[l]), 2);
		// 去掉 l 那个位置，l++
		l++;
		if (l == r) break;
		// 累加 r --> l
		sum += pow((v[r] - v[l]), 2);
		// 去掉 r 那个位置，r--;
		r--;
	}

	cout << sum << endl;
}