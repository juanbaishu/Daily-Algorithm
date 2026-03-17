#include <iostream>
using namespace std;

int fa[200008];		// 并查集组别，代表根节点从属

int find(int x) {	// 递归找根节点
	if (fa[x] == x) {
		return x;		// 找到根节点了
	}
	return fa[x] = find(fa[x]);	// 如果没找到就继续往上找，这里是 压缩路径，把 所有子节点-->根节点，因为 find(fa[x]) 只有一个值——根节点位置
}

/*	另一种写法
int find(int x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
*/

int main() {
	int n, m;
	cin >> n >> m;
	int z, x, y;
	// 初始化并查集
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}

	for (int i = 1; i <= m; ++i) {
		cin >> z >> x >> y;
		if (z == 1) {		// 合并
			int root_1 = find(x);	// 找它的根节点
			int root_2 = find(y);
			fa[root_1] = root_2;	// fa[root_2] = root_1 也行，将根节点连过去
		}
		else {				// 查询
			int root_1 = find(x);	// 找它的根节点
			int root_2 = find(y);
			if (fa[root_1] == fa[root_2]) cout << "Y" << endl;
			else cout << "N" << endl;
		}
	}

	return 0;
}