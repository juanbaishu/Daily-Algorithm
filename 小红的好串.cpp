#include <iostream>
using namespace std;
string s;
int table[27];

int main() {
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		table[s[i] - 'a']++;
	}

	int cnt = 0;
	for (int i = 1; i <= 26; ++i) {
		if (table[i]) cnt++;
	}
	if (cnt == 2) cout << "Yes";
	else cout << "No";

	return 0;
}