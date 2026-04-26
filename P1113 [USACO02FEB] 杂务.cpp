// 使用 kahn算法(bfs)		链式前向星 + 队列 + 入边数记录
// 因为可以并行完成任务，所以 v-->u   res[u] = max(res[u], res[v] + tim[u])
#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
int n;
struct {
	int to, nex;	// 出边顶点、下一邻边
} e[10008];
int h[10008];
int cnt = 0;
int tim[10008];		// 各顶点时间
int res[10008];		// 处理到各顶点需要的时间
int ind[10008];		// in-degree

void add(int x, int y) {
	e[cnt].to = y;
	// 头插
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

void kahn() {
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (ind[i] == 0) q.push(i);
	}

	int t;
	while (!q.empty()) {
		t = q.front();
		q.pop();

		for (int i = h[t]; i != -1; i = e[i].nex) {		// 遍历邻边
			int u = e[i].to;
			ind[u]--;		// 防止了重复入队
			res[u] = max(res[u], res[t] + tim[u]);		// OLD VS NEW					这个很关键
			if (ind[u] == 0) {
				q.push(u);
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof(h));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, ti;
		cin >> x >> ti;
		tim[x] = res[x] = ti;
		int in;
		while (1) {
			cin >> in;
			if (in == 0) break;
			add(in, x);			// in-->x
			ind[x]++;
		}
	}

	kahn();

	int ma = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		ma = max(ma, res[i]);		// OLD VS NEW
		//cout << "i: " << i << "=> res: " << res[i] << endl;
	}
	cout << ma << endl;

	return 0;
}