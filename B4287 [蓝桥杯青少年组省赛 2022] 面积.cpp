//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int pos[105][105];		// 标记空间
//int re_sum[105][105];		// 累加空间
//
//int main() {
//	int n;
//	cin >> n;
//	int a, b, c, d;		// 左下角坐标、右上角坐标
//	for (int i = 1; i <= n; ++i) {
//		cin >> a >> b >> c >> d;
//		a++; b++; c++; d++;		// 范围改成 1~101,防止 越界
//		pos[b][a] += 1;					// 差分 填空
//		pos[b][c] -= 1;
//		pos[d][a] -= 1;					// 根据题意，推出所求范围为 半开半闭，所以不用位移就行
//		pos[d][c] += 1;
//	}
//
//	int sum = 0;
//	// 遍历墙面，注意从 0 开始，因为根据题意，接收坐标可能有 0 处的，因此通过上面 挪一下位置
//	for (int i = 1; i <= 101; ++i) {
//		for (int j = 1; j <= 101; ++j) {
//			// 累加式子累加式子
//			re_sum[i][j] = re_sum[i - 1][j] + re_sum[i][j - 1] - re_sum[i - 1][j - 1] + pos[i][j];
//			if (re_sum[i][j] > 0) sum++;
//		}
//	}
//	cout << sum;
//
//	return 0;
//}




















// 二刷
// 思路一：一眼差分，标记二维数组的 影响位
// 时间复杂度为：O(n^2)，遍历找结果时的时间
#include <iostream>
using namespace std;
int n;
int pos[108][108];
int arr[108][108];
int res;

int main() {
	cin >> n;
	int ldx, ldy, rux, ruy;		// 左下、右上
	for (int i = 1; i <= n; ++i) {
		cin >> ldx >> ldy >> rux >> ruy;
		// 填入 影响位
		ldx++;	ldy++;	rux++;	ruy++;		// 全体向右下偏移，为了差分计数
		int lux, luy, rdx, rdy;		// 左上、右下
		lux = ldx;	luy = ruy;	rdx = rux;	rdy = ldy;
		// 这是开区间
		//pos[luy][lux] += 1;		// 反着填
		//pos[ruy][rux+1] -= 1;
		//pos[ldy+1][ldx] -= 1;
		//pos[rdy+1][rdx+1] += 1;
		pos[luy][lux] += 1;		// 反着填
		pos[ruy][rux] -= 1;
		pos[ldy][ldx] -= 1;
		pos[rdy][rdx] += 1;
	}
	// 遍历-->涂色结果
	for (int i = 1; i <= 101; ++i) {		// 图的范围 0 -- 100，全体向右下偏移，变为 1 -- 101
		for (int j = 1; j <= 101; ++j) {
			arr[i][j] = pos[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];		// 差分公式
			if (arr[i][j]) res++;
		}
	}

	cout << res << endl;


	return 0;
}

// 思路二：暴力涂色
// 直接涂，时间就是 n 块中，遍历每个m*m片空间，时间复杂度就是 O(n*m*m)，只有 10^5，所以直接暴力也能过
//#include <iostream>
//using namespace std;
//int n;
//int arr[108][108];
//int res;
//
//int main() {
//	cin >> n;
//	for (int k = 1; k <= n; ++k) {		// 次数循环
//
//		int lux, luy, rdx, rdy;			// 转换成 左上、右下
//		cin >> lux >> luy >> rdx >> rdy;
//		int ldx, ldy, rux, ruy;
//		ldx = lux; ldy = rdy; rux = rdx; ruy = luy;		// 左下、右上
//
//		// 涂色
//		for (int i = luy; i < rdy; ++i) {
//			for (int j = lux; j < rdx; ++j) {
//				arr[i][j] = 1;
//			}
//		}
//	}
//	// 遍历-->涂色结果
//	for (int i = 0; i <= 100; ++i) {		// 图的范围 0 -- 100，全体向右下偏移，变为 1 -- 101
//		for (int j = 0; j <= 100; ++j) {
//			if (arr[i][j]) res++;
//		}
//	}
//
//	cout << res << endl;
//
//
//	return 0;
//}



