                                 // 常规 dfs 写法，不查子岛屿的残缺版
//#include <iostream>
//using namespace std;
//// 使用 BFS 进行遍历搜索，分两个情况，若连成一个圈，就清空内部；若不围成圈，只清空自身
//// 围成圈的标准是
//int T, col, line;	// 列、行
//char str[58][58];
//
//void dfs(int x, int y) {
//	if (x < 1 || x > line || y < 1 || y > col) return;		// 终止条件
//	if (str[x + 1][y] == '1') { str[x + 1][y] = '0'; bfs(x + 1, y); }
//	if (str[x - 1][y] == '1') { str[x - 1][y] = '0'; bfs(x - 1, y); }
//	if (str[x][y + 1] == '1') { str[x][y + 1] = '0'; bfs(x, y + 1); }
//	if (str[x][y - 1] == '1') { str[x][y - 1] = '0'; bfs(x, y - 1); }
//	return;
//}
//
//int main() {
//	cin >> T;
//	while (T--) {
//		int ans = 0;
//		cin >> line >> col;
//		for (int i = 1; i <= line; ++i) {
//			for (int j = 1; j <= col; ++j) {
//				cin >> str[i][j];
//			}
//		}
//
//		for (int i = 1; i <= line; ++i) {
//			for (int j = 1; j <= col; ++j) {
//				if (str[i][j] == '1') {
//					ans++;
//					dfs(i, j);
//				}
//			}
//		}
//		cout << ans << endl;
//	}
//
//
//	return 0;
//}


                                 // 常规 bfs 写法，不查子岛屿的残缺版
//#include <iostream>
//#include <queue>
//#include <cstring>
//using namespace std;
//int T, n, m;
//char str[58][58];
//int dx[4] = { 0, 0, -1, 1 };        // 移动方式
//int dy[4] = { 1, -1, 0, 0 };
//pair<int, int> p1, p2;
//queue<pair<int, int> > q;   // 存储数对类型的队列
//
//
//void bfs(int x, int y) {
//    p1 = { x, y };
//    q.push(p1);
//    while (!q.empty()) {
//        p1 = q.front();
//        q.pop();
//        
//        for (int i = 0; i < 4; ++i) {
//            if (p1.first + dx[i] < 1 || p1.first + dx[i] > n || p1.second + dy[i] < 1 || p1.second + dy[i] > m) continue;   // 跳过越界项
//            if (str[p1.first + dx[i]][p1.second + dy[i]] == '1') { str[p1.first + dx[i]][p1.second + dy[i]] = '0'; p2 = {p1.first + dx[i], p1.second + dy[i]}; q.push(p2); }
//        }
//    }
//    return;
//
//}
//
//int main() {
//    cin >> T;
//    while (T--) {
//        int ans = 0;
//        cin >> n >> m;
//        memset(str, 0, sizeof(str));
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                cin >> str[i][j];
//            }
//        }
//
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                if (str[i][j] == '1') {
//                    ans++;
//                    bfs(i, j);
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//}



// 关键在于 外海 与 内海 的关系，如果 内部的水 在八个方向能接触到外海，那么这就是外海。如果 一个岛 四方方向内接触到外海，那么它 就不算 子岛
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int T, n, m;
char str[58][58];
int vis[58][58];
int dx[4] = { 0, 0, -1, 1 };        // 移动方式
int dy[4] = { 1, -1, 0, 0 };
int xx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int yy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
pair<int, int> p1, p2;
queue<pair<int, int> > q;   // 存储数对类型的队列


void bfs_opensea(int x, int y) {
    p1 = { x, y };
    q.push(p1);
    int nx, ny;
    while (!q.empty()) {
        p1 = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            nx = p1.first + xx[i]; ny = p1.second + yy[i];
            if ( nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1 || vis[nx][ny] == 1) continue;   // 跳过越界/重复项
            if (str[nx][ny] == 0) { 
                vis[nx][ny] = 1;
                str[nx][ny] = 2;    // 外海标记为数字 2
                p2 = {nx, ny}; 
                q.push(p2); }     // (char)cnt 对应不可见字符
        }
    }
}


int bfs_land(int x, int y) {
    int flag = 0;
    int nx, ny;

    p1 = { x, y };
    q.push(p1);
    while (!q.empty()) {
        p1 = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            nx = p1.first + dx[i]; ny = p1.second + dy[i];
            if (str[nx][ny] == 2) flag = 1;     // 发现外海
            if (p1.first + dx[i] < 1 || p1.first + dx[i] > n || p1.second + dy[i] < 1 || p1.second + dy[i] > m || vis[nx][ny] == 1) continue;   // 跳过越界/重复项
            if (str[nx][ny] == 1) {
                vis[nx][ny] = 1; 
                p2 = { nx, ny }; 
                q.push(p2);
            }
        }
    }
    return flag;

}

int main() {
    cin >> T;
    while (T--) {
        int ans = 0;
        cin >> n >> m;
        memset(str, 0, sizeof(str));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> str[i][j];
                str[i][j] -= '0';           // 字符全部转化为 数字
            }
        }
        // 标记外海
        bfs_opensea(0, 0);

        // 遍历陆地
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str[i][j] == 1 && vis[i][j] == 0) {
                    if (bfs_land(i, j)) {       // 接触外海的情况
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}




