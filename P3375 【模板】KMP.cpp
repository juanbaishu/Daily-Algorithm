//								最原始的暴力算法
//#include <iostream>
//#include <cstring>
//using namespace std;
//string s1, s2;		// 主串、模式串
//
//int main() {
//	cin >> s1 >> s2;
//	
//	int flag = 0;		// 字符串匹配标志
//	for (int i = 0; i < s1.size(); ++i) {
//		int k = i;
//		int j;
//		for (j = 0; j < s2.size(); j++) {
//			if (s1[k] == s2[j]) {
//				k++;
//			}
//		}
//		if (k-i == s2.size()) cout << i+1 << endl;		// 输出每次重合时的 l 位置
//	}
//
//	return 0;
//}


//			KMP算法，优化遍历过程中 k 的移动，借助最大相同前后缀，不向后移动 k
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
string s1, s2;		// 主串，模式串
vector<int> nex;	// 记录限定长度时的最大相同前后缀的长度
vector<int> res_l;	// 记录配对结果的左索引位置

//int calcu_lenth(int x, string s) {		// x 是 s 中可使用的部分长度
//	int lenth_ma = 0;
//	// 根据 x 枚举各种前后缀情况，进行 border 计算
//	for (int i = 1; i < x; ++i) {		// 前后缀长度，i==x的话就重合了，不行
//		int lenth = 0;
//		int rp = i-1, lp = x-i;		// 枚举前缀右边索引、后缀左边索引
//		for (int j = 0; j <= rp; ++j) {
//			if (s[j] == s[j + lp]) lenth++;
//			else { lenth = 0; break; }			// 防止 前缀"ABC" 后缀 "ACC" 时让 lenth==1成立，只是前面有一个字符相同而已，lenth应该保存匹配时的结果
//		}
//		lenth_ma = max(lenth_ma, lenth);
//	}
//	return lenth_ma;
//}

int main() {
	cin >> s1 >> s2;

	// 计算最大相同前后缀															这个暂时不懂
	nex.resize(s2.size(), 0); // 分配空间，初始都为 0

	int j = 0; // j 既是前缀的待比对索引，也是当前已匹配成功的 border 长度
	for (int i = 1; i < s2.size(); ++i) { // i 从 1 开始，作为后缀的末尾指针

		// 【看！这就是你写的向前滚逻辑！】
		// 如果字符对不上，且 j 还能退，j 就查前面的成果一直往回滚
		while (j > 0 && s2[i] != s2[j]) {
			j = nex[j - 1];
		}

		// 如果对上了，说明相同的 border 长度可以在之前的基础上加 1
		if (s2[i] == s2[j]) {
			j++;
		}

		nex[i] = j; // 记录当前长度为 i+1 的前缀的最长 border 长度
	}


	//for (int i = 1; i <= s2.size(); ++i) {
	//	nex.push_back(calcu_lenth(i, s2));			// i == 1 时的结果会被存入 nex[0] 中
	//}

	//while (!nex.empty()) {
	//	cout << nex.front() << ' ';
	//	nex.pop();
	//}

	// 计算字符串匹配情况
	int i = 0;		// 主串索引
	j = 0;		// 模式串索引
	while (i < s1.size()) {
		if (s1[i] == s2[j]) {
			i++; j++;
			if (j == s2.size()) {
				res_l.push_back(i-s2.size()+1);		// 存结果，实际位置==索引+1
				j = nex[j - 1];
			}
		}
		else if (j > 0) {		// 防止 j-1 == -1 冲突
			j = nex[j - 1];		// 对应的最大相同前后缀长度			只要遇到对不上的就能一直查表向前滚，等到 nex[]==0 时就会 触发 i++，进行下一轮
		}
		else i++;
	}

	// 输出结果
	for (int i : res_l) cout << i << endl;
	for (int i : nex) cout << i << ' ';

	return 0;
}