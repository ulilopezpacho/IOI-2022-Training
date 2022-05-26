#include <bits/stdc++.h>

using namespace std;
typedef long long tint;

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

tint signo (tint A) {
    if (A > 0) return 1;
    else if (A < 0) return -1;
    else return 0;
}

tint lado (const Point &A, const Point &B, const Point &C) {
    return signo((B-A)^(C-A));
}



int main () {

}