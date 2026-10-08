// 使用 sum 记录学生数量，学生数据插入 unordered_map 中，实现 O(1)级访问
#include <iostream>
#include <unordered_map>
#include <cstring>
#define ll long long
using namespace std;

int sum;
unordered_map<string, ll> mp;

int main() {
	int n;	cin >> n;
	while (n--) {
		int t;	cin >> t;
		switch (t) {
			// 插入与修改
		case 1: { 
			// init
			string name; ll score; cin >> name >> score; 
			// 更新 sum
			if (mp.find(name) == mp.end()) sum++;
			// 更新数据
			mp[name] = score; 
			cout << "OK" << endl;
			break;
		}
			// 查询
		case 2: {
			string name; cin >> name;
			if (mp.find(name) == mp.end()) cout << "Not found" << endl;
			else cout << mp[name] << endl;
			break;
		}
			// 删除
		case 3: {
			string name; cin >> name;
			if (mp.count(name)) {
				mp.erase(name);
				sum--;
				cout << "Deleted successfully" << endl;
			}
			else cout << "Not found" << endl;
			break;
		}
			// 输出sum
		case 4: cout << sum << endl;
		}
	}

	return 0;
}