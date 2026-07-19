#include <iostream>
#include <cstring>
using namespace std;
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        if (i == k) continue;
        cout << k << ' ';
        cout << i << endl;
    }

    return 0;
}