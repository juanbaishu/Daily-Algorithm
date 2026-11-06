// 这一题我发现，直接进行模拟，最坏时间复杂度为O(10 ^ 5 * 10 ^ 5)，绝对会超时，但是又找不到每次O(1)级别的找到落脚点的方法，
// 所以，我找到了一个比较中和的思路。就是将源数组存起来，然后搞一个一样大小的标记数组，TA的值用来记录落脚点为当前位置的话，
// 向后最近的可以落脚的落脚点的位置，这样也能实现O(1)级别寻找寻找，最后时间复杂度能到O(2 * 10 ^ 5)
#include <iostream>
#include <vector>
#define CIRCULAR(x) ((x - 1) % n) + 1		// 用于环结构位置计算
using namespace std;

int n, m;
vector<int> arr(200008, 0);
vector<int> nex_pos(200008, 0);		// 更新路径时间最坏为 O(2*10^5)，所以不行，用并查集的 O(logn) 级别的更好，主要是并查集中的路径压缩 (所有子节点 --> 全都直接连到根节点上，就没有最坏遍历的情况了)
long long sum = 0;

int find(int x) {
	if (x == nex_pos[x]) return x;

	return nex_pos[x] = find(nex_pos[x]);		// 递归，路径压缩
}


int main() {
	// init
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; ++i) nex_pos[i] = i;

	// judge，边遍历，边更新 nex_pos
	int pos = 1;
	while (m--) {
		int t;	cin >> t;
		//pos += t;
		pos = CIRCULAR(pos + t);
		// 找应该落脚的地方
		pos = find(pos);			// 直接调用 nex_pos[pos]可能错误，因为路径压缩只会压缩一段路径上的节点

		sum += arr[pos];		// 占用直接累加结果，因为最后一轮访问边界n位置时会有小bug，只有最后一轮会产生，因为每次更新当前位置的下一可用位置指针时，一定是找后方一格位置的祖宗，所以不会出现找祖宗，第一项连到最后一项的情况，中间部分肯定是被占用过的
		// 更新 nex_pos
		//nex_pos[pos] = CIRCULAR(pos + 1);		// 默认祖宗变成后面的节点，接着就会去查 后面节点的 祖宗
		//nex_pos[pos] = find(pos);			// 更新 落脚点的祖宗
		nex_pos[pos] = find(CIRCULAR(pos + 1));
	}

	// cout
	cout << sum << ' ';
	cout << pos << endl;

	return 0;
}