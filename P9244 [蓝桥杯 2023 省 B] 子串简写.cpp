#include <iostream>
#include <string>
using namespace std;		// ÀÛ¼ÓË¼Ïë
int k;
string s;
char a, b;
int cnt;
long long ans;

int main() {
	cin >> k >> s >> a >> b;
	
	for (int i = 0, j = k - 1; j < s.size(); ++i, ++j) {
		if (s[i] == a) cnt++;
		if (s[j] == b) ans += cnt;
	}

	cout << ans << endl;

	return 0;
}