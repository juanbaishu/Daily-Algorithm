#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;	// 马走日
void work();
bool check(int nx, int ny);
void out();
int n, m;
int x, y;
int map[408][408];
int v[408][408];	// visited，访问过变成 1
int ans[408][408];  //记录最短路径长度
int dx[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };	// 设置马的八个移动
int dy[8] = { -1, 1, -1, 1, -2, -2, 2, 2 };	// 上下左右
pair<int, int> p1, p2;	// 用于存放坐标信息
queue<pair<int, int> > q;
int nx, ny;		// 移动后坐标信息

int main() {
	cin >> n >> m >> x >> y;
	memset(ans, -1, sizeof(ans));	// 未访问位置为-1，马在走完队列后剩下的-1就是走不到的地方
	work();
	out();

	return 0;
}

void work() {
	v[x][y] = 1;	ans[x][y] = 0;	// 0步走到
	p1.first = x;	p1.second = y;
	q.push(p1);		// 填入队列
	while (!q.empty()) {
		p1 = q.front();		// p1 在循环中不能改变
		q.pop();
		// 进行位移操作
		for (int i = 0; i <= 7; ++i) {
			nx = p1.first + dx[i];
			ny = p1.second + dy[i];
			if (check(nx, ny)) {	// 检查越界 和 访问情况(访问过就不访问)
				v[nx][ny] = 1;
				ans[nx][ny] = ans[p1.first][p1.second] + 1;	// 移动后路径长度 = 上一个路径长度 + 1
				// 注意不要写反
				p2.first = nx; p2.second = ny;
				q.push(p2);		// 将移动后位置存入
			}
		}
	}
}

bool check(int nx, int ny) {
	if (nx < 1 || nx > n || ny < 1 || ny > m || v[nx][ny] == 1) return 0;
	return 1;
}

void out() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}