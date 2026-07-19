#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
string s; 	vector<int> vs;		// 存入 1 的索引位置
string t;	vector<int> vt;	
int dif = 0;

void init() {
	s = ' ' + s;				// size() 记得 -1
	t = ' ' + t;
	vs.push_back(0);
	vt.push_back(0);
}

int main() {
	init();
	cin >> n;
	string ss, tt;
	cin >> ss >> tt;
	s += ss; t += tt;	// 累加防止覆盖
	for (int i = 1; i <= s.size() - 1; ++i) {
		if (s[i] != t[i]) {
			if (s[i] == '1')  vs.push_back(i);
			if (t[i] == '1')  vt.push_back(i);
		}
		if ((s[i] == '1' && t[i] != '1') || (s[i] != '1' && t[i] == '1')) dif++;
	}

	// 输出
	dif /= 2;
	cout << 3 * dif << endl;		// 3 * 需要调整的1的个数
	for (int i = 1; i <= vs.size() - 1; ++i) {
		if (vt[i] == vs[i]) continue;
		cout << min(vt[i], vs[i]) << endl;
		cout << max(vt[i], vs[i]) << endl;
		cout << min(vt[i], vs[i]) << endl;
	}

	return 0;
}