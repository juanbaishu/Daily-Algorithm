#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	int t;
	for (int i = 0; i < nums.size(); ++i) {
		bool flag = false;
		// 找补数，是否出现过
		int f = target - nums[i];
		if (m.find(f) != m.end()) flag = true;		// 找到两数，find找不到返回end()迭代器
		// 存入表中
		if (flag == true) t = m[f];
		m[nums[i]] = i;		// 存入索引位置
		if (flag == true) return { min(m[nums[i]], t), max(m[nums[i]], t) };
	}
}


int main() {
	vector<int> a;
	int target;
	// 录入 a... target...
	vector<int> b = twoSum(a, target);
	// 输出 b...

	return 0;
}