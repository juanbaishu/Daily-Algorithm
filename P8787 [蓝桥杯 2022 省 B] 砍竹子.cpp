#include <iostream>
#include <cmath>
using namespace std;
int n;
long long arr[200008];
int cut[200008];	// 能砍次数
int maxc;			// 最耐砍次数
int ans;

void solve() {
	for (int i = maxc; i >= 1; --i) {		// 能从高->低依次搞了
		for (int j = 1; j <= n; ++j) {
			if (cut[j] == i) {// 砍最耐砍的树
				cut[j]--;
				if (arr[j] != arr[j + 1]) {			// 要和这一阶段的树比较，前面的已经改变了，所以只能和后面的比
					ans++;		// 累加比较要放到改变前
				}
				arr[j] = sqrt((arr[j] / 2) + 1);		// 当前前后项值不同，就能砍
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		int tmp = arr[i];
		while (tmp != 1) {
			cut[i]++;
			tmp = sqrt((tmp / 2) + 1);
		}
		maxc = max(cut[i], maxc);
	}

	solve();
	cout << ans << endl;

	return 0;
}