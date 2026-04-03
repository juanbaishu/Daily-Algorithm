#include <iostream>
using namespace std;
string str[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

int main() {
	string s, s1, s2;
	cin >> s;
	s1.insert(s1.begin(), s.begin(), s.end() - 2);
	s2.insert(s2.begin(), s.end()-2, s.end());
	for (int i = 0; i < 12; ++i) {
		if (s1 == str[i]) {
			cout << arr[i] << " ";
		}
	}
	if (s2[0] == '0') {
		string t;
		t = s2[1];
		s2.clear();
		s2 = t;
	}
	cout << s2 << endl;

	return 0;
}