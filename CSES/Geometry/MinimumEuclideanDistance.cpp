#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

#define x first
#define y second

using namespace std;
typedef long long tint;
typedef pair<tint,tint> Point;

const tint minim = -2e9;

tint distanciaCuadrado(const Point &p1, const Point &p2) {
    tint xa = p1.x-p2.x, ya = p1.y-p2.y;
    return xa*xa+ya*ya;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Point> points (n);
    forn (i,n) cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end());
    tint d = distanciaCuadrado(points[0], points[1]);
    set<Point> sx, sy;

    sy.insert({points[0].y, points[0].x});
    sy.insert({points[1].y, points[1].x});
    sx.insert({points[0].x, points[0].y});
    sx.insert({points[1].x, points[1].y});

    for (int i = 2; i < n; i++) {
        Point actual = points[i];
        tint minimoX = actual.x- tint(sqrt(d)+1);

        auto deleteUpTo = sx.lower_bound({minimoX, minim});
        for (auto it = sx.begin(); it != deleteUpTo; it++) {
            Point toDelete = {it->second, it->first};
            sy.erase(toDelete);
        }
        sx.erase(sx.begin(), deleteUpTo);

        tint minimoY = actual.y - tint(sqrt(d) + 1);
        tint maximoY = actual.y + tint(sqrt(d) + 1);
        auto beginIteratingYs = sy.lower_bound({minimoY, minim});
        auto endIteratingYs = sy.upper_bound({maximoY, minim});

        for (; beginIteratingYs != endIteratingYs; beginIteratingYs++) {
            Point it = {beginIteratingYs->second, beginIteratingYs->first};
            d = min(d, distanciaCuadrado(actual, it)); 
        }

        sx.insert({actual.x, actual.y});
        sy.insert({actual.y, actual.x});
    }

    cout << d << "\n";
}