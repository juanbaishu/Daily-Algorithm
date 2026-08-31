/*
#include <iostream>
#include <stack>
using namespace std;
// 本次模板代码实现：从左到右，输出每个数左边第一个大于自身的数，若无则输出 -1
void way_1();
void way_2();
void test();

int a[3000008];
stack<int> s;
int ans[3000008];		// 当栈顶为遍历过的数时，就是对应方向的结果


int main() {
	// way_1();		// 常规写法，掌握这个即可
	//	way_2();		// 复杂点的写法，主要通过下标控制
	test();			// 洛谷 P5788

	return 0;
}

void way_1() {
	int n;		// n <= 100
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	// 从左向右遍历，使用自底开始的递减栈， 进入栈前判断栈顶是否存在大于自身的数，是则输出，否则连续pop直至符合条件
	// 处理pop情况
	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && s.top() <= a[i]) {		// 因为如果 栈顶 == a[i]，那就会输出一个相等的值，而非大于自身的值
			s.pop();
		}
		if (s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();	// 此时剩下的栈顶就是结果
		}
		s.push(a[i]);
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
}

void way_2() {
	int n;		// n <= 100
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	// 这里因为反向遍历，位置不好确定，所以采用 单调栈存储位置的方法
	// 从右向左遍历，因为栈顶为反方向，所以输出的结果应该是符合条件的push入的值，所以应该是自底向上递减的栈，然后就是判断非空情况和pop情况
	// 处理pop情况
	for (int i = n; i >= 1; --i) {
		while (!s.empty() && a[s.top()] < a[i]) {		// 因为满足条件的位置都会执行下面一行指令，所以 栈顶 == a[i]的就不能算入，就不能加等号
			ans[s.top()] = a[i];		// 因为这里填结果，位置只能从栈中取，所以只能在这里搞
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) { ans[s.top()] = -1; s.pop(); }		// 剩下的就是左边没有大的了的，补完


	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
}

void test() {
	int n;		// n <= 100
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	// 根据题目要求，需要在栈中录入位置
	// 从右向左遍历，因为栈顶存储的位置为遍历过的位置，所以当找到 a[i] < 栈顶时就将栈顶存入 ans 中，因此使用自底向上递减栈
	// 处理pop情况
	for (int i = n; i >= 1; --i) {
		// 连续pop情况
		while (!s.empty() && a[s.top()] <= a[i]) {
			s.pop();
		}
		if (s.empty()) {
			ans[i] = 0;
		}
		else {
			ans[i] = s.top();		// 栈顶是右边遍历过的，且符合大于当前值条件的，自然填入答案中
		}
		s.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
}
*/


// 二刷，使用 左 <-- 右，自下向上递减栈，接收元素时，与 .top() 比较大小，小的话 --> 放入stack并记录该位置结果
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n;
stack<int> st;		// 存入索引
vector<int> v, res(3000008, 0);				// 提前申请空间后.push_back()新元素会填在后面

int main() {
	cin >> n;
	v.push_back(0); res.push_back(0);
	for (int i = 1; i <= n; ++i) { int t; cin >> t; v.push_back(t); }

	for (int i = n; i >= 1; --i) {
		// 每轮都能得到当前位的结果
		// 栈顶 <= 当前，一直pop栈顶
		while (!st.empty() && v[st.top()] <= v[i]) st.pop();
		
		// 直到栈顶 > 当前，结果 = 栈顶位置
		// 如果pop完没了，结果 = 0
		if (st.empty()) res[i] = 0;					// 反向搞更简单实现
		else res[i] = st.top();

		// 固定入栈
		st.push(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}

	return 0;
}