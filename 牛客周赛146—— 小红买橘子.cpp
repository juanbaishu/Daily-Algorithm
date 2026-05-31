#include <iostream>
using namespace std;
int cnt;		// 袋数
int x, y, z;	// 每袋花费、每袋个数、需要个数

int main() {
	cin >> x >> y >> z;
	while (z > 0) { cnt++; z -= y; }
	cout << (long long)cnt * x << endl;
	return 0;
}