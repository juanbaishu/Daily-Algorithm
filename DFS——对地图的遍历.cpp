#include <iostream>
#include <vector>
using namespace std;

void bfs(vector<vector<char>>& g, int i, int j) {
	int n = g.size();	// 行
	int m = g[0].size();	// 列，第0行的size
	if (i - 1 >= 0 && g[i - 1][j] == '1') { g[i - 1][j] = '0'; bfs(g, i - 1, j); }	// 陆地变水，继续递归，顺序不能变，不然会无限递归
	if (i + 1 < n && g[i + 1][j] == '1') { g[i + 1][j] = '0'; bfs(g, i + 1, j); }
	if (j - 1 >= 0 && g[i][j - 1] == '1') { g[i][j - 1] = '0'; bfs(g, i, j - 1); }
	if (j + 1 < m && g[i][j + 1] == '1') { g[i][j + 1] = '0'; bfs(g, i, j + 1); }
	return ;
}

int numIslands(vector<vector<char>>& grid) {
	int sum = 0;
	int n = grid.size();	// 行
	int m = grid[0].size();	// 列，第0行的size
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '1') {	// 找到陆地时
				sum++;
				grid[i][j] = '0';		// 陆地变水
				// 向周围遍历
				bfs(grid, i, j);
			}
		}
	}
	return sum;
}

void putin(vector<vector<char> >& g, int n, int m) {
	char x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m;) {
			cin >> x;
			if (x == '1' || x == '0') {			// 字符的输入也有讲究
				g[i][j] = x;
				j++;	// 过滤其他字符，eg.[[
			}
		}
	}
}

int main() {
	int n, m;	// 行 列
	cin >> n >> m;
	vector<vector<char> > g(n, vector<char>(m) );
	putin(g, n, m);
	int sum = numIslands(g);
	cout << sum << endl;

	return 0;
}