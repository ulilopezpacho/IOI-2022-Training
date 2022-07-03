#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long tint;

int n;

struct Point {
    tint x, y;
    Point operator+ (const Point &o) const {
        return {x+o.x, y+o.y};
    }
    Point operator- (const Point &o) const {
        return {x-o.x, y-o.y};
    }
    tint operator* (const Point &o) const {
        return x*o.x + y*o.y;
    }
    tint operator^ (const Point &o) const {
        return x*o.y - y*o.x;
    }
};

istream &operator>> (istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}

ostream &operator<< (ostream &os, Point &p) {
    os << p.x << " "<< p.y;
    return os;
}

tint signo (tint A) {
    if (A > 0) return 1;
    else if (A < 0) return -1;
    else return 0;
}

tint lado (const Point &A, const Point &B, const Point &C) {
    return signo((B-A)^(C-A));
}

bool sorterLeftToRight (const Point &a, const Point &b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x && a.y < b.y) return true;
    else return false;
}

bool sorterRightToLeft (const Point &a, const Point &b) {
    if (a.x > b.x) return true;
    else if (a.x == b.x && a.y > b.y) return true;
    else return false;
}

void createChull (vector<Point> &chull, vector<Point> &poly) {
    chull = {poly[0], poly[1]};
    for (int i = 2; i < n; i++) {
        Point current = poly[i];
        while (chull.size() > 1) {
            Point B = chull[chull.size()-1], A = chull[chull.size()-2];
            if (lado(A,B,current) > 0) chull.pop_back();
            else break;
        }
        chull.push_back(current);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<Point> poly (n), upperChull, lowerChull;
    forn(i,n) cin >> poly[i];
    
    sort(poly.begin(), poly.end(), sorterLeftToRight);
    createChull(upperChull, poly);

    sort(poly.begin(), poly.end(), sorterRightToLeft);
    createChull(lowerChull, poly);

    int resultSize = int(upperChull.size()) + int(lowerChull.size()) - 2;
    cout << resultSize << "\n";
    forn (i, upperChull.size() - 1) cout << upperChull[i] << "\n";
    forn (i, lowerChull.size() - 1) cout << lowerChull[i] << "\n";
}