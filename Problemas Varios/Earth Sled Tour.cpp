#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

vector<vector<pair<int,int>>> g;
vector<tuple<int,int,int>> aristas;

vector<int> sizes;
vector<int> representatives;

int find (int x) {
    if (representatives[x] == x) return x;
    return representatives[x] = find(representatives[x]);
}

bool same (int a, int b) {
    return find(a) == find(b);
}

void unite (int a, int b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    representatives[b] = a;
}

int maxDfs (int actual, int anterior, int &buscando) {

    if (actual == buscando) return 0;

    for (pair<int,int> e: g[actual]) {
        if (e.first == anterior) continue;
        int res = maxDfs(e.first, actual, buscando);
        if (res != -1) return max(e.second, res); 
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m;
    g.resize(n);

    forn (i, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        aristas.push_back({cost, from, to});
    }

    cin >> q;
    vector<pair<int,int>> queries(q);
    forn(i, q) cin >> queries[i].first >> queries[i].second;

    sort(aristas.begin(), aristas.end());
    sizes.resize(n,1);
    representatives.resize(n);
    forn (i,n) representatives[i] = i;

    for (tuple<int,int,int> &arista: aristas) {
        int cost, from, to;
        tie(cost, from, to) = arista;
        if (!same(from, to)) {
            unite(from,to);
            g[from].push_back({to, cost});
            g[to].push_back({from, cost});
        }
    }

    for (pair<int,int> &query: queries) {
        cout << maxDfs(query.first, -1, query.second) << "\n";
    }
}