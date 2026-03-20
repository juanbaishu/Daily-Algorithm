#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
void putin_1(), putin_2(), putin_3();
void work();
bool check(int x, int y, int r);
// 小明走迷宫，而且有多种状态、位移情况，而且要求最短用时，所以应该用BFS进行所有情况的记录
int n, k;
char map[308][308];
struct cond {		// condition per second
	int x;
	int y;
	int t;
	int s;			// size，这里填半径，5x5 --> 2  3x3 --> 1  1x1 --> 0
} nex, now;
int v[308][308];
//struct cond a;	// 等价于上面的写法，把上面的a, tmp去掉后
queue<cond> q;
int dx[4] = {1, -1, 0, 0};		// 四向移动，上下左右，x是竖的
int dy[4] = {0, 0, -1, 1};
int nx, ny;		// 移动后位置

int main() {
	putin_3();
	work();

	return 0;
}

void putin_1() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		getchar();	// 吃掉/n
		for (int j = 1; j <= n; ++j) {
			scanf("%c", &map[i][j]);	// 乱吃\n
		}
	}
}
void putin_2() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", &map[i]);
	}
}
void putin_3() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];	// cin 会自动扔掉 /n
		}
	}
}

void work() {
	v[3][3] = 1;
	q.push({3, 3, 0, 2});
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.x == n - 2 && now.y == n - 2) { cout << now.t << endl; break; }		// 到达终点
		// 操作部分
		// 保持不动，在能变瘦时
		int r = now.s;
		if (now.s != 0) {
			if (now.t + 1 < k) r = 2;			// 判断变瘦情况
			else if (now.t + 1 < 2 * k) r = 1;
			else r = 0;
			q.push({now.x, now.y, now.t+1, r});		// now.s 也不能改变
		}

		// 四向移动
		cond nex;
		for (int i = 0; i < 4; ++i) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];
			if (check(nx, ny, now.s)) {		// 检查边界条件和访问情况，以及是否会被阻挡
				v[nx][ny] = 1;
				nex.x = nx; nex.y = ny; nex.t = now.t + 1;		// now.t 自身千万不能改，否则会累加，导致结果错误
				if (nex.t < k) nex.s = 2;			// 判断变瘦情况
				else if (nex.t < 2 * k) nex.s = 1;
				else nex.s = 0;
				q.push(nex);		// 存入更新后的位置信息
			}
		}
	}
}

bool check(int x, int y, int r) {
	if (x < 1 || x > n || y < 1 || y > n || v[x][y] == 1) return 0;
	for (int i = x - r; i <= x + r; ++i) {
		for (int j = y - r; j <= y + r; ++j) {
			if (i < 1|| i > n || j < 1 || j > n || map[i][j] == '*') return 0;
		}
	}
	return 1;
}
