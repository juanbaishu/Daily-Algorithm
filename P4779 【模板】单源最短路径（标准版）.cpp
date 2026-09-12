//// 使用 堆排序 进行优化，使用 链式前向星 代替 邻接矩阵										dijkstra算法，说白了就是不断辐射，优化前是找个最近点然后辐射，优化后是依次辐射
//#include <iostream>
//#include <cstring>
//#include <climits>
//#include <queue>
//#include <utility>
//#define inf INT_MAX
//using namespace std;
//
//int n, m, s;	// 顶点、边、初始位置
//struct {
//	int to, nex, w;		// 出边节点、头插邻边索引、权值
//} e[200008];
//int h[100008];
//int dis[100008];
//int vis[100008];
//int cnt;
//typedef pair<int, int> PII;		// 用 pair 主要是为了 👇
//priority_queue<PII, vector<PII>, greater<> > q;		// 按 dis 小 -> 大 的顺序排列
//
//void add(int x, int y, int wi) {
//	// 构建 链式前向星(静态链表 ==> 邻接表)
//	e[cnt].w = wi;
//	e[cnt].to = y;
//	// 头插法
//	e[cnt].nex = h[x];
//	h[x] = cnt;
//	cnt++;
//}
////		dijkstra优化写法，时间复杂度 O(nlogn)
//void dij(int s) {
//	for (int i = 1; i <= n; ++i) dis[i] = INT_MAX;
//	dis[s] = 0;
//	PII p;
//	p.first = dis[s];	p.second = s;
//	q.push(p);
//
//	// 大循环
//	while (q.size()) {
//		// 依次取出
//		p = q.top();
//		q.pop();
//		int t = p.second;
//		if (vis[t] == 1) continue;
//		vis[t] = 1;
//		// 进行辐射，更新dis
//		for (int i = h[t]; i != -1; i = e[i].nex) {		// 遍历邻边
//			int u = e[i].to;
//			if (vis[u] == 0 && dis[t] + e[i].w < dis[u]) {
//				dis[u] = dis[t] + e[i].w;
//				q.push({ dis[u], u });
//			}
//		}
//	}
//}
//
//
////		dijkstra常规写法，时间复杂度 O(n^2)
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
//
//void out() {
//	for (int i = 1; i <= n; ++i) cout << dis[i] << " ";
//}
//
//int main() {
//	cin >> n >> m >> s;
//	memset(h, -1, sizeof(h));
//	int x, y, wi;
//	for (int i = 1; i <= m; i++) {
//		cin >> x >> y >> wi;
//		add(x, y, wi);	// 在 add() 中构建 e[] 链式前向星
//	}
//
//	dij(s);
//
//	out();
//
//	return 0;
//}




// 二刷
#include <iostream>
#include <climits>
#include <utility>
#include <queue>
#define inf INT_MAX
using namespace std;
typedef pair<int, int> PII;
int n, m, s;
int cnt = 1;
int h[100008];
struct {
	int to, wi, nex;	// 出边顶点索引、权值、邻接表头插邻边索引
} e[200008];

void add(int, int, int);		// 构建链式前向星
void dij(int);
void dij_pro(int);
void prin(int*);

int main() {
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) h[i] = -1;
	int x, y, w;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> w;
		add(x, y, w);
	}
	dij_pro(s);

	return 0;
}

void add(int x, int y, int w) {
	e[cnt].wi = w;
	e[cnt].to = y;
	// 头插
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

void dij(int s) {
	int dis[100008];		// s --> 每个点的距离
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	int vis[100008] = { 0 };	// 0 --> 未访问该点，1 --> 访问了
	dis[s] = 0;
	
	for (int k = 1; k <= n; ++k) {
		int tmp = inf, t = -1;		// 存储最近点的 距离、索引
		for (int i = 1; i <= n; ++i) {
			// 找到最近点
			if (vis[i] == 0 && dis[i] < tmp) {
				tmp = dis[i];
				t = i;
			}
		}
		if (t == -1) continue;
		vis[t] = 1;

		// 对该点进行辐射，找松弛后更小的路径
		for (int i = h[t]; i != -1; i = e[i].nex) {
			int y = e[i].to, w = e[i].wi;
			if (vis[y] == 0 && tmp + w < dis[y]) {			// 松弛
				dis[y] = tmp + w;
			}
		}
	}
	prin(dis);
}

void dij_pro(int s) {		// 采用堆，节约遍历时间，只有松弛成功的才进来
	priority_queue<PII, vector<PII>, greater<PII> > q;		// top() --> 小的
	int dis[100008];
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	dis[s] = 0;
	int vis[100008] = { 0 };
	PII p;		// 存 索引、dis值
	p.first = dis[s]; p.second = s;			// 因为 priority_queue 默认按 pair 第一项进行排序
	q.push(p);

	while (!q.empty()) {
		// 获取最近点
		PII a;
		a = q.top();
		q.pop();
		int t = a.second;		// 最近点索引
		if (vis[t] == 1) continue;
		vis[t] = 1;

		// 进行辐射，松弛成功的进入堆中
		for (int i = h[t]; i != -1; i = e[i].nex) {
			int y = e[i].to, w = e[i].wi;
			if (vis[y] == 0 && dis[t] + w < dis[y]) {
				dis[y] = dis[t] + w;
				q.push({ dis[y], y });
			}
		}
	}
	prin(dis);
}

void prin(int* a) {
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << ' ';
	}
}