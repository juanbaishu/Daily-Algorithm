//							O(n^3)解法，超时了，直接用双指针计数不行
//#include <iostream>
//#include <cstring>
//using namespace std;
//string s;
//int arr[26];
//int sum;
//
//void acc(int l, int r) {
//	memset(arr, 0, sizeof(arr));
//	for (int i = l; i <= r; ++i) {
//		arr[s[i] - 'a']++;
//	}
//
//	for (int i = 0; i < 26; ++i) {
//		if (arr[i] == 1) {
//			sum++;
//		}
//	}
//}
//
//int main() {
//	cin >> s;
//	int l = 0, r = 0;
//	while (r < s.size()) {
//		l = 0;
//		while (l <= r) {
//			acc(l, r);
//			l++;
//		}
//		r++;
//	}
//	cout << sum << endl;
//
//	return 0;
//}

//								O(n)写法，主要用乘法原理判断某个元素的集合个数，然后累加，需要知道该元素的上次出现位置 和 下次出现位置
#include <iostream>
#include <cstring>
using namespace std;
int la[100008], na[100008];			// last、next
string s;
int a[27];							// 26个英文字母个数
long long ans;

int main() {
	cin >> s;
	memset(a, -1, sizeof(a));
	memset(la, -1, sizeof(la));									// -1 补码为 1111 1111，所以可以直接填
	for (int i = 0; i < s.size(); ++i) na[i] = s.size();		// memset是按字节进行填充，如果直接填入 s.size()，会将四个个字节都填充成对应补码，eg.memset(a,1,sizeof(a))，最后 a: 0000 0001 0000 0001...

	for (int i = 0; i < s.size(); ++i) {
		// 过滤掉初次出现的元素
		if (a[s[i] - 'a'] == -1) {
			a[s[i] - 'a'] = i;
			continue;
		}
		// 更新 la
		la[i] = a[s[i] - 'a'];			// 记录上一位置
		// 更新 na
		na[a[s[i] - 'a']] = i;			// 记录下一位置
		a[s[i] - 'a'] = i;				// 相当于时媒介，代表上一位置

	}
		// 更新 ans
	for (int i = 0; i < s.size(); ++i) {
		ans += (i - la[i]) * (na[i] - i);			// 需要 la 逐个记录上一位置
	}
	cout << ans << endl;

	return 0;
}
