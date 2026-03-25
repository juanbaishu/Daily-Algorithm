#include <iostream>
#include <cstring>
using namespace std;
int T, n;
int t[11]; int d[11]; int l[11];
int used[11];		// 降落完毕为 1

bool dfs(int x, int cur_time) {																		// 完成的飞机个数、上个飞机着陆时刻
	if (x == n) return true;							// 终止条件									// 飞机全部降落，发生错误就回溯回去了

	for (int i = 1; i <= n; ++i) {
		if (used[i] == true) continue;																// 下过了就继续
		int start = max(t[i], cur_time);															// 飞机可以等/过时间了 下去，但是出发时间肯定是最大值
		if (start > t[i] + d[i]) continue;				// 超时判定											// 超时了，继续往后执行，后面会执行到used[x] = false处收尾
		used[i] = true;
		if (dfs(x + 1, start + l[i])) return true;		// 检查口
		used[i] = false;								// 回溯											// 能执行到这里，说明不行，要回溯
	}
	return false;
}

int main() {
	cin >> T;
	while (T--) {
		memset(used, 0, sizeof(used));
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> t[i] >> d[i] >> l[i];
		}
		if (dfs(0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}