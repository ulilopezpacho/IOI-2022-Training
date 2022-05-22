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
    bool operator ==(const Point &o) const {
        return x==o.x && y==o.y;
    }
};

struct Segment {
    Point p1, p2;
};

tint signo (tint A) {
    if (A < 0) return -1;
    else if (A > 0) return 1;
    else return 0;
}

tint lado (const Point A, const Point B, const Point C) {
    return signo((A-B)^(A-C));
}

bool checkIntersection (Segment s1, Segment s2) {

    // Caso en que coinciden en un solo vértice
    if (s1.p1 == s2.p1) return true;
    if (s1.p2 == s2.p1) return true;
    if (s1.p1 == s2.p2) return true;
    if (s1.p2 == s2.p2) return true;
    
    // Caso que están alineados
    if (lado(s1.p1, s1.p2, s2.p1) == 0 && (s2.p1-s1.p1)*(s2.p1-s1.p2) < 0) return true;
    if (lado(s1.p1, s1.p2, s2.p2) == 0 && (s2.p2-s1.p1)*(s2.p2-s1.p2) < 0) return true;
    if (lado(s2.p1, s2.p2, s1.p1) == 0 && (s1.p1-s2.p1)*(s1.p1-s2.p2) < 0) return true;
    if (lado(s2.p1, s2.p2, s1.p2) == 0 && (s1.p2-s2.p1)*(s1.p2-s2.p2) < 0) return true;

    // Caso que no están alineados
    if (lado(s1.p1, s1.p2, s2.p1) != lado(s1.p1, s1.p2, s2.p2) && lado(s2.p1, s2.p2, s1.p1) != lado(s2.p1, s2.p2, s1.p2)) return true;

    // No se cortan sino se cumplen ambos casos
    return false;
}

void solve () {
    tint x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Segment s1 = {{x1, y1}, {x2, y2}};
    Segment s2 = {{x3, y3}, {x4, y4}};

    if (checkIntersection(s1, s2)) cout << "YES\n";
    else cout << "NO\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    tint T;
    cin >> T;
    forn (i, T) solve();
}