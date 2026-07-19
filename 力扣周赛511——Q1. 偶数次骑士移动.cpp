#include <iostream>
#include <vector>
using namespace std;

bool canReach(vector<int>& start, vector<int>& target) {
	long long res = target[0]; res += target[1]; res -= start[0]; res -= start[1];
	if (res % 2 == 0) return true;
	return false;
}

int main() {


	return 0;
}