//#define _CRT_SECURE_NO_WARNINGS
//#define ll long long
//#include <iostream>
//using namespace std;
//ll n, m;
//ll p[1000005];		// 每棵树的高度
//
//bool check(ll mid) {
//	ll sum = 0;	// 木材长度											这数据量太大了，全换成 ll 才过
//	for (ll i = 1; i <= n; ++i) {
//		ll val = p[i] - mid;
//		if (val > 0) sum += val;
//	}
//	if (sum >= m) 	return 1;	// sum >= m
//	else   return 0; 			// 木材太短
//
//}
//
//int main() {
//	ll h_min = 0, h_max = 0;
//
//	cin >> n >> m;
//
//	for (ll i = 1; i <= n; ++i) {
//		cin >> p[i];
//		if (p[i] > h_max) h_max = p[i];
//	}
//
//	ll ans = -1;
//	ll mid = 0;
//	while (h_min <= h_max) {
//		mid = (h_min + h_max) / 2;
//		if (check(mid)) {		// mid 对应的结果 <= M
//			ans = mid;
//			h_min = mid + 1;
//		}
//		else {
//			h_max = mid - 1;
//		}
//	}
//	cout << ans;
//
//	return 0;
//}


// 一眼：二分匹配答案，最大化最小值(伐木高度)
#include <iostream>
#include <climits>
using namespace std;
int n, m;		// 数量，所需木材长度
int arr[1000008];
int res = 0;

bool check(int len) {
	long long sum = 0;	// 得到木材长度
	for (int i = 1; i <= n; ++i) {
		if (arr[i] > len) sum += (arr[i] - len);
	}
	
	return sum >= m;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	int l = 0, r = INT_MAX;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {		// 伐木高度过低
			res = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << res << endl;

	return 0;
}
