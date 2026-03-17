#include <iostream>
#include <algorithm>
using namespace std;
int fa[40008];	// 并查集组别，2 * 20000，包含 监狱组别
int n, m;

// 思路：仇恨值递减的数据依次处理，每次都会 整体调组别，保持只有两个组别，最后传入的仇恨双方在一个集合的就是最大仇恨值

// 创建结构体用于存储仇恨值信息，用于排序
struct crime{
	int a, b, c;	 // 前者、后者、仇恨值
} e[100008];			 // 用于建立边关系，所以要用 m 个空间存储

int find(int x) {		// 找到监狱的组别(根节点)
	if (fa[x] != x) {
		fa[x] = find(fa[x]);	// 路径压缩，ALL子节点 --> 根节点
	}
	return fa[x];
}

bool sort_crime(crime& x, crime& y) {		// 代表结构体 e[i] 中的 前一个 和 后一个，可以当成 e[i]，i 会自己走
	return x.c > y.c;			// 使 x.c > y.c 的情况成立。成立会返回1，不执行 sort，如果返回 0，会执行 sort
}	// 这里就是确保是 降序排列


int main() {
	cin >> n >> m;
	// 初始化并查集
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		fa[i + n] = i + n;	// 监狱组别也改成自己
	}
	
	// 整理输入信息
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].a >> e[i].b >> e[i].c;
	}
	sort(e + 1, e + m + 1, sort_crime);			// 左闭右开

	// 操作部分
	for (int i = 1; i <= m; ++i) {
		int root_1 = find(e[i].a);		// 返回 a对应的监狱 组别
		int root_2 = find(e[i].b);
		if (root_1 == root_2) { cout << e[i].c << endl; return 0; } // 当双方监狱组别相同时，因为仇恨值递减，所以就必须在一块了，这就是最大仇恨值，一共就两块地方
		// 剩下的就是需要合并的情况（分配监狱）
		fa[find(e[i].a)] = find(e[i].b + n);		// 把 a 处的组别全部改成 b 处的组别
		fa[find(e[i].b)] = find(e[i].a + n);
	}			// 假如 前三组数据分别为 1-2  3-4  4-2，那么第三组数据就会将四个监狱合并为两个监狱
	cout << 0 << endl;	// 数据很少，没仇恨时
	return 0;
}