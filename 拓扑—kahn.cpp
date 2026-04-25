// bfs算法，链式前向星 + 队列，从入度为0的点 ==> 辐射
// 有向图
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m;
struct {
	int to, nex;	// 出度顶点、下一邻边，权值用不到就不写了
} e[10008];
int h[10008];
int in_degree[10008];		// 记录各点 入度数
int topo[10008]; int k = 0;	// 记录结果
int cnt = 0;

void add(int x, int y) {
	e[cnt].to = y;
	// 头插
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

bool kahn() {
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (in_degree[i] == 0) { 
			q.push(i); 
			topo[++k] = i;
		}
	}
	int t;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (int i = h[t]; ~i; i = e[i].nex) {		// ~i == i不为-1
			int u = e[i].to;
			in_degree[u]--;
			if (in_degree[u] == 0) {
				q.push(u);
				topo[++k] = u;
			}
		}
	}
	if (k != n) return false;
	return true;
}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		add(x, y);
		in_degree[y]++;
	}

	if (kahn() == false) {
		cout << "有环" << endl;
		return 0;
	}
	else {
		for (int i = 1; topo[i] != 0; ++i) {
			cout << topo[i] << ' ';
		}
	}

	return 0;
}