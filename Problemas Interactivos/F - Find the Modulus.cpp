#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long tint;

const tint query1 = 1e18;

tint askNumber (tint num) {
    cout << "? " << num << endl;
    tint temp; cin >> temp;
    return temp;
}

void answer (tint num) {
    cout << "! " << num << endl;
}

tint gcd (tint a, tint b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

void solve (int T) {
    tint num1 = query1 - askNumber(query1);
    tint num2 = (num1 - 1) - askNumber(num1 - 1);
    answer(gcd(num1, num2));
}

int main () {
    int T; cin >> T;
    forn (i,T) solve(T);
}