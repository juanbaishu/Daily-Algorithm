//// 一道 最短路径算法 板子题，单源最短路，选用 优化后dijkstra算法
//#include <iostream>
//#include <cstring>
//#include <utility>
//#include <queue>
//#define inf (int)1e8
//using namespace std;
//// 链式前向星 + 小根堆
//// 注意这题需要将 出边顶点时间 + 权值 ==> 权值，最后再减去 N 处的时间
//int n, m;
//struct {
//	int to, w, nex;		// 出边顶点、权值、下一邻边
//} e[20008];
//int h[10008];
//int dis[10008];
//int vis[10008];		// 每次都找最短路，找过的就不用再找了
//int val[10008];		// 暂存顶点时间
//int cnt = 1;
//typedef pair<int, int> PII;		// 存 dis[x] 和 x
//priority_queue<PII, vector<PII>, greater<> > q;		// 用 dis[x] 递增排序
//
//void add(int x, int y, int wi) {
//	e[cnt].to = y;
//	e[cnt].w = wi;
//	// 头插法
//	e[cnt].nex = h[x];
//	h[x] = cnt;
//	cnt++;
//}
//
//void dij() {
//	for (int i = 1; i <= n; ++i) dis[i] = inf;
//	dis[1] = 0;
//	PII p;
//	p.first = dis[1];	p.second = 1;
//	q.push(p);
//
//	while (!q.empty()) {
//		// 出队
//		p = q.top();
//		q.pop();
//		int t = p.second;
//		if (vis[t] == 1) continue;		// 队会自动选出最小的进行 松弛操作，因此使用过的点不需要再次使用
//		vis[t] = 1;
//
//		// 入队，找邻边中短的，更新+入栈
//		for (int i = h[t]; i != -1; i = e[i].nex) {
//			int u = e[i].to;
//			if (vis[u] == 0 && dis[t] + e[i].w < dis[u]) {
//				dis[u] = dis[t] + e[i].w;
//				q.push({dis[u], u});
//			}
//		}
//
//
//	}
//
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i) {
//		cin >> val[i];
//	}
//	int x, y, wi;
//	memset(h, -1, sizeof(h));
//	for (int i = 1; i <= m; ++i) {		// 无向图，记得 e[]需要变大一倍
//		cin >> x >> y >> wi;
//		//cout << x << "--" << wi << "--" << y << "  ";
//		//cout << x << "--" << wi << "--" << y << endl;
//		add(x, y, wi + val[y]);
//		add(y, x, wi + val[x]);
//	}
//
//	dij();
//
//	cout << dis[n] - val[n] << endl;
//
//	return 0;
//}


// 二刷
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#define PII pair<int, int>
#define inf INT_MAX
#define ll long long
using namespace std;
int n, m;				// 城市数量、道路数量
int qua_time[1008];		// 各城市隔离时间
int road_time[10008];	// 道路时间
// 链式前向星
int head[1008];
struct {
	int to, w, nex;		// 出边顶点、权值、邻接表逻辑下一个
} e[20008];		// 双向存两份

void add(int, int, int);
int dij(int);


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> qua_time[i];
	// 构建链式前向星
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= m; ++i) {
		int x, y, r;
		cin >> x >> y >> r;
		add(x, y, r + qua_time[y]);		// 加上隔离时间
		add(y, x, r + qua_time[x]);		// 双向道路，反向记录一次
	}
	int t = dij(1);

	cout << t << endl;

	return 0;
}

int cnt = 1;
void add(int x, int y, int r) {
	e[cnt].w = r;
	e[cnt].to = y;
	// 头接法
	e[cnt].nex = head[x];
	head[x] = cnt;
	cnt++;
}

int dij(int s) {
	int dis[10008];		// 记录各点 --> s 的距离
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	dis[1] = 0;
	int vis[10008] = { 0 };
	priority_queue<PII, vector<PII>, greater<PII> > q;		// 小根堆
	PII p;
	p.first = dis[1];	p.second = 1;		// 优先队列默认根据第一个参数排序
	q.push(p);

	while (!q.empty()) {
		// 找最近的点
		PII p;
		p = q.top();	q.pop();
		int t = p.second;
		if (vis[t] == 1) continue;
		vis[t] = 1;
		// 辐射，找到松弛后更优的路线进入堆中
		for (int i = head[t]; i != -1; i = e[i].nex) {			// i --> 边的编号，需要转化成 点的信息
			int y = e[i].to, w = e[i].w;
			if (vis[y] == 0 && dis[t] + w < dis[y]) {
				dis[y] = dis[t] + w;
				q.push({ dis[y], y });
			}
		}
	}
	return dis[n] - qua_time[n];
}