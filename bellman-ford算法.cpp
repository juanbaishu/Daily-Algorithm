#include <iostream>
#define inf 1001;
using namespace std;
// 思想：全部边遍历一遍，至少出一个最短路径，遍历n-1遍 ==> 完成
// 有权有向图
int n, m;	// n == 顶点数  ==>  m 最大值 == n*(n-1)/2, n <= 100; 设定 -1000 <= m <= 1000
// 边集数组
struct {
	int stat, end;
	int w;
} e[10008];
int res[108];		// 各顶点的最短距离

void ford() {
	int x, y, wi;
	for (int i = 1; i <= n - 1; i++) {		// 最多n-1轮，每轮至少处理完一条边
		for (int j = 1; j <= m; ++j) {		// 更新每条边的最短路径
			x = e[j].stat;
			y = e[j].end;
			wi = e[j].w;
			if (res[x] + wi < res[y]) {
				res[y] = res[x] + wi;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int x, y, wi;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> wi;
		e[i] = { x, y, wi };
		res[i] = inf;
	}
	int begi;
	cin >> begi;
	res[begi] = 0;

	ford();
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << " ";			//输出 begi->各点 的最短距离
	}

	return 0;
}

/*
输出样例：
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
1    // begi
输出样例：
0 -3 -1 2 4
*/