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

istream &operator >>(istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}

tint signo (const tint A) {
    if (A > 0) return 1;
    else if (A < 0) return -1;
    else return 0;
}

tint lado (const Point A, const Point B, const Point C) {
    return signo((B-A)^(C-A));
}

tint dcm (tint a, tint b) {
    if (b == 0) return a;
    else return dcm(b, a%b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Point> polygon (n+1);
    forn (i, n) cin >> polygon[i];
    polygon[n] = polygon[0];

    tint doubleArea = 0, pointsAfuera = 0;
    forn (i, n) doubleArea += (polygon[i])^(polygon[i+1]);
    doubleArea = abs(doubleArea);
    
    forn (i, n) {
        tint diferenciaX = abs(polygon[i].x - polygon[i+1].x);
        tint diferenciaY = abs(polygon[i].y - polygon[i+1].y);
        pointsAfuera += dcm(diferenciaX, diferenciaY);
    }
    
    cout << ((doubleArea+2-pointsAfuera)/2) << " " << pointsAfuera << "\n";
}