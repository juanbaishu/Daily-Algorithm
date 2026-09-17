//// 使用 kahn算法(bfs)		链式前向星 + 队列 + 入边数记录
//// 因为可以并行完成任务，所以 v-->u   res[u] = max(res[u], res[v] + tim[u])
//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <climits>
//using namespace std;
//int n;
//struct {
//	int to, nex;	// 出边顶点、下一邻边
//} e[1000008];
//int h[10008];
//int cnt = 0;
//int tim[10008];		// 各顶点时间
//int res[10008];		// 处理到各顶点需要的时间
//int ind[10008];		// in-degree
//
//void add(int x, int y) {
//	e[cnt].to = y;
//	// 头插
//	e[cnt].nex = h[x];
//	h[x] = cnt;
//	cnt++;
//}
//
//void kahn() {
//	queue<int> q;
//	// 找起始点
//	for (int i = 1; i <= n; ++i) {
//		if (ind[i] == 0) q.push(i);
//	}
//
//	// 辐射，无入度后入队，松弛路径
//	int t;
//	while (!q.empty()) {
//		t = q.front();
//		q.pop();
//
//		for (int i = h[t]; i != -1; i = e[i].nex) {		// 遍历邻边
//			int u = e[i].to;
//			ind[u]--;		// 防止了重复入队
//			res[u] = max(res[u], res[t] + tim[u]);		// OLD VS NEW					这个很关键
//			if (ind[u] == 0) {
//				q.push(u);
//			}
//		}
//	}
//}
//
//int main() {
//	memset(h, -1, sizeof(h));
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		int x, ti;
//		cin >> x >> ti;
//		tim[x] = res[x] = ti;
//		int in;
//		while (1) {
//			cin >> in;
//			if (in == 0) break;
//			add(in, x);			// in-->x
//			ind[x]++;
//		}
//	}
//
//	kahn();
//
//	int ma = INT_MIN;
//	for (int i = 1; i <= n; ++i) {
//		ma = max(ma, res[i]);		// OLD VS NEW
//		//cout << "i: " << i << "=> res: " << res[i] << endl;
//	}
//	cout << ma << endl;
//
//	return 0;
//}


// 二刷
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct {
	int to, nex;	// 出度顶点、逻辑下一邻边
} e[1000008];
int h[10008];		// 每一顶点
int ind[10008];		// 入度数
int tim[10008];		// 该事件耗时
int res[10008];		// 该事件耗时 + 前置总耗时

int n;

void add(int, int);
void kahn(void);

int main() {
	memset(h, -1, sizeof(h));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, len, f;
		cin >> x >> len;
		res[x] = tim[x] = len;
		while (1) {
			cin >> f;
			if (f == 0) break;
			ind[x]++;		// 入度++
			add(f, x);		// f --> x，事件依赖
		}
	}
	kahn();

	int max_res = 0;
	for (int i = 1; i <= n; ++i) {
		max_res = max(max_res, res[i]);
	}
	cout << max_res << endl;

	return 0;
}

int cnt = 1;
void add(int x, int y) {
	// 通过链式前向星，描述 事件对后续事件的依赖
	e[cnt].to = y;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

void kahn() {
	queue<int> q;
	// 找起始点
	for (int i = 1; i <= n; ++i) {
		if (ind[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		// 辐射，入度为0入队，松弛路径
		for (int i = h[t]; i != -1; i = e[i].nex) {		// i --> 边，t --> 辐射点
			int u = e[i].to;	// 出度顶点
			// 更新 res
			if (res[t] + tim[u] > res[u]) res[u] = res[t] + tim[u];			// 松弛
			// 更新 ind
			ind[u]--;
			if (ind[u] == 0) q.push(u);
		}
	}
}