#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
typedef long long ll;
#define ui unsigned int
using namespace std;
// 尝试dfs做
void dfs(int x, int y, int r);
int n, m;
struct mes {				// 上方名称是结构体名称，下方就是变量声明
	int x; int y; int r;
} pos;
vector<mes> Landmine;
map<ll, stack<int> > mp;	// 存地雷的坐标信息，longlong用来存坐标信息32位32位，用vector<int> 而非 int 是因为同位置可多放地雷
vector<mes> Rocket;
int ans;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> pos.x >> pos.y >> pos.r;
		mp[((ll)pos.x << 32) | (ui)pos.y].push(pos.r);	// 记录地雷坐标，mp[key].push_back() 才能存储 vector<int>的值
		Landmine.push_back(pos);
	}
	for (int i = 0; i < m; ++i) {
		cin >> pos.x >> pos.y >> pos.r;
		Rocket.push_back(pos);
	}

	for (int i = 0; i < m; ++i) {
		dfs(Rocket[i].x, Rocket[i].y, Rocket[i].r);
	}

	cout << ans << endl;
	
	return 0;
}

void dfs(int x, int y, int r) {		// 爆炸物的范围(include rocket and landmine)
	for (ll i = x - r; i <= x + r; ++i) {
		for (ll j = y - r; j <= y + r; ++j) {
			if (!mp.count((ll)i << 32 | (ui)j)) continue;
			while (!mp[(ll)i << 32 | (ui)j].empty() && ((i - x) * (i - x) + (j - y) * (j - y)) <= r * r) {		// 有雷 && 够得着
				int nr = mp[(ll)i << 32 | (ui)j].top();
				mp[(ll)i << 32 | (ui)j].pop();

				ans++;
				dfs(i, j, nr);
			}
		}
	}
}