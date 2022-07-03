#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long tint;

const tint outside = 1e9+1;

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

tint signo (const tint A) {
    if (A > 0) return 1;
    else if (A < 0) return -1;
    else return 0;
}

tint lado (const Point &A, const Point &B, const Point &C) {
    return signo((B-A)^(C-A));
}

bool sideCheck (const Point &p, const Segment &s1) {
    // Caso coinciden en un punto
    if (s1.p1 == p || s1.p2 == p) return true;

    // Caso está sobre el segmento
    if (lado(s1.p1, s1.p2, p) == 0 && (s1.p1-p)*(s1.p2-p) < 0) return true;
    return false;
}

bool alignCheck (const Segment &s1, const Segment &s2) {
    // Caso coinciden en punto

    // Caso alineados
    if (lado(s1.p1, s1.p2, s2.p1) == 0 && (s1.p1-s2.p1)*(s1.p2-s2.p1) < 0) return true;
    if (lado(s1.p1, s1.p2, s2.p2) == 0 && (s1.p1-s2.p2)*(s1.p2-s2.p2) < 0) return true;
    if (lado(s2.p1, s2.p2, s1.p1) == 0 && (s2.p1-s1.p1)*(s2.p2-s1.p1) < 0) return true;
    if (lado(s2.p1, s2.p2, s1.p2) == 0 && (s2.p1-s1.p2)*(s2.p2-s1.p2) < 0) return true;
    
    return false;
}

bool intersectionCheck (const Segment &s1, const Segment &s2) {
    // Caso que se cortan
    if ((lado(s1.p1, s1.p2, s2.p1) != lado(s1.p1, s1.p2, s2.p2)) && lado(s2.p1, s2.p2, s1.p1) != lado(s2.p1, s2.p2, s1.p2)) return true;

    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> polygon (n+1);
    vector<Point> points (m);

    forn (i, n) {
        tint x, y;
        cin >> x >> y;
        polygon[i] = {x,y};
    }

    polygon[n] = polygon[0];

    forn (i, m) {
        tint x, y;
        cin >> x >> y;
        points[i] = {x,y};
    }

    for (Point p: points) {
        tint count = 0;

        for (int i = 0; i < n; i++) {
            Segment s1 = {polygon[i], polygon[i+1]};
            if (sideCheck(p, s1)) {
                count = -1;
                break;
            }
            Segment s2 = {p, {outside, outside}};
            if (alignCheck(s1, s2)) {
                i++;
                count++;
            }
            if (intersectionCheck(s1, s2)) {
                count++;
            }
        }

        if (count == -1) cout << "BOUNDARY\n";
        else if (count % 2 == 0) cout << "OUTSIDE\n";
        else cout << "INSIDE\n";
    }
}