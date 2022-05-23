#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long int tint;

struct Point {
    tint x, y;
    Point operator +(const Point &o) const {
        return {x + o.x, y + o.y};
    }
    Point operator -(const Point &o) const {
        return {x - o.x, y - o.y};
    }
    tint operator *(const Point &o) const {
        return x*o.x + y*o.y;
    }
    tint operator ^(const Point &o) const {
        return x*o.y - y*o.x;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    tint n, total = 0;

    cin >> n;
    vector<Point> points (n);

    forn(i,n) {
        tint x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    points.push_back(points[0]);

    for (int i = 0; i < n; i++) {
        total += (points[i])^(points[i+1]);
    }

    cout << abs(total);
}