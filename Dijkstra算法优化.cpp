// 使用 堆排序 进行优化，使用 链式前向星 代替 邻接矩阵										dijkstra算法，说白了就是不断辐射，优化前是找个最近点然后辐射，优化后是依次辐射
#include <iostream>
#include <queue>
#include <utility>
#define inf 2e8
using namespace std;

int n, m;
struct {
	int to, nex, w;		// 出边节点、头插邻边索引、权值
} e[10008];
int h[10008];
int dis[108];
int vis[108];
int cnt;
typedef pair<int, int> PII;		// 用 pair 主要是为了 👇
priority_queue<PII, vector<PII>, greater<> > q;		// 按 dis 小 -> 大 的顺序排列

void add(int x, int y, int wi) {
	// 构建 链式前向星(静态链表 ==> 邻接表)
	e[cnt].w = wi;
	e[cnt].to = y;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}
//		dijkstra优化写法，时间复杂度 O(nlogn)
void dij(int s) {
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	dis[s] = 0;
	PII p;
	p.first = dis[s];	p.second = s;
	q.push(p);

	// 大循环
	while (q.size()) {
		// 依次取出
		p = q.top();
		q.pop();
		int t = p.second;
		if (vis[t] == 1) continue;
		vis[t] = 1;
		// 进行辐射，更新dis
		for (int i = h[t]; i != -1; i = e[i].nex) {		// 遍历邻边
			int u = e[i].to;
			if (vis[u] == 0 && dis[t] + e[i].w < dis[u]) {
				dis[u] = dis[t] + e[i].w;
				q.push({dis[u], u});
			}
		}
	}
}


//		dijkstra常规写法，时间复杂度 O(n^2)
//void dij(int s) {
//	for (int i = 1; i <= n; ++i) dis[i] = inf;
//	dis[s] = 0;
//	// 在未用过的点中找
//	for (int k = 1; k <= n; ++k) {
//		// 找最近点
//		int mi = inf;	int t = -1;
//		for (int i = 1; i <= n; ++i) {
//			if (vis[i] == 0 && dis[i] < mi) {
//				mi = dis[i];
//				t = i;
//			}
//		}
//		if (t == -1) continue;
//		vis[t] = 1;
//		// 向该点四周辐射，更新路径
//		for (int i = h[t]; i != -1; i = e[i].nex) {
//			int u = e[i].to;	// 找到对应出度
//			if (vis[u] == 0 && dis[t] + e[i].w < dis[u]) {		// 松弛后变短		dis[t] == mi
//				dis[u] = dis[t] + e[i].w;
//			}
//		}
//	}
//}

void out() {
	for (int i = 1; i <= n; ++i) cout << dis[i] << " ";
}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	int x, y, wi;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> wi;
		add(x, y, wi);	// 在 add() 中构建 e[] 链式前向星
	}

	// 默认从 索引1 开始
	dij(1);

	out();

	return 0;
}

