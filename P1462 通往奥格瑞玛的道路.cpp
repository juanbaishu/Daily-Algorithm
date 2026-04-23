// 用二分 筛选出 满足 最大值最小化的 路径(dijkstra)
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
int n, m, b;
struct {
	int to, w, nex;		// 出边顶点、权值、下一邻边
} e[100008];		// 存无向图，所以需要二倍大小
int h[10008];
long long dis[10008];
int vis[10008];
int f[10008];	// 城市费用
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<> > q;
int cnt = 0;

void add(int x, int y, int wi) {
	e[cnt].to = y;
	e[cnt].w = wi;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

bool dij(int s, int ma) {
	memset(vis, 0, sizeof(vis));
	if (f[s] > ma) return false;	// 刚开始收费就高于 ma 直接返回
	for (int i = 1; i <= n; ++i) dis[i] = INT_MAX;
	dis[s] = 0;
	PII p;
	q.push({ dis[s], s });

	while (!q.empty()) {
		p = q.top();
		q.pop();
		int t = p.second;
		if (vis[t] == 1) continue;		// 入边顶点需新
		vis[t] = 1;
		
		for (int i = h[t]; i != -1; i = e[i].nex) {
			int u = e[i].to;
			if (vis[u] == 0 && f[u] <= ma && dis[t] + e[i].w < dis[u]) {		// 未访问点 && 城市收费小于 ma(二分限制) && 能变小
				dis[u] = dis[t] + e[i].w;
				q.push({ dis[u], u });
			}
		}
	}

	return dis[n] <= b;		// 能走就返回 true
}


int main() {
	int l = INT_MAX, r = 0;
	memset(h, -1, sizeof(h));
	cin >> n >> m >> b;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
		l = min(l, f[i]);
		r = max(r, f[i]);
	}
	int x, y, wi;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> wi;
		if (x == y) continue;	// 自边情况
		add(x, y, wi);
		add(y, x, wi);
	}

	// 走不到 n 的情况
	if (dij(1, INT_MAX) == false) {
		cout << "AFK" << endl;
		return 0;
	}

	int mid, res = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (dij(1, mid) == true) {		// 说明还能降
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << res << endl;

	return 0;
}