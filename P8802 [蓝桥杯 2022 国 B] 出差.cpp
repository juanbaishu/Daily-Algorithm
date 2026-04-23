// 一道 最短路径算法 板子题，单源最短路，选用 优化后dijkstra算法
#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#define inf (int)1e8
using namespace std;
// 链式前向星 + 小根堆
// 注意这题需要将 出边顶点时间 + 权值 ==> 权值，最后再减去 N 处的时间
int n, m;
struct {
	int to, w, nex;		// 出边顶点、权值、下一邻边
} e[20008];
int h[10008];
int dis[10008];
int vis[10008];		// 每次都找最短路，找过的就不用再找了
int val[10008];		// 暂存顶点时间
int cnt = 1;
typedef pair<int, int> PII;		// 存 dis[x] 和 x
priority_queue<PII, vector<PII>, greater<> > q;		// 用 dis[x] 递增排序

void add(int x, int y, int wi) {
	e[cnt].to = y;
	e[cnt].w = wi;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

void dij() {
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	dis[1] = 0;
	PII p;
	p.first = dis[1];	p.second = 1;
	q.push(p);

	while (!q.empty()) {
		// 出队
		p = q.top();
		q.pop();
		int t = p.second;
		if (vis[t] == 1) continue;		// 队会自动选出最小的进行 松弛操作，因此使用过的点不需要再次使用
		vis[t] = 1;

		// 入队，找邻边中短的，更新+入栈
		for (int i = h[t]; i != -1; i = e[i].nex) {
			int u = e[i].to;
			if (vis[u] == 0 && dis[t] + e[i].w < dis[u]) {
				dis[u] = dis[t] + e[i].w;
				q.push({dis[u], u});
			}
		}


	}

}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	int x, y, wi;
	memset(h, -1, sizeof(h));
	for (int i = 1; i <= m; ++i) {		// 无向图，记得 e[]需要变大一倍
		cin >> x >> y >> wi;
		//cout << x << "--" << wi << "--" << y << "  ";
		//cout << x << "--" << wi << "--" << y << endl;
		add(x, y, wi + val[y]);
		add(y, x, wi + val[x]);
	}

	dij();

	cout << dis[n] - val[n] << endl;

	return 0;
}