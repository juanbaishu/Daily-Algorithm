// 拓扑排序，题上说要从左右情况中找出500进制下最小的结果，意思就是字典序，13253 ==> 1*500^4 + 3*500^3 + 2*500^2 + 5*500^1 + 3*500^0
// 整理所有边，降序排 --> 找起点 --> dfs记录结果
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#define maxm 1030
#define maxn 508
#define PII pair<int, int>
using namespace std;
int m;
struct {
	int to, nex, nid;		// 出边顶点、下一邻边、now_index当前边编号
	bool vis;
} e[maxm * 2];		// 无向图
int h[maxn];
int cnt = 0;
stack<int> s;
vector<PII> v;
int ndg[maxn];		// 当前顶点的 度

void add(int x, int y) {
	e[cnt].to = y;
	e[cnt].nid = cnt;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

void dfs(int x) {
	for (auto i = h[x]; i != -1; i = h[x]) {
		if (e[i].vis == true) {
			h[x] = e[i].nex;
			continue;
		}
		e[i].vis = e[i ^ 1].vis = true;		// 无向图需要同化对边，因为本质上是一条边
		dfs(e[i].to);
	}
	s.push(x);		// 执行到这里说明当前点后面的所有部分都已经执行完毕，当前 x 点作为当前的终点，记录到栈中
}

int main() {
	cin >> m;
	memset(h, -1, sizeof(h));
	int x, y, t;
	int st = INT_MAX;

	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		t = max(x, y);	y = min(x, y);	x = t;		// 保证 x > y
		v.push_back({ x, y });
		st = min(st, y);
	}
	sort(v.begin(), v.end(), greater<PII>());		// 降序排，dfs按排列顺序 依次遍历邻边，降序排完 越小的点就最后存进去，从栈中取出时，自然是小的在前面，字典序
	for (int i = 0; i < m; ++i) {			// 键边需要 sort 后
		x = v[i].first;	y = v[i].second;
		add(x, y);	add(y, x);
		ndg[x]++;	ndg[y]++;
	}

	for (int i = 1; i <= maxn; ++i) {		// 遍历找 奇数度的点为起点（欧拉回路直接 st = 1 就行）
		if (ndg[i] % 2 == 1) {
			st = i;	break;
		}
	}

	dfs(st);

	for (int i = 1; i <= m + 1; ++i) {		// 连通图的结果顶点数 = 边数+1
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}