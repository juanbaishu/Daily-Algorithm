// 无向有环图，dfs算法
// 找起点 --> dfs入栈
// 注意 无邻边时 出度顶点即为当前终点
#include <iostream>
#include <cstring>
#include <stack>
#define maxn 1008
#define maxm 1008
using namespace std;
int n, m;
// 使用 链式前向星 存边关系
struct {
	int to, nex, ndg;	// 出度顶点、下一邻边、now_degree当前边的编号
	bool vis;			// 标记是否访问
} e[maxm * 2];
int h[maxn];
int cnt = 0;
int deg[maxn];		// 顶点对应度数量
stack<int> ansm;		// 记录边的结果
stack<int> ansn;			// 记录点的结果

void add(int x, int y) {
	e[cnt].ndg = cnt;
	e[cnt].to = y;
	// 头插法
	e[cnt].nex = h[x];
	h[x] = cnt;
	cnt++;
}

////优化前算法			时间复杂度：O(m * (n + m) )，如果是无环图，就没影响，但是有环就会使得一个点被重复访问，即使有vis continue指令，也会顺着邻边将下面所有的节点都再访问一遍，我理解最坏情况就是所有一半的边都连着起点，复杂度从 n+m ==> m/2 * (n+m)
//void dfs(int x) {		// 第 x 位，点
//	// 这里遍历所有边作为终止标志，因此不需要使用 x 作为终止条件
//	for (int i = h[x]; i != -1; i = e[i].nex) {
//		if (e[i].vis == true) {
//			continue;
//		}
//		e[i].vis = e[i ^ 1].vis = true;		// 边从索引 0 开始，无向边分组为 0 1、2 3、4 5... ==>   0 ^ 1 == 1 && 1 ^ 1 == 0，这样运算都能得到正确另一边编号，所以这样写
//		dfs(e[i].to);
//		ansm.push(e[i].ndg);		// 只有遍历完e[i].to以后所有的才会到这，说明该从这返回了，当前的终点边在这，因此录入
//	}
//	ansn.push(x);		// 遍历完当前点的所有出边，执行到这里说明出边的dfs全部完成了，该从这里返回，x就是当前的终点点，因此录入
//}

// 优化后算法			时间复杂度：O(n + m)，相当于 剪枝，通过 删邻接表的边
void dfs(int x) {
	for (int i = h[x]; i != -1; i = h[x]) {		// 这样放还是会正常遍历邻边，只不过第二次还是遍历第h[x]条边，此时执行完h[x] = e[i].nex，然后continue跳到第三次，就正常遍历第二条邻边了
		if (e[i].vis == true) {
			h[x] = e[i].nex;		// 其实是相当于把 一个点的起边 从 h[x] 往后推了，直接覆盖掉原来的路径，这样就不会再重复访问了，没写下面是因为会死循环，若h[x]还没到-1，就有有环了，触发vis，就会不停continue
			continue;
		}
		e[i].vis = e[i ^ 1].vis = true;
		dfs(e[i].to);
		ansm.push(e[i].ndg);
	}
	ansn.push(x);
}

// ai给的代码，确实不错，和上面这个优化代码思想是一样的，&i = h[x] && i = e[i].nex 使得无论 vis 是否判定，都会自动截断，从而规避了在h[x]==-1前遇到环就死循环的特点
//void dfs(int x) {
//	for (int& i = h[x]; i != -1; i = e[i].nex) {
//		if (e[i].vis) continue;
//
//		int t = i;
//		e[t].vis = e[t ^ 1].vis = true;
//
//		dfs(e[t].to);
//
//		ansm.push(e[t].ndg);
//	}
//	ansn.push(x);
//}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		add(x, y);
		add(y, x);
		deg[x]++;	deg[y]++;
	}

	int st = 1;		// start，起始点索引
	for (int i = 1; i <= n; ++i) {
		if (deg[i] % 2 == 1) {
			st = i; break;
		}
	}

	dfs(st);		// 从 st 开始，点

	while (!ansm.empty()) {
		cout << ansm.top() << " ";
		ansm.pop();
	} cout << endl;
	while (!ansn.empty()) {
		cout << ansn.top() << " ";
		ansn.pop();
	} cout << endl;

	return 0;
}

/* 测试样例：
6 9
1 2
1 3
2 3
3 5
5 4
3 4
4 7
7 6
4 6

结果：
	2 10 16 15 13 9 7 5 1
	1 3 4 6 7 4 5 3 2 1
*/