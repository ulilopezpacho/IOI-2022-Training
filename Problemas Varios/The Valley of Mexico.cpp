#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

vector<bitset<1001>> g;

int DP (const int &i, const int &j, const bool &esDerecha) {
    if (i == j) return true;
    if (g[j][j-1] == 1) DP(i, j-1, true);
    if (g[j])
}

int main () {
    int c, n;
    cin >> c, n;
    
    g.resize(c+1);

    forn (i, n) {
        int from, to;
        cin >> from >> to;
        g[from][to] = 1;
        g[to][from] = 1;
    }
}