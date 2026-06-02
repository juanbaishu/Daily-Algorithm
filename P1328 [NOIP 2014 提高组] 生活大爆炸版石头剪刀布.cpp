//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int result[5][5] = {
//	0, 0, 1, 1, 0,
//	1, 0, 0, 1, 0,
//	0, 1, 0, 0, 1,
//	0, 0, 1, 0, 1,
//	1, 1, 0, 0, 0
//};
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int na[205], nb[205];
//	for (int i = 0; i < a; ++i) {
//		scanf("%d", &na[i]);
//	}
//	for (int i = 0; i < b; ++i) {
//		scanf("%d", &nb[i]);
//	}
//	int scoreA = 0, scoreB = 0;
//	for (int i = 0; i < n; ++i) {
//		scoreA += result[na[i % a]][nb[i % b]];
//		scoreB += result[nb[i % b]][na[i % a]];
//	}
//	printf("%d %d", scoreA, scoreB);
//	return 0;
//}









// 二刷
// 一眼模拟
#include <iostream>
using namespace std;
int n, nx, ny;		// 轮数、x周期、y周期
int a[208];
int b[208];
int scoreA, scoreB;

int situ[5][5] = { {0, 0, 1, 1, 0 }, {1, 0, 0, 1, 0},{0,1,0,0,1}, { 0,0,1,0,1 },{1,1,0,0,0} };

int main() {
	cin >> n >> nx >> ny;
	for (int i = 0; i < nx; ++i) cin >> a[i];
	for (int i = 0; i < ny; ++i) cin >> b[i];

	// 遍历结果
	int x, y;	// a和b 出的情况
	for (int i = 0; i < n; ++i) {
		x = a[i % nx];
		y = b[i % ny];
		scoreA += situ[x][y];
		scoreB += situ[y][x];
	}
	cout << scoreA << ' ' << scoreB << endl;

	return 0;
}
