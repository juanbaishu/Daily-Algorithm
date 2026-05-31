#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;		// 传送阵个数、终点
vector<long long> v;	// 传送阵信息，存储差值

int main() {

	cin >> n >> k;
	int t1, t2;
	while (n--) {
		cin >> t1 >> t2;
		v.push_back(abs(t1-0) + abs(k - t2));		// 距离：起点-->传送点，传送地-->终点
	}
	sort(v.begin(), v.end());

	//for (int i : v) cout << i << endl;

	if (abs(k) < v[0]) { cout << abs(k) << endl; return 0; }


	cout << v[0] << endl;

	return 0;
}