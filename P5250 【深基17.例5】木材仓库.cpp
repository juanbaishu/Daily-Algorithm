// 去重、近似匹配 --> 使用 set 容器实现
#include <iostream>
#include <set>
using namespace std;
set<int> s;

int main() {
	int n; cin >> n;
	while (n--) {
		int t;	cin >> t;
		if (t == 1) {
			// 塞木头
			int tt;	cin >> tt;
			if (s.count(tt) == true) cout << "Already Exist" << endl;
			else s.insert(tt);
		}
		else {
			// 取木头
			int tt; cin >> tt;
			if (s.count(tt) == true) {
				cout << tt << endl;
				s.erase(tt);
			}
			else if (s.size() != 0) {
				// 近似匹配
				int res;
				auto it = s.lower_bound(tt);	// >= tt的第一项的迭代器
				if (it == s.end()) { it = prev(it); res = *it; }
				else if (it == s.begin()) res = *it;
				else {		// 两边都有
					auto pre = prev(it);
					if (tt - (*pre) <= (*it) - tt) res = *pre;
					else res = *it;
				}
				s.erase(res);
				cout << res << endl;
				
			}
			else {
				cout << "Empty" << endl;
			}
		}
	}

	return 0;
}