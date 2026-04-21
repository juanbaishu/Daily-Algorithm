//		实际就是 Bellman - ford算法优化
#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#define inf	2e8
using namespace std;
int n, m, s;
// 每轮都要依次遍历边，使用 边集数组
struct {
	int to, w, nex;		// 出边顶点、权值、逻辑下个邻边
} e[100008];
int h[100008];
int dis[100008];
int vis[100008];
int cnt = 1;

void add(int x, int y, int wi) {		// spfa需要链式向前星，因为 逐个遍历顶点需要知道各个出边，nex
	e[cnt].to = y;
	e[cnt].w = wi;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

void spfa(int s) {
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	dis[s] = 0;
	// 每轮只更新队列中的出边路径
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	// 能松弛的顶点 && 未在队中 ==> 才会入队
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		vis[t] = 0;
		for (int i = h[t]; i != -1; i = e[i].nex) {
			int u = e[i].to;
			if (dis[t] + e[i].w < dis[u]) {
				dis[u] = dis[t] + e[i].w;
				if (vis[u] == 0) {
					q.push(u);
					vis[u] = 1;		// 入队代表，该点进行下次辐射，该点的dis已经更新过了，没必要重复入队
				}  
			}
		}
	}

}

//struct {
//	int x, w, y;		// x -- w --> y
//} e[100008];
//int h[100008];
//int dis[100008];
//int cnt = 1;
//
//void ford(int s) {
//	for (int i = 1; i <= n; ++i) dis[i] = inf;
//	dis[s] = 0;
//	for (int i = 1; i <= n - 1; ++i) {		// 依次遍历节点，每轮最少搞出一个点的路径，因此只需遍历 n-1 轮
//		for (int j = 1; j <= m; ++j) {	// 遍历所有边
//			int x = e[j].x;
//			int wi = e[j].w;
//			int y = e[j].y;
//			if (dis[x] + wi < dis[y]) {
//				dis[y] = dis[x] + wi;
//			}
//		}
//	}
//}

void out() {
	for (int i = 1; i <= n; ++i) cout << dis[i] << " ";
}

int main() {
	memset(h, -1, sizeof(h));
	cin >> n >> m >> s;
	int x, y, wi;
	//for (int i = 1; i <= m; ++i) {
	//	cin >> x >> y >> wi;
	//	e[i].x = x;
	//	e[i].w = wi;
	//	e[i].y = y;
	//}
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> wi;
		add(x, y, wi);
	}

	spfa(s);

	out();

	return 0;
}


