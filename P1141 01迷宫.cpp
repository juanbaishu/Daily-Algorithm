//#include <iostream>
//#include <cstring>
//#include <utility>
//#define PII pair<int, int>
//using namespace std;
//int n, m;
//int arr[1008][1008];
//
//// -------------------------------------------------------------------------------------------------------------------  函数声明
//
//int dfs(int, int);
//PII check(int, int);
//
//// -------------------------------------------------------------------------------------------------------------------  函数
//
//int fa[1000008];		// 并查集
//int vis[1008][1008];
//int sum = 0;
//int dfs(int y, int x) {
//	if (find(y, x) == 1) {
//		return fa[y * 1000 + x];
//	}
//	// 向周围符合条件的地方 移动，sum累加，vis标记
//	PII area;
//	for (int i = 1; i <= 4; ++i) {		// 轮四次 --> 每条路都走一遍
//		if ((area = check(y, x)).first) {
//			vis[area.first][area.second] = 1;
//			fa[area.first*1000 + area.second] = dfs(area.first, area.second);
//		}
//	}
//	// 回溯
//	return ;
//}
//
//PII check(int y, int x) {
//	// 成功找到，返回 正确 y、x 值
//	if (vis[y-1][x] == 0 && y - 1 >= 1 && arr[y - 1][x] != arr[y][x]) {
//		return { y - 1, x };
//	}
//	else if (vis[y + 1][x] == 0 && y + 1 <= n && arr[y + 1][x] != arr[y][x]) {
//		return { y + 1, x };
//	}
//	else if (vis[y][x - 1] == 0 && x - 1 >= 1 && arr[y][x - 1] != arr[y][x]) {
//		return { y, x - 1 };
//	}
//	else if (vis[y][x + 1] == 0 && x + 1 <= n && arr[y][x + 1] != arr[y][x]) {
//		return { y, x + 1 };
//	}
//	// 失败填充 0
//	else {
//		return { 0, 0 };
//	}
//}
//
//// -----------------------------------------------------------------------------------------------------------------  主程序
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			char c;
//			cin >> c;
//			arr[i][j] = c - '0';
//		}
//	}
//
//	int y, x;
//	for (int i = 1; i <= m; ++i) {
//		// init
//		memset(vis, 0, sizeof(vis));
//		for (int i = 1; i <= 1000008; ++i) fa[i] = 1;		// 代替 sum
//		cin >> y >> x;
//		vis[y][x] = 1;		// 起点 vis 标记
//		sum = 1;			// 算上起点
//
//		dfs(y, x);
//		cout << sum << endl;
//	}
//
//	return 0;
//}


// -------------------------------------- 连通块记忆化
#include <iostream>
#include <cstring>
#define nx (x + dx[i])
#define ny (y + dy[i])
#define check(y, x) (1<=x&&x<=n&&1<=y&&y<=n)
using namespace std;
int dx[] = { 0, 0, 0, 1, -1 }, dy[] = {0, 1, -1, 0, 0};		// 第一个不读
int n, m;

int id[1008][1008];		// 缓存连通块编号
int compSize[1000008];	// 连通块记录，完成一轮结果，才会更新一次
int arr[1008][1008];	// 地图


void dfs(int y, int x, int no) {
	id[y][x] = no;			// 记忆化搜索关键
	compSize[no]++;			// 后面找到一块路，就累加到 祖先中

	for (int i = 1; i <= 4; ++i) {
		if (!check(ny, nx)) continue;				// 边界条件要行
		if (id[ny][nx]) continue;					// 没连通块才行
		if (arr[ny][nx] == arr[y][x]) continue;		// 数字不同才行

		dfs(ny, nx, no);		// 继续看后面
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	int compCnt = 0;			// 连通块编号
	int y, x;
	while (m--) {
		cin >> y >> x;
		if (id[y][x] != 0) { cout << compSize[id[y][x]] << endl; continue; }		// 有缓存结果

		compCnt++;
		dfs(y, x, compCnt);
		cout << compSize[compCnt] << endl;
	}

	return 0;
}