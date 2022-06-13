#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

vector<vector<int>> g;
vector<bool> visited;

void solve (const int &n) {
    int node = -1, x;

    g.clear();
    visited.clear();
    g.resize(n+1);
    visited.resize(n+1);

    cin >> node;
    while (node != 0) {
        string linea;
        getline(cin, linea);
        istringstream inpu(linea);
        while (cin >> x) {
            g[node].push_back(x);
            g[x].push_back(x);
        }
        cin >> node;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n != 0) solve(n);
}