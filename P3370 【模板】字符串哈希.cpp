// 这里使用 自然进位hash/单进制hash  双进制hash 三种方法做
//#include <iostream>
//#include <cmath>
//#define MOD 13192833
//using namespace std;
//int n;
//int b = 97;		// 进制
//string s;		// 记录当前字符串 各位的字符
//int w[1508];	// 当前字符串各位的进制后的值
//int h[10008];		// 记录各个字符串 hash值
//int res[MOD];
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		// 取出当前字符串
//		cin >> s;
//		int l = s.size();
//		for (int j = 0; j < l; ++j) {
//			w[j] = (int)s[j];
//		}
//		// 计算 hash值
//		for (int j = 0; j < l; ++j) {
//			h[i] = (h[i] * b + w[j]) % MOD;
//		}
//	}
//
//		// 遍历 h[] 找不重复的结果个数
//		for (int i = 0; i < n; ++i) {
//			res[h[i]]++;					// 将 所有hash值 -映射-> res表中，记录各个值的个数
//		}
//		int sum = 0;
//		for (int i = 0; i < MOD; ++i) {
//			if (res[i] != 0) sum++;
//		}
//		cout << sum << endl;
//
//		return 0;
//	
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ULL unsigned long long
#define b 131		// 进制
using namespace std;
int n;
vector<int> h;		// 字符串对应 hash值

int main() {
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		ULL hash_val = 0;
		for (char x : s) {
			hash_val = hash_val * b + x;		// 自然溢出截断，unsigned long long
		}
		h.push_back(hash_val);
	}
	sort(h.begin(), h.end());		// unique 是把相邻的重复元素放到末尾，所以时间复杂度为 O(n),需要sort排序
	int sum = unique(h.begin(), h.end()) - h.begin();		// 两个迭代器相减，得到的就是去重后有效元素的个数。
	cout << sum << endl;

	return 0;
}