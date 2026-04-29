// 找起点 --> 辐射 --> 全局找下一点
// 就是因为要全局中，找目前最短的边，所以写的比dijkstra还麻烦，还有个不同点是 dis 为邻边长度最小值
#include <iostream>
#include <cstring>
#include <climits>
#define inf INT_MAX
using namespace std;
int n, m;
struct {
	int to, w, nex;		// 出边顶点、权值、下一邻边
} e[10008];
int h[10008];
int cnt = 0;
int vis[10008];
int dis[10008];		// 每个顶点 入度边的最短长度(权值)

void add(int x, int y, int wi) {
	e[cnt].to = y;
	e[cnt].w = wi;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

int prim() {
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	int sum = 0;
	int count = 0;
	int mi = inf;
	int now;		// 当前顶点位置
	dis[1] = 0;		// 不存在入度边，因此为 0
	vis[1] = 1;
	for (int i = h[1]; i != -1; i = e[i].nex) {					// 初始化第一个
		int u = e[i].to;
		dis[u] = min(dis[u], e[i].w);
	}

	while (count < n - 1) {										// 把剩下的遍历完
		mi = inf;

		for (int i = 1; i <= n; ++i) {							// 全局找下一点
			if (vis[i] == 0 && dis[i] < mi) {
				now = i;
				mi = dis[i];
			}
		}

		if (mi == inf) return -1;								// 说明路不通，不是连通图
		vis[now] = 1;
		count++;
		sum += mi;

		for (int i = h[now]; i != -1; i = e[i].nex) {			// 辐射更新 dis
			int u = e[i].to;
			if (vis[u] == 0 && e[i].w < dis[u]) {
				dis[u] = e[i].w;
			}
		}

	}


	return sum;
}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	int x, y, wi;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> wi;
		add(x, y, wi);
		add(y, x, wi);
	}

	int sum = prim();
	cout << sum;

	return 0;
}