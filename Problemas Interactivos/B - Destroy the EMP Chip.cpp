#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

typedef long long tint;

const tint MINP = -2*1e18;
const tint MAXP = 2*1e18;

string guessPoint (tint x, tint y) {
    cout << 1 << " " << x << " " << y << endl;
    string str;
    cin >> str;
    return str;
}

string guessRectangle (tint x1, tint y1, tint x2, tint y2) {
    cout << 2 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    string str;
    cin >> str;
    return str;
}

void adjust (char &res, tint &minCoord, tint &medCoord, tint &maxCoord) {
    if (res == 'P' || res == 'X' || res == 'Y') maxCoord = medCoord;
    else if (res == 'N' || res == 'X' || res == 'Y') minCoord = medCoord;
}

void solve (tint D) {
    tint xMin = MINP, yMin = MINP, xMax = MAXP, yMax = MAXP;
    const tint compConst = 3*D;
    string res = "";
    while (abs(xMin-xMax) > compConst && abs(yMin-yMax) > compConst) {
        tint xMed = (xMin + xMax) / 2;
        tint yMed = (yMin + yMax) / 2;
        res = guessPoint(xMed, yMed);
        if (res == "O") return;
        adjust(res[0], xMin, xMed, xMax);
        adjust(res[1], yMin, yMed, yMax);
        xMin -= D; yMin -= D; xMax += D; yMax += D;
    }
    while (res != "O") {
        res = guessRectangle(xMin, yMin, xMax, yMax);
    }
}

int main () {
    tint T, Q, D;
    cin >> T >> Q >> D;
    forn (i, T) solve(D);
}