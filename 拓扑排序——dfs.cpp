//					不能判断有环的拓扑dfs算法
//// 思路：遍历每个点 ==> 作为起点 ==> dfs没走过的点
//// 链式前向星 + stack存结果(得到的结果是 逆拓扑排序结果)
//#include <iostream>
//#include <stack>
//#include <cstring>
//using namespace std;
//int n, m;
//struct {
//	int to, nex;	// 出度顶点、下一邻边，用不到权值
//} e[10008];
//int h[10008];
//int cnt = 0;
//stack<int> topo;	// 记录结果
//int vis[10008];
//
//void add(int x, int y) {
//	e[cnt].to = y;
//	// 头插
//	e[cnt].nex = h[x];
//	h[x] = cnt;
//	cnt++;
//}
//
//void dfs(int x) {
//	//if (e[x].nex == -1) return;		// 终止条件不需要
//	vis[x] = 1;
// 	for (int i = h[x]; ~i; i = e[i].nex) {
//		int u = e[i].to;
//		if (vis[u] == 0) {
//			dfs(u);
//		}
//	}
//	topo.push(x);	// 当前是最后面的点
//	return;
//}
//
//int main() {
//	cin >> n >> m;
//	memset(h, -1, sizeof(h));
//	int x, y;
//	for (int i = 1; i <= m; ++i) {
//		cin >> x >> y;
//		add(x, y);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (vis[i] == 1) continue;
//		dfs(i);
//	}
//
//	while (!topo.empty()) {
//		cout << topo.top() << ' ';
//		topo.pop();
//	}
//
//	return 0;
//}

/* 无环样例：
5 5
1 2
2 4 
3 2
3 4
4 5
out:
3 1 2 4 5
*/

/* 有环样例：
5 5
1 2
2 4
3 2
4 3
4 5
错误的out:
1 2 4 3 5
正确的out:
有环
*/

//							能判断有环的拓扑dfs算法
// 思路：遍历每个点 ==> 作为起点 ==> 辐射 && DFS
// vis == 0   未经过
// vis == 1   该点后所有点已经经过
// vis == 2   已经过，用于判断是否有环
//		vis  0 ==> 2 ==> 1
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
// 有向图
// 链式向前星 + vis + stack存结果(实际遍历为 逆拓扑排序结果)
int n, m;
struct {
	int to, nex;	// 出边顶点、下一邻边
} e[10008];
int h[10008];
int cnt = 0;
int vis[10008];
stack<int> topo;	// 存结果
int flag;			// 判断是否有环

void add(int x, int y) {
	e[cnt].to = y;
	// 头插
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

void DFS(int x) {
	vis[x] = 2;
	for (int i = h[x]; ~i; i = e[i].nex) {
		int u = e[i].to;
		if (vis[u] == 0) {
			DFS(u);
			if (flag == 1) return;		// 放在这里才能防止后续进行操作
		}
		else if (vis[u] == 2) {
			flag = 1;
			return;		// 有环
		}
	}
	topo.push(x);
	vis[x] = 1;			// 后面的点已遍历完
	return;
}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		add(x, y);
	}

	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 1) continue;
		DFS(i);
	}

	if (flag == 1) cout << "有环" << endl;
	else {
		while (!topo.empty()) {
			cout << topo.top() << ' ';
			topo.pop();
		}
	}

	return 0;
}

