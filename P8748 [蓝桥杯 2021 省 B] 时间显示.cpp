#include <iostream>
typedef long long ll;
using namespace std;
ll t;
ll h, m, s;

int main() {
	cin >> t;
	t /= 1000;
	s = t % 60;
	m = t / 60 % 60;
	h = t / 3600 % 24;

	printf("%02d : %02d : %02d", h, m, s);

	return 0;
}