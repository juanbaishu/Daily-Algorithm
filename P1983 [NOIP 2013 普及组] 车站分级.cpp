//// 关键是找到条件：每轮 始-->终 停靠车站级别 > 未停靠车站
//// 使用 kahn算法
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <climits>
//using namespace std;
//int n, m;			// 车站数、班次
//int ac[10008];		// 填充每轮停靠的车站，across
//int flag[10008];	// 记录停靠的车站
//int ind[10008];		// in-degree，入度数
//int link[10008][10008];		// 记录 两顶点的连接关系
//vector<int> v[10008];		// 10008个vector，可变二维数组
//int le[10008];		// level，个顶点层级
//
//void kahn() {	// 通路的过程中 划分层级
//	for (int i = 1; i <= n; ++i) le[i] = 1;		// memset不能用于赋值0、-1以外的数，因为是按字节来的
//	queue<int> q;
//	for (int i = 1; i <= n; ++i) {		// 未经过的车站插入也没事，反正也没有邻边关系
//		if (ind[i] == 0) q.push(i);
//	}
//
//	int x, y;
//	while (!q.empty()) {
//		x = q.front();
//		q.pop();
//
//		// 遍历邻边
//		for (int i = 0; i < v[x].size(); ++i) {
//			y = v[x][i];		// 高级别的车站，可能高一级，可能高多级
//			ind[y]--;
//			le[y] = max(le[y], le[x] + 1);
//			if (ind[y] == 0) q.push(y);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	int t;		// 每次经过的 车站数
//	for (int i = 1; i <= m; ++i) {
//		memset(ac, 0, sizeof(ac));
//		memset(flag, 0, sizeof(flag));
//		cin >> t;
//		for (int j = 1; j <= t; ++j) {		// 接收 经过车站的信息
//			cin >> ac[j];
//			flag[ac[j]] = 1;
//		}
//
//		for (int j = ac[1]; j <= ac[t]; ++j) {		// 枚举 经过的所有车站
//			if (flag[j] == 1) continue;
//			// j 为每个 未停靠车站
//			for (int k = 1; k <= t; ++k) {
//				if (link[j][ac[k]] == 0) {		// 只连未连接过的
//					v[j].push_back(ac[k]);		// 未停靠车站 --> 停靠车站，add(j, ac[k]);
//					link[j][ac[k]] = 1;
//					ind[ac[k]]++;
//				}
//			}
//		}
//	}
//
//	kahn();
//
//	int ma = INT_MIN;
//	for (int i = 1; i <= n; ++i) {
//		ma = max(ma, le[i]);
//	}
//	cout << ma << endl;
//
//	return 0;
//}


// 二刷，拓扑排序，抽象成不同阶段路径，找出最长的一条
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
// 直接使用二维vector建表
struct edge {
	int to, wi;				// 出边顶点、权值、(逻辑下一邻边)有vector所以不需要了
};
vector<edge> h[10008];						// 直接建边不太行，大小为 n*n*m/4 --> (10^9)

int ind[1008];						// 入度数
int st[1008];						// 记录停靠点
int flag[1008];						// 记录停靠的站
int res[1008];						// 记录最长路径
int linked[1008][1008] = { 0 };		// 不同轮中，相同的链接路径不必重复出现

int n, m;

void add(int, int);
void kahn();

int main() {
	// 接收数据
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		memset(st, 0, sizeof(st));
		memset(flag, 0, sizeof(flag));
		h->clear();
		for (int i = 1; i <= n; ++i) res[i] = 1;
		int t;
		cin >> t;
		for (int j = 1; j <= t; ++j) {
			// 区间内 每个非停靠点 --> 区间内 停靠站
			cin >> st[j];
			flag[st[j]] = 1;
		}
		for (int j = st[1]; j <= st[t]; ++j) {		// 遍历 区间内所有站点
			// 找到 非停靠点
			if (flag[j] == 1) continue;
			// 建立链接
			for (int k = 1; k <= t; ++k) {			// 链接 非停靠站 --> 停靠站
				int u = st[k];
				if (linked[j][u] == 1) continue;
				add(j, u);
				linked[j][u] = 1;
				ind[u]++;
			}

		}
	}

	kahn();

	int max_res = 0;
	for (int i = 1; i <= n; ++i) {
		max_res = max(max_res, res[i]);
	}
	cout << max_res << endl;

	return 0;
}


void add(int x, int y) {
	h[x].push_back({y, 1});
}


void kahn() {
	queue<int> q;
	// 找起始点
	for (int i = 1; i <= n; ++i) {
		if (ind[i] == 0) q.push(i);
	}
	// 遍历每个车站
	while (!q.empty()) {
		int t = q.front(); q.pop();
		// 遍历邻边
		for (int i = 0; i < h[t].size(); ++i) {
			int u = h[t][i].to, w = h[t][i].wi;
			if (w + res[t] > res[u]) res[u] = res[t] + w;
			ind[u]--;
			if (ind[u] == 0) q.push(u);
		}
	}

	// 错误写法，不能提前遍历还有 ind值 的
	//for (int i = 1; i <= n; ++i) {
	//	// 辐射，松弛，找到最长路径
	//	for (int j = 1; j < h[i].size(); ++j) {
	//		int u = h[i][j].to, w = h[i][j].wi;
	//		if (w + res[i] > res[u]) {
	//			res[u] = res[i] + w;
	//		}
	//		ind[u]--;
	//	}
	//}

}