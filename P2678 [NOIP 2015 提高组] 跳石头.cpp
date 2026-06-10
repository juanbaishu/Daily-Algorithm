//// 对于这题，使用枚举二分法，得到最大化最小值
//#define _CRT_SECURE_NO_WARNINGS
//#define ll long long
//#include <iostream>
//using namespace std;
//ll s, n, m;	// L、N、M
//unsigned int pos[50005];		// 石头位置
//
//bool check(ll mid) {
//	int now = 0, nex = 0;	// 两个指针，next 有关键字不能写全，代表下标位置，从起点开始
//	int sum = 0;
//	while (nex < n) {		// nex 未指到终点时
//		nex++;
//		if (mid > pos[nex] - pos[now])  sum++;		// mid > now 和 nex 之间的距离
//		else  now = nex;		// mid <= 距离
//	}
//	if (sum <= m) return 1;
//	return 0;	// sum 过多情况
//
//}
//
//int main() {
//	cin >> s >> n >> m;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%ld", &pos[i]);
//	}
//	pos[n + 1] = s;		// 记录终点
//	n++;		// 终点下标位置
//	ll l = 1, r = s;	// 最小距离、最大距离
//	ll ans;
//	while (l <= r) {
//		ll mid = (l + r) / 2;	// 每次枚举的最小距离
//		if (check(mid)) {		// mid <= 最大化最小值
//			ans = mid;
//			l = mid + 1;
//		}
//		else {
//			r = mid - 1;		// mid > 最大化最小值
//		}
//	}
//	cout << ans;
//
//	return 0;
//}
//
//


// 由于给定的数据很大，直接暴力，时间复杂度达到 O(n^2)，50000 * 50000 ==> 2.5 x 10^9，所以不行。其中的数组也不能动(需要保存石头之间的相对关系)
// 所以考虑使用二分答案，最大化最小值。通过二分去猜答案，时间复杂度能缩短到，O(nlogn)
#include <iostream>
using namespace std;
int L, N, M;			// 起点终点距离、起点终点之间的石头数、能移动石头数
int dif[50008];			// 石头距离差值

bool check(int len) {		// 模拟跳跃的过程
	int cur_dis = 0;			// 当前的累加距离
	int cnt = 0;				// 移动石头的次数
	for (int i = 1; i <= N + 1; i++) {
		cur_dis += dif[i];
		if (cur_dis < len) {			// 距离过小
			cnt++;
		}
		else {
			cur_dis = 0;
		}
	}
	
	if (cnt <= M) return true;			// len值 取小了
	return false;
}

int main() {
	cin >> L >> N >> M;
	int pre = 0, cur;		// 上一个值、当前值
	for (int i = 1; i <= N; ++i) {
		cin >> cur;
		dif[i] = cur - pre;
		pre = cur;
	}
	dif[N + 1] = L - pre;		// 补充 终点到最后一个块石头的间距

	int l = 0, r = L;
	int mid;
	int res = 0;		// 最大化最小值，res --> 更大
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid) == true) {		// mid值 取小了
			res = mid;			// 最后存的值 肯定是 最大的
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << res << endl;

	return 0;
}