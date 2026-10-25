#include <iostream>
#include <cmath>
#include <climits>
#define ll long long
using namespace std;

ll gcd(ll x, ll y) {
    while (y != 0) {
        ll t = x;
        x = y;
        y = t % x;
    }
    return x;
}

int main() {
    ll x;    cin >> x;
    ll num = 1;
    while (gcd(num * 2 + 1, x) != 1) {
        //         if (num > x) break;
        if (num == INT_MAX) break;
        num += 1;
    }

    //     if (x > num) cout << (x + 1) - num << ' ' << (x + 1) + num;
    //     else cout << -1 << endl;
    if (x != INT_MAX) cout << (x + 1) - num << ' ' << (x + 1) + num;
    else cout << "-1" << endl;

    return 0;
}