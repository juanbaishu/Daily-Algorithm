#include <iostream>
#include <cstring>
using namespace std;
int n;
string s;
int arr[4];

int main() {
	cin >> n;
	cin >> s;
	for (char x : s) {
		arr[x - 'A']++;
	}

	if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}