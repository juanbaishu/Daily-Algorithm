//#include <iostream>
//#include <stack>
//#include <cstring>
//using namespace std;
//
//int q, n;
//int a[100005], b[100005];
//stack<int> p;
//
//int main() {
//	cin >> q;
//	for (int k = 1; k <= q; ++k) {
//		cin >> n;
//		memset(a, 0, sizeof(a));
//		memset(b, 0, sizeof(b));
//		p = stack<int>();		// 清空栈的写法
//
//		for (int i = 1; i <= n; ++i) {
//			cin >> a[i];
//		}
//		for (int i = 1; i <= n; ++i) {
//			cin >> b[i];
//		}
//
//		int i, j = 1;
//		for (i = 1; i <= n; ++i) {
//			// 入栈情况
//			p.push(a[i]);
//			// 出栈情况
//			while (!p.empty() && p.top() == b[j]) {
//				p.pop();
//				j++;
//			}
//		}
//		if (p.empty()) cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//
//	return 0;
//}



// 二刷，直接模拟
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n;
vector<int> a, b;		// 存储入栈、出栈序列


int main() {
	int q;
	cin >> q;
	while (q--) {
		a = vector<int>(); b = vector<int>();		// 清空
		cin >> n;
		for (int i = 1; i <= n; ++i) { int t; cin >> t; a.push_back(t); }
		for (int i = 1; i <= n; ++i) { int t; cin >> t; b.push_back(t); }

		stack<int> st;			// q = stack<int>();	申请空栈的写法
		int i, j = 0;
		for (i = 0; i < n; ++i) {
			// 入栈
			st.push(a[i]);
			// 找到对应数了，出栈
			while (!st.empty() && st.top() == b[j]) { st.pop(); j++; }
		}
		if (st.empty()) cout << "Yes" << endl; 		// 栈空 --> 出栈顺序可以
		else cout << "No" << endl;
	}

	return 0;
}