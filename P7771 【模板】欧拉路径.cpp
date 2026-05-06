// 有向图 字典序欧拉路径
// 找起点 --> dfs入栈
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#define maxn 100008
#define maxm 200008
using namespace std;

typedef pair<int, int> PII;
vector<PII> v;

int n, m;
struct {
	int to, nex, nin;	// 出边顶点、下一邻边、now_index当前边编号
	bool vis;
} e[maxm];
int h[maxn];
int cnt = 0;
int dif[maxn];		// 各点上 出度-入度 数量，为 1 的为起点
stack<int> ansn;

void add(int x, int y) {
	e[cnt].nin = cnt;
	e[cnt].to = y;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
	dif[x]++;	dif[y]--;
}

void dfs(int x) {
	for (int i = h[x]; i != -1; i = h[x]) {
		if (e[i].vis == true) {
			h[x] = e[i].nex;
			continue;
		}
		e[i].vis = true;
		dfs(e[i].to);
	}
	ansn.push(x);		// 所有出边顶点后面处理完毕后执行这里，这里为当前终点，因此录入
}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	int x, y;

	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end(), greater<PII>() );		// 降序排，因为 add 是头插，所以小的应该放后面
	for (int i = 0; i < m; ++i) {
		add(v[i].first, v[i].second);
	}
	int st = 1;		// 起点
	int c1 = 0, c2 = 0;		// 起点数量、终点数量
	for (int i = 1; i <= n; ++i) {
		if (abs(dif[i]) >= 2) {		// 无欧拉路径的情况
			cout << "No" << ' ';
			return 0;
		}
		if (dif[i] == 1) {
			st = i;
			c1++;
		}
		if (dif[i] == -1) c2++;
	}
	if (!((c1 == 1 && c2 == 1) || (c1 == 0 && c2 == 0)) ) {		// 非 两种正确情况时
		cout << "No" << ' ';
		return 0;
	}

	dfs(st);

	if (ansn.size() != m + 1) {		// 检查是否漏边
		cout << "No";
		return 0;
	}

	// 正确时输出结果
	while (!ansn.empty()) {
		cout << ansn.top() << ' ';
		ansn.pop();
	} cout << endl;

	return 0;
}