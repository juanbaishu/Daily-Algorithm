// 找起点 --> 辐射 --> 全局找下一点
// 就是因为要全局中，找目前最短的边，所以写的比dijkstra还麻烦，还有个不同点是 dis 为邻边长度最小值
#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <utility>		// pair
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

//				优化前的prim算法，时间复杂度为 O(n^2)
//int prim() {
//	for (int i = 1; i <= n; ++i) dis[i] = inf;
//	int sum = 0;
//	int count = 0;
//	int mi = inf;
//	int now;		// 当前顶点位置
//	dis[1] = 0;		// 不存在入度边，因此为 0
//	vis[1] = 1;
//	for (int i = h[1]; i != -1; i = e[i].nex) {					// 初始化第一个
//		int u = e[i].to;
//		dis[u] = min(dis[u], e[i].w);
//	}
//
//	while (count < n - 1) {										// 把剩下的遍历完
//		mi = inf;
//
//		for (int i = 1; i <= n; ++i) {							// 全局找下一点
//			if (vis[i] == 0 && dis[i] < mi) {
//				now = i;
//				mi = dis[i];
//			}
//		}
//
//		if (mi == inf) return -1;								// 说明路不通，不是连通图
//		vis[now] = 1;
//		count++;
//		sum += mi;
//
//		for (int i = h[now]; i != -1; i = e[i].nex) {			// 辐射更新 dis
//			int u = e[i].to;
//			if (vis[u] == 0 && e[i].w < dis[u]) {
//				dis[u] = e[i].w;
//			}
//		}
//
//	}
//
//
//	return sum;
//}


//					优化后的prim算法，使用堆优化，时间复杂度为 O(nlogn)
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<> > q;		// 递增队列

int prim() {
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	int count = 0;		// 找到顶点数，初始点 1 算进去了，直到 count == n
	int sum = 0;
	PII p;
	p = { 0, 1 };		// 根据权值排序，对应位置便于使用
	q.push(p);
	dis[1] = 0;			// 首次要使用 sum += dis[1];

	while (!q.empty()) {
		p = q.top();
		q.pop();
		int x = p.second;		// x == 该辐射点索引
		if (vis[x] == 1) continue;		// 防止未使用前，重复入队
		vis[x] = 1;				// 将使用的点设定一下
		sum += dis[x];
		count++;
		if (count == n) break;

		for (int i = h[x]; i != -1; i = e[i].nex) {
			int y = e[i].to;
			if (vis[y] == 0 && e[i].w < dis[y]) {
				dis[y] = e[i].w;
				p = { dis[y], y };
				q.push(p);			// 辐射到的都进
			}
		}
	}
	if (count < n) return -1;		// 未连通

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