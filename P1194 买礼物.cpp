// 逃课写法过不了，我试试 kruskal算法(边)
// 最短边 --> 合成树 -->...
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int a, b;
struct edge{
	int x, y;
	int w;
} e[250008];		// 最大边数为 b^2 ==> 250000
int fa[508];
bool cmp(const edge& a, const edge& b) {
	return a.w < b.w;
}
int res = 0;
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);			// 路径压缩
}

void kruskal(int m) {
	for (int i = 0; i <= b; ++i) fa[i] = i;		// 初始化组别
	//cout << "e[1].w = " << e[1].w << endl;

	int cnt = 0;	// 树上边数
	for (int i = 1; i <= m; ++i) {
		int x = e[i].x;
		int y = e[i].y;
		int fx = find(x);
		int fy = find(y);
		if (fx == fy) continue;	// 组别相同，合成不了生成树
		fa[fx] = fy;							// 合并组别
		res += e[i].w;
		//cout << "e[i].w : " << e[i].w << endl;
		cnt++;
		if (cnt == b) break;	// 形成最小生成树时退出
	 }
}

int main() {
	cin >> a >> b;
	int t, cnt = 0;
	for (int i = 1; i <= b; ++i) {
		e[++cnt] = { 0, i, a };			// 搞一个虚拟点，相当于给每个点提供了一个“天桥”，kij值大的时候可以按原价过
	}

	for (int i = 1; i <= b; ++i) {
		for (int j = 1; j <= b; ++j) {			// 这里还是去重，虽然全都进去也没事，就算重复也会被并查集剔除
			cin >> t;
			if (i < j) {
				cnt++;
				//cout << "j: " << j << "b: " << b << endl;
				e[cnt].x = i; e[cnt].y = j;
				e[cnt].w = (t == 0 ? a : t);
			}
		}
		//cout << "i:" << i << endl;
	}
	sort(e + 1, e + cnt + 1, cmp);		// 递增排序，左闭右开
	kruskal(cnt);	// 传入边数

	cout << res << endl;

	return 0;
}