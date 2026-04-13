//							链式前向星，结构体形式
#include <iostream>
using namespace std;
int n, m;		// 顶点数、边数
int head[1008];		// 第i个顶点(head[i])存储的第一个边索引(x)  <==>  head[i] == x;
struct {
	int to;	//	to表示当前边的出度顶点，nex则是下一个边的索引
	int w;
	int nex;
}edge[1008];
int vis[1008];

int cnt;
void inser(int x, int y, int wi) {
	//		x -- wi --> y
	edge[cnt].to = y;
	edge[cnt].w = wi;
	// 头插法
	edge[cnt].nex = head[x];
	head[x] = cnt;				// 指向当前顶点，方便下一次头插
}

void dfs(int x) {
	if (vis[x]) return;
	printf("%d ", x);
	vis[x] = 1;
	for (int i = head[x]; i != -1; i = edge[i].nex) {		// i 为 edge索引，head[x] == 初始edge索引
		dfs(edge[i].to);
	}
}

int main() {
	memset(head, -1, sizeof(head));		// 索引从0开始，所以初始化为-1
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int x, y, wi;
		cin >> x >> y >> wi;
		inser(x, y, wi);
		inser(y, x, wi);
	}

	for (int i = 1; i <= n; ++i) dfs(i);
	return 0;
}