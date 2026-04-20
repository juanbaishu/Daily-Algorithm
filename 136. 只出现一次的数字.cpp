#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int n;
vector<int> nums;

//		异或运算
int singleNumber(vector<int>& nums) {
	int ans = 0;
	for (int x : nums) {		// 依次枚举元素值
		ans ^= x;
	}
	return ans;
}

//		栈写法
//int singleNumber(vector<int>& nums) {		// 非空、存在一个出现一次元素、其余均为出现两次元素
//	sort(nums.begin(), nums.end());
//	int n = nums.size();
//	stack<int> s;
//	for (int i = 0; i <= n - 1; ++i) {
//		s.push(nums[i]);
//		if (i + 1 != n) {
//			if (s.top() == nums[i + 1]) {
//				s.pop();
//				i++;
//				continue;
//			}
//		}
//		return s.top();
//	}
//}

//		左右检查写法
//int singleNumber(vector<int>& nums) {		// 非空、存在一个出现一次元素、其余均为出现两次元素
//	sort(nums.begin(), nums.end());
//	int res = nums[0];
//	int n = nums.size();
//	for (int i = 0; i <= n-1; ++i) {
//		// 输入单数情况 {1}
//		if (n == 1) return res;
//		// 输入多数情况 {2, 1, 3, 2, 3}
//		if (i - 1 != -1 && i + 1 != n) if (res == nums[i - 1] || res == nums[i + 1]) { res = nums[i + 1]; continue; }		// 不越界情况
//		if (i - 1 == -1) if (res == nums[i + 1]) { res = nums[i + 1]; continue; }
//		//if (i + 1 == n) if (res == nums[i - 1]) continue;		// 能走到最后就已经说明这里是 res 了
//		return res;
//	}
//}

int main() {
	cin >> n;
	int t;
	while (n--) { cin >> t; nums.push_back(t); }
	int res = singleNumber(nums);
	cout << res << endl;

	return 0;
}