#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

class Solution {
public:
    int flag;       // 1: ture      0: false

    bool match(char x, char y) {
        if ((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}')) return true;
        return false;
    }

    bool isValid(string s) {
        // 左 --> 右
        stack<char> st;
        flag = 1;
        for (char c : s) {
            // 放入适合左括号
            if (c == '(' || c == '[' || c == '{') st.push(c);
            // 处理匹配右括号
            else if (!st.empty() && match(st.top(), c)) st.pop();       // 忘加 else 就会多处理一步
            // 其他情况就是错误
            else { flag = 0; break; }
        }
        // 处理多填入的左括号
        if (!st.empty()) flag = 0;
        
        // 输出
        if (flag == 1) return true;
        else return false;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    if (sol.isValid(s) == true) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}