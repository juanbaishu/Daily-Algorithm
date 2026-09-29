//// 枚举出 bob 出牌的所有可能性，只要找到赢得情况就行
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	// 接收数据
//	int n;	cin >> n;
//	vector<int> A(n);
//	vector<int> B(n);
//	for (int i = 0; i < n; ++i) cin >> A[i];
//	for (int i = 0; i < n; ++i) cin >> B[i];
//	sort(B.begin(), B.end());
//
//	int gcd(int, int);
//	bool BobWin = false;
//
//	// 进行判定
//	do {
//		int ok = true;
//		// 若该序列中一个对不上 ---> 本轮不对，换序列
//		for (int i = 0; i < n; ++i) {
//			if (gcd(A[i], B[i]) != 1) {
//				ok = false;
//				break;
//			}
//		}
//		// 若全成功，就成功 --> Bob 赢
//		if (ok == true) {
//			BobWin = true;
//			break;
//		}
//
//	} while (next_permutation(B.begin(), B.end()));		// 枚举 B 的所有序列
//
//	// 输出结果
//	cout << (BobWin ? "Bob" : "Alice") << endl;			// << 优先级高于 ? ，所以需要加括号
//
//	return 0;
//}
//
//
//int gcd(int x, int y) {
//	int t;
//	while (y != 0) {
//		t = x;
//		x = y;
//		y = t % y;
//	}
//	return x;
//}



// 枚举出 bob 出牌的所有可能性，只要找到赢得情况就行
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> A, B;
vector<bool> used;
bool found = false;

int gcd(int x, int y) {
    while (y != 0) {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

void dfs(int pos) {
    if (found) return;

    if (pos == n) {
        found = true;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (gcd(A[pos], B[i]) != 1) continue;  // 给 A[pos] 配 B[i]

        used[i] = true;
        dfs(pos + 1);
        used[i] = false;

        if (found) return;  // 已经找到答案，提前结束
    }
}

int main() {
    cin >> n;
    A.resize(n);
    B.resize(n);
    used.resize(n);

    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    dfs(0);

    cout << (found ? "Bob" : "Alice") << endl;

    return 0;
}
