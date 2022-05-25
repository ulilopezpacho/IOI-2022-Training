#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long tint;

const tint outside = 1e9+1;
int n, m;

struct Point {
    tint x, y;
    Point operator + (const Point &o) const {
        return {x+o.x, y+o.y};
    }
    Point operator - (const Point &o) const {
        return {x-o.x, y-o.y};
    }
    tint operator * (const Point &o) const {
        return x*o.x+y*o.y;
    }
    tint operator ^ (const Point &o) const {
        return x*o.y-y*o.x;
    }
    bool operator == (const Point &o) const {
        return x == o.x && y == o.y;
    }
};

struct Segment {
    Point p1, p2;
};

istream &operator>> (istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}

tint signo (const tint A) {
    if (A > 0) return 1;
    else if (A < 0) return -1;
    else return 0;
}

tint lado (const Point &A, const Point &B, const Point &C) {
    return signo((B-A)^(C-A));
}

bool sideCheck (const Point &p, vector<Point> &poly) {
    for (int i = 0; i < n; i++) {
        Segment s1 = {poly[i], poly[i+1]};
        if (lado(p, s1.p1, s1.p2) == 0 && (p-s1.p1)*(p-s1.p2) <= 0) return true;
    }
    return false;
}

bool outsideCheck (const Point &p, const vector<Point> &poly) {
    int counter = 0;
    tint yPoint = p.y;
    forn (i, n) {
        Segment s = {poly[i], poly[i+1]};
        if ((s.p1.y >= yPoint) != (s.p2.y >= yPoint)) {
            tint signo1 = signo((s.p1 - p) ^ (s.p2 - s.p1));
            tint signo2 = signo(Point({1,0}) ^ (s.p2 - s.p1));
            if (signo1 * signo2 > 0) counter++;
        }
    }
    return (counter) % 2 == 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<Point> polygon (n+1);
    vector<Point> points (m);

    forn (i, n) cin >> polygon[i];
    polygon[n] = polygon[0];
    forn (i, m) cin >> points[i];

    for (const Point &p: points) {
        if (sideCheck(p, polygon)) cout << "BOUNDARY\n";
        else if (outsideCheck(p, polygon)) cout << "OUTSIDE\n";
        else cout << "INSIDE\n";
    }
}