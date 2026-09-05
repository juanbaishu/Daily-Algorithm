/*
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
map<ll, stack<int> > mp;	// 存地雷的坐标信息，longlong用来存坐标信息32位32位，用stack<int> 而非 int 是因为同位置可多放地雷
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
			if (!mp.count((ll)i << 32 | (ui)j)) continue;		// 防止 map 后面自动创建不存在坐标，所以这里判断一下这里是否对应有值，empty只能判断空不空
			while (!mp[(ll)i << 32 | (ui)j].empty() && ((i - x) * (i - x) + (j - y) * (j - y)) <= r * r) {		// 有雷 && 够得着
				int nr = mp[(ll)i << 32 | (ui)j].top();
				mp[(ll)i << 32 | (ui)j].pop();

				ans++;
				dfs(i, j, nr);
			}
		}
	}
}
*/

// 二刷，关键是如何遍历爆炸范围内的地雷，直接遍历 --> 超时，这题中爆炸范围都比较小，不如都用map存，然后递归遍历爆炸范围中是否存在
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#define ll long long
#define ui unsigned int
using namespace std;
int n, m;
struct mes {
	ui x, y, r;
} pos;
stack<mes> st;				// 存储 排雷弹
map<ll, stack<int> > mp;	// 存储地雷	ll --> stack,目的是一个坐标可以存多个	高32存x，低32存y
int res = 0;

void dfs(mes pos) {
	ll x, y, r;
	x = pos.x, y = pos.y, r = pos.r;

	// 爆炸
	for (ll i = x - r; i <= x + r; ++i) {
		for (ll j = y - r; j <= y + r; ++j) {
			if (mp.count((ll)i << 32 | (ui)j) == 0) continue;		// 未找到地雷
			while (!mp[(ll)i << 32 | (ui)j].empty() && (i-x)*(i-x) + (j-y)*(j-y) <= r*r) {			// 找到地雷 && 爆炸能炸到
				res++;
					
				ui k = 0;		// 爆炸半径
				k = mp[(ll)i << 32 | (ui)j].top(); mp[(ll)i << 32 | (ui)j].pop();

				// 深度爆破
				dfs({ (ui)i, (ui)j, (ui)k });
			}
			
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) { cin >> pos.x >> pos.y >> pos.r; mp[(ll)pos.x << 32 | pos.y].push(pos.r); }		// 存地雷信息
	for (int i = 1; i <= m; ++i) { cin >> pos.x >> pos.y >> pos.r; st.push(pos); }										// 存排雷弹信息

	// 排雷
	for (int i = 1; i <= m; ++i) {
		dfs(st.top());
		st.pop();
	}

	cout << res << endl;

	return 0;
}