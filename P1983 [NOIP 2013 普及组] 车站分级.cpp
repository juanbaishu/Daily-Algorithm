// 关键是找到条件：每轮 始-->终 停靠车站级别 > 未停靠车站
// 使用 kahn算法
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int n, m;			// 车站数、班次
int ac[10008];		// 填充每轮停靠的车站，across
int flag[10008];	// 记录停靠的车站
int ind[10008];		// in-degree，入度数
int link[10008][10008];		// 记录 两顶点的连接关系
vector<int> v[10008];		// 10008个vector，可变二维数组
int le[10008];		// level，个顶点层级

void kahn() {	// 通路的过程中 划分层级
	for (int i = 1; i <= n; ++i) le[i] = 1;		// memset不能用于赋值0、-1以外的数，因为是按字节来的
	queue<int> q;
	for (int i = 1; i <= n; ++i) {		// 未经过的车站插入也没事，反正也没有邻边关系
		if (ind[i] == 0) q.push(i);
	}

	int x, y;
	while (!q.empty()) {
		x = q.front();
		q.pop();

		// 遍历邻边
		for (int i = 0; i < v[x].size(); ++i) {
			y = v[x][i];		// 高级别的车站，可能高一级，可能高多级
			ind[y]--;
			le[y] = max(le[y], le[x] + 1);
			if (ind[y] == 0) q.push(y);
		}
	}
}

int main() {
	cin >> n >> m;
	int t;		// 每次经过的 车站数
	for (int i = 1; i <= m; ++i) {
		memset(ac, 0, sizeof(ac));
		memset(flag, 0, sizeof(flag));
		cin >> t;
		for (int j = 1; j <= t; ++j) {		// 接收 经过车站的信息
			cin >> ac[j];
			flag[ac[j]] = 1;
		}

		for (int j = ac[1]; j <= ac[t]; ++j) {		// 枚举 经过的所有车站
			if (flag[j] == 1) continue;
			// j 为每个 未停靠车站
			for (int k = 1; k <= t; ++k) {
				if (link[j][ac[k]] == 0) {		// 只连未连接过的
					v[j].push_back(ac[k]);		// 未停靠车站 --> 停靠车站，add(j, ac[k]);
					link[j][ac[k]] = 1;
					ind[ac[k]]++;
				}
			}
		}
	}

	kahn();

	int ma = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		ma = max(ma, le[i]);
	}
	cout << ma << endl;

	return 0;
}