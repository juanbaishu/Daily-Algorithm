// 这里使用 自然进位hash/单进制hash  双进制hash 三种方法做



//			自然溢出
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#define ULL unsigned long long
//#define b 131		// 进制
//using namespace std;
//int n;
//vector<ULL> h;		// 字符串对应 hash值
//
//int main() {
//	cin >> n;
//	while (n--) {
//		string s;
//		cin >> s;
//
//		ULL hash_val = 0;
//		for (char x : s) {
//			hash_val = hash_val * b + x;		// 自然溢出截断,这里相当于隐藏了一个MOD(2^64)
//		}
//		h.push_back(hash_val);
//	}
//	sort(h.begin(), h.end());		// unique 是把相邻的重复元素放到末尾，所以时间复杂度为 O(n),需要sort排序
//	int sum = unique(h.begin(), h.end()) - h.begin();		// 两个迭代器相减，得到的就是去重后有效元素的个数。
//	cout << sum << endl;
//
//	return 0;
//}


//			双hash值取法
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define MOD1 (int)(1e9 + 7)
#define MOD2 (int)(1e9 + 9)
#define b1   131
#define b2   13331
#define ll long long
using namespace std;
int n;
vector<pair<ll, ll> > v;

int main() {
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		ll t1 = 0, t2 = 0;
		for (char x : s) {
			t1 = ((t1 * b1) + x) % MOD1;
			t2 = ((t2 * b2) + x) % MOD2;
		}
		v.push_back({ t1, t2 });
	}

	sort(v.begin(), v.end());
	int sum = unique(v.begin(), v.end()) - v.begin();		// 迭代器差值为 不重复数个数
	cout << sum << endl;

	return 0;
}