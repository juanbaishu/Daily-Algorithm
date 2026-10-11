// 每个前缀和余数 --> 相同余数的部分，两两之间组成的区域 取余的结果相减 == 0 --> 找前缀和余数相同的个数 --> 区间组合数 --> 累加 --> n/2 * (n-1) [平均值*个数] --> 结果
#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<long long> v(100008, 0);
vector<int> re(100008, 0);				// 记录取余结果

long long calculate(long long x) {
	return x * (x - 1) / 2;
}

int main() {
	cin >> n >> k;
	re[0]++;			// 算上 0 号位置，因为计算区间时是左开右闭的 --> (i, j] --> 0 1 2 --> 0 1 3 --> sum[1]-sum[0] --> 找 v[1] 取余如何
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		v[i] += v[i - 1];				// 前缀和
		re[v[i] % k]++;					// 记录对应余数数量
		//cout << "v[i]: " << v[i] << endl;
	}

	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		//cout << "re[i]: " << re[i] << endl;
		ans += calculate(re[i]);
	}
	cout << ans << endl;


	return 0;
}