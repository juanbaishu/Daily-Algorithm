//							vector存图 结构体形式，直接能存权值
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m;	// 顶点、边
//struct edge{
//	int nex;		// w --> nex
//	int w;
//};
//vector<vector<edge> > v;
//int vis[108];
//
//void dfs(int x) {
//	if (vis[x] == 1) return;
//	printf("%d ", x);
//	vis[x] = 1;
//	for (int i = 0; i < v[0].size(); ++i) {		// 向该行后面遍历
//		dfs(v[x][i].nex);
//	}
//}
//
//
//int main() {
//	cin >> n >> m;
//	v.resize(108);		// 纵向扩容，方便直接操作
//	for (int i = 1; i <= m; ++i) {		// 每个顶点
//		int a, b, wi;
//		cin >> a >> b >> wi;
//		v[a].push_back({ b, wi });		// 无向 当成 两个有向
//		v[b].push_back({ a, wi });
//	}
//
//	for (int i = 1; i <= n; ++i) dfs(i);
//
//	return 0;
//}

//							vector存图 非结构体形式，存权值需要单独写数组
#include <iostream>
#include <vector>
using namespace std;
int n, m;	// 顶点、边

vector<vector<int> > v;
int vis[108];

void dfs(int x) {
	if (vis[x] == 1) return;
	printf("%d ", x);
	vis[x] = 1;
	for (int i = 0; i < v[0].size(); ++i) {		// 向该行后面遍历
		dfs(v[x][i]);
	}
}


int main() {
	cin >> n >> m;
	v.resize(108);		// 纵向扩容，方便直接操作
	for (int i = 1; i <= m; ++i) {		// 每个顶点
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);		// 无向 当成 两个有向
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) dfs(i);

	return 0;
}
