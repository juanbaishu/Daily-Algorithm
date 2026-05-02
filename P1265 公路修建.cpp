// 使用 prim算法，初始点 --> 已知边中找最小的 --> 下一点
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>
#define inf 1e18
using namespace std;
int n;
struct {
	double x, y;
} a[5008];
double dis[5008];		// 记录顶点到生成树间的距离
int vis[5008];
int cnt = 0;		// 已知边的数量
double sum = 0;

double getDist(int i, int j) {
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) +
		(a[i].y - a[j].y) * (a[i].y - a[j].y));
}

void prim() {
	typedef pair<double, int> PDI;
	PDI p;
	priority_queue<PDI, vector<PDI>, greater<> > q;
	q.push({ dis[1], 1 });
	dis[1] = 0;

	while (!q.empty()) {
		p = q.top();	q.pop();
		int x = p.second;		// 取出起点
		if (vis[x] == 1) continue;	// 防止重复入队的数据的使用，因为随着树的变化，一个点的dis也会变，然后重复入队
		vis[x] = 1;
		sum += dis[x];

		// 辐射
		double t;
		for (int i = 1; i <= n; ++i) {
			t = getDist(x, i);
			if (vis[i] == 0 && t < dis[i]) {
				dis[i] = t;
				q.push({ dis[i], i });
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) dis[i] = inf;		// 初始化距离
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y;
	}

	prim();

	printf("%.2f", sum);

	return 0;
}