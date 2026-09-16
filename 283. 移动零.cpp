#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1) return;
        // 将数组中所有的0值，全部移动到后面
        int l = 0;  // 一个从前遍历，一个从后遍历
        int t;
        int max_r = nums.size() - 1;    // 边界
        //for (int r = 0; r < nums.size(); ++r) {
        //    if (nums[r] != 0) {
        //        swap(nums[l], nums[r]);
        //        l++;
        //    }
        //}

        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] != 0) {
                if (nums[l] == 0) swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};

int main() {
    vector<int> num;
    Solution s;
    s.moveZeroes(num);

	return 0;
}