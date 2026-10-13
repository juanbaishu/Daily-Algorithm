#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <climits>
#define ll long long
using namespace std;

//int main() {
//	// init
//	string s;
//	cin >> s;
//	for (auto c : s) c = tolower(c);
//
//	// judge
//	if (s.size() % 2) { cout << "NO" << endl; return 0; }
//	else {
//		int n = s.size();
//		for (int i = 0; i < (n / 2); ++i) {
//			if (s[n - i - 1] != s[i]) {
//				cout << "NO" << endl;
//				return 0;
//			}
//		}
//	}
//	cout << "YES" << endl;
//
//	return 0;
//}

// A题答案
//int main() {
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.size(); ++i) {
//		if (isupper(s[i])) s[i] += 'a' - 'A';
//	}
//	//cout << s << endl;
//	//sort()
//
//	string s_r(s);
//	reverse(s_r.begin(), s_r.end());
//
//	if (s == s_r) cout << "YES" << endl;
//	else cout << "NO" << endl;
//
//	return 0;
//}

// B题答案
//set<int> arr;								// 存储优先度
//unordered_map<int, vector<int> > ma;		// 存储 优先度 --> 各个样例
//vector<int> res;							// 存储结果
//
//int main() {
//	// init
//	int n;	cin >> n;
//	while (n--) {
//		int no, pi;	cin >> no >> pi;
//		arr.insert(pi);
//		ma[pi].push_back(no);
//	}
//
//	// sort
//	for (int i : arr) {
//		// 取出每个pi容器中的样例
//		sort(ma[i].begin(), ma[i].end());		// 排序
//		reverse(ma[i].begin(), ma[i].end());	// 倒序排
//		for (int j : ma[i]) res.push_back(j);	// 放入 res 中，依次遍历每个 ma[i]
//	}
//	reverse(res.begin(), res.end());
//
//	// cout
//	for (int i : res) {
//		cout << i << endl;
//	}
//
//	return 0;
//}

// E题答案
//vector<int> arr(200008, 0);
//int main() {
//	// init
//	int n, k;	cin >> n >> k;
//	for (int i = 1; i <= n; ++i) { cin >> arr[i]; if (arr[i] >= k) arr[i] = 1; else arr[i] = 0; }
//
//	// judge
//	//int l = 0, r = 0;
//	//while (1) {
//	//	// 找区间起点
//	//	if (!arr[l]) l = r + 1;
//	//	// 找区间终点
//	//	while ()
//	//	// 判断
//	//}
//	int res = 0;
//	int t = 0;
//	for (int i = 1; i <= n+1; ++i) {
//		// 遍历
//		if (arr[i]) t++;
//		// 终止条件
//		else {
//			res = max(res, t);
//			t = 0;
//		}
//	}
//	
//	// cout
//	cout << res << endl;
//
//	return 0;
//}

// C题答案
//vector<int> arr(200008, INT_MAX);
//int cnt = 0;
//int main() {
//	// init
//	int n; ll s;	cin >> n >> s;
//	for (int i = 0; i < n; ++i) cin >> arr[i];
//	sort(arr.begin(), arr.end());
//
//	// calculate
//	for (int i = 0; i < n; ++i) {
//		s -= arr[i];
//		cnt++;
//		//cout << arr[i] << endl;
//		//cout << s << endl;
//		if (s < 0) { cnt--; break; }
//	}
//
//	// cout
//	cout << cnt << endl;
//
//	return 0;
//}

// F题答案
//string s;
//int res;
//int main() {
//	cin >> s;
//	int t = 0;
//	for (char c : s) {
//		if (c == '(') { t++; res = max(res, t); }
//		else t--;
//	}
//	
//	// cout
//	cout << res << endl;
//
//	return 0;
//}

// G题答案
ll res;
int n, m;
vector<ll> arr(200008, 0);

bool check(ll mid) {
	int cnt = 0;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += arr[i];
		if (sum > mid) { sum = 0; cnt++; i--; }
	}
	if (cnt+1 <= m) return true;		// 第一次发车也需要统计
	else return false;
}

void dic(ll ma, ll mi) {		// 二分
	ll mid = mi;
	ll l = mi, r = ma;
	while (l != r) {
		mid = (l + r) / 2;
		if (check(mid))  r = mid;			// r = mid 而不是 r = mid - 1，是因为 mid 可能是最后答案，不能跳过去
		else l = mid + 1;								// 答案一定不是 mid，所以可以直接跳过去
	}
	res = l;		// 循环结束的条件是 l == r，因为循环最后一轮，要么执行 r = mid 要么执行 l = mid + 1，所以 最后结果可能不是 mid，但一定是 l/r
}



int main() {
	cin >> n >> m;
	ll ma = 0, mi = 0;
	for (int i = 1; i <= n; ++i) { cin >> arr[i]; mi = max(mi, arr[i]); ma += arr[i]; }

	dic(ma, mi);

	cout << res << endl;

	return 0;
}