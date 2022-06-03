#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

vector<vector<pair<int,int>>> g;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.resize(n);

    forn (i, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[from].push_back({to, cost});
        g[to].push_back({from, cost});
    }
}