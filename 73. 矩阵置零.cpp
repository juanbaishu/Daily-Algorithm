#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    //// 申请空间，遍历版
    //void setZeroes(vector<vector<int>>& matrix) {
    //    typedef pair<int, int> PII; PII p;
    //    vector<PII> res;
    //    // 存数据
    //    for (int i = 0; i < matrix.size(); ++i) {
    //        for (int j = 0; j < matrix[i].size(); ++j) {
    //            if (matrix[i][j] == 0) { 
    //                p.first = i, p.second = j; 
    //                res.push_back(p);
    //            }
    //            
    //        }
    //    }
    //    // 改值
    //    for (int i = 0; i < res.size(); ++i) {
    //        PII t = res[i];
    //        int row = t.first, line = t.second;
    //        // 改行
    //        for (int j = 0; j < matrix[row].size(); ++j) {
    //            matrix[row][j] = 0;
    //        }
    //        // 改列
    //        for (int j = 0; j < matrix.size(); ++j) {
    //            matrix[j][line] = 0;
    //        }
    //    }
    //}

    // 常量空间版
    void setZeroes(vector<vector<int>>& matrix) {
        // 申请 行、列 标记数组
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) row[i] = col[j] = true;
            }
        }
        // 进行遍历改写
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};

int main() {


	return 0;
}