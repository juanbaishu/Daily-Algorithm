// 递增边 --> 祖先关系 --> 连接两点
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
// 使用边集数组存图，因为便于表示顶点与边的关系
struct edge{
	int x, y;
	int w;
} e[10008];
bool cmp(const edge &a, const edge &b) {
	return a.w < b.w;
}

int fa[10008];		// 并查集组别
int find(int x) {			// 递归找根节点
	if (fa[x] == x) {		// 找到了根节点
		return x;
	}	// 终止条件
	return fa[x] = find(fa[x]);		// 路径压缩，子节点都直接连到根节点
}

// 时间复杂度为 O(mlogm)，因为排序的时间复杂度是这个
int kruskal() {
	int sum = 0;
	for (int i = 1; i <= n; ++i) fa[i] = i;		// 初始时，自身为自身组别
	sort(e+1, e + m + 1, cmp);		// 递增排序，左闭右开

	for (int i = 1; i <= m; ++i) {		// 需找 n-1 条边，构建最小生成树
		// 判断边两端是否可连
		int x = find(e[i].x);
		int y = find(e[i].y);
		if (x == y) continue;		// 不能连情况
		fa[x] = y;					// x 那组的祖先变成 y，谁当祖先都行
		sum += e[i].w;
	}
	return sum;
}

int main() {
	cin >> n >> m;
	int x, y, wi;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> wi;
		e[i] = { x, y, wi };
	}

	int sum = kruskal();
	cout << sum;

	return 0;
}