#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define ll long long				// 递归结果 == 值，记录值就是记录递归过程
using namespace std;
ll a, b, c;
ll ans;
ll f[28][28][28];	// 记录递归结果，因为递归最多到 20

int w(ll a, ll b, ll c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) {
		if (a == 20 && b == 20 && c == 20) { f[20][20][20] = w(20, 20, 20); }	// 记录
		return w(20, 20, 20);
	}
	else if (a < b && b < c) {
		if (f[a][b][c - 1] == -1)			f[a][b][c - 1] = w(a, b, c - 1);					// 没有记录过的记一下，不判断的话和原来没区别，还是会浪费时间
		if (f[a][b - 1][c - 1] == -1)		f[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		if (f[a][b - 1][c] == -1)			f[a][b - 1][c] = w(a, b - 1, c);
		return f[a][b][c - 1] + f[a][b - 1][c - 1] - f[a][b - 1][c];
	}
	else {
		if (f[a - 1][b][c] == -1)			f[a - 1][b][c] = w(a - 1, b, c); 
		if (f[a - 1][b - 1][c] == -1)		f[a - 1][b - 1][c] = w(a - 1, b - 1, c); 
		if (f[a - 1][b][c - 1] == -1)		f[a - 1][b][c - 1] = w(a - 1, b, c - 1); 
		if (f[a - 1][b - 1][c - 1] == -1)	f[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
		return f[a - 1][b][c] + f[a - 1][b - 1][c] + f[a - 1][b][c - 1] - f[a - 1][b - 1][c - 1];
	}
}


int main() {
	memset(f, -1, sizeof(f));
	while (scanf("%lld%lld%lld", &a, &b, &c)) {		// 若有输入返回 1，无输入返回 EOF
		if (a == -1 && b == -1 && c == -1) break;
		ans = w(a, b, c);
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
	}
	return 0;
}