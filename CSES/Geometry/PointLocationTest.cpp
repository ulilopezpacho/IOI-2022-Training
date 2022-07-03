#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long tint;

struct Point {
    tint x, y;
    Point operator +(const Point &o) const {
        return {x+o.x, y+o.y};
    }
    Point operator -(const Point &o) const {
        return {x-o.x, y-o.y};
    }
    tint operator *(const Point &o) const {
        return x*o.x + y*o.y;
    }
    tint operator ^(const Point &o) const {
        return x*o.y - y*o.x;
    }
};

tint signo (const tint e) {
    if (e < 0) return -1;
    else if (e > 0) return 1;
    else return 0;
}

tint lado (const Point A, const Point B, const Point C) {
    return signo((B-A)^(C-A));
}

void solve () {
    tint x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    Point p1, p2, p3;
    p1 = {x1,y1};
    p2 = {x2,y2};
    p3 = {x3,y3};

    tint resultado = lado(p1, p2, p3);
    if (resultado < 0) cout << "RIGHT\n";
    if (resultado == 0) cout << "TOUCH\n";
    if (resultado > 0) cout << "LEFT\n";

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    forn (i, T) solve();
}