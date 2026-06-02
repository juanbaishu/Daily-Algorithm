//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int n;
//int a[10005], b[10005], g[10005], k[10005];
//int x, y;
//int flag;
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
//	}
//	scanf("%d%d", &x, &y);
//	for (int i = n - 1; i >= 0; --i) {
//		if ((a[i] <= x && x <= a[i] + g[i]) && (b[i] <= y && y <= b[i] + k[i])) {
//			printf("%d\n", ++i);
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0) {
//		printf("-1\n");
//	}
//	return 0;
//}









// 二刷
// 一眼，覆盖差分，但是做不到，因为数组开不了太大

// 暴力选取，直接看(x,y)是否在枚举的区间内，越往后越在上面
#include <iostream>
using namespace std;
int n;
int a[10008], b[10008], c[10008], d[10008];
int x, y;
int res = -1;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	cin >> x >> y;

	// 枚举判断
	for (int i = 1; i <= n; ++i) {
		if (y >= b[i] && y <= b[i] + d[i] && x >= a[i] && x <= a[i] + c[i]) res = i;				// 注意是 笛卡尔系
	}
	cout << res << endl;

	return 0;
}
