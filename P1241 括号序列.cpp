//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//vector<char> s;
//stack<char> a;
//
//int main() {
//	char t;
//	while (cin >> t) {
//		s.push_back(t);
//	}
//
//	int n = s.size();
//	for (int i = 0; i < n; ++i) {
//		// 左括号入栈
//		if (s[i] == '(' || s[i] == '[') {
//			if (!a.empty()) {
//				if (a.top() == '(') { a.push(')'); }
//				if (a.top() == '[') { a.push(']'); }
//			}
//			a.push(s[i]);
//		}
//		// 右括号匹配
//		else if (s[i] == ')') {
//			if (!a.empty() && a.top() != '(') {
//				a.push('(');
//				a.push(s[i]);
//			}
//			else if (!a.empty() && a.top() == '(') {
//				a.pop();
//			}
//			else {		// a.empty() 成立时
//				a.push('(');
//				a.push(s[i]);
//			}
//		}
//		else {
//			if (!a.empty() && a.top() != '[') {
//				a.push('[');
//				a.push(s[i]);
//			}
//			else if (!a.empty() && a.top() == '[') {
//				a.pop();
//			}
//			else {
//				a.push('[');
//				a.push(s[i]);
//			}
//		}
//	}
//
//	stack<char> b;
//	while (!a.empty()) { b.push(a.top()); a.pop(); }
//	while (!b.empty()) { cout << b.top(); b.pop(); }
//
//	return 0;
//}












// 二刷，之前还是没写出来
// 重构一下，分两轮执行，先标记匹配项，再依次整理 queue 中输出

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> v;		// 标记，标记处说明已配对，无需补对应括号
string s;
queue<char> q;

char match(char x) {
	if (x == '(') return ')';
	if (x == ')') return '(';
	if (x == '[') return ']';
	if (x == ']') return '[';
}

bool check(char x, char y) {
	if (y == match(x)) return true;
	return false;
}

int main() {
	cin >> s;
	s = ' ' + s;
	v.resize(s.size());		// 从 索引1 开始

	// 进行标记
	for (int i = 1; i <= s.size() - 1; ++i) {
		int flag = 0;	// 不存在左括号 标志
		// 判断 i 是否有匹配项
		if (s[i] == ')' || s[i] == ']') {		// 右括号 情况
			for (int j = i - 1; j >= 1; --j) {
				if ((s[j] == '(' || s[j] == '[') && s[j] == match(s[i]) && v[j] == 0) {		// 找到匹配项，v[j] == 0使得匹配过的左括号下次不再匹配
					v[j] = v[i] = 1; break;
				}
				else if ((s[j] == '(' || s[j] == '[') && s[j] != match(s[i]) && v[j] == 0) {	// 不匹配情况
					v[i] = 0; break;
				}
				if (s[j] == '(' || s[j] == '[') flag = 1;	// 存在左括号
				// 未找到 左括号情况
				if (j == 1 && flag == 0) v[i] = 0;
			}
			
		}
		// 右括号情况 由 右边的左括号 决定，所以不用判断
	}

	// 进行整理
	for (int i = 1; i <= s.size() - 1; ++i) {
		if (v[i] == 0) {
			if (s[i] == '(' || s[i] == '[') { q.push(s[i]); q.push(match(s[i])); }
			else { q.push(match(s[i])); q.push(s[i]); }
		}
		else {
			q.push(s[i]);
		}
	}

	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}

	return 0;
}

// 便于理解的两组样例：
//	样例1：
//	input:	([)])	output:	([()])
//	样例2：
//	input:	([(])	output:	()[]([])



// stack写法暂时不想写，这题写了一整天，太费脑子了