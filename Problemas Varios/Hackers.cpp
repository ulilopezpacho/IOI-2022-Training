#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

vector<vector<pair<int,int>>> g;
vector<tuple<int,int,int>> aristas;

vector<int> link;
vector<int> sizes;
vector<pair<int,int>> hackers;

int find (int x) {
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}

bool same (int a, int b) {
    return find(a) == find(b);
}

void unite (int a, int b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    link[b] = a;
}

int minDfs (int actual, int parent, int find) {

    if (actual == find) return 0;
    for (pair<int,int> &a: g[actual]) {
        if (a.first == parent) continue;
        int res = minDfs(a.first, actual, find);
        if (res != -1) return max(res, a.second);
    }
    return -1;
}

void solve (int C, int L, int H) {
    
    g.clear();
    aristas.clear();
    link.clear();
    sizes.clear();
    hackers.clear();

    g.resize(C+1);
    hackers.resize(H);

    forn (i, L) {
        int from, to, cost;
        cin >> from >> to >> cost;
        aristas.push_back({cost, from, to});
    }

    forn (i, H) cin >> hackers[i].first >> hackers[i].second;
    sort(aristas.begin(), aristas.end());

    link.resize(C+1);
    forn(i, C+1) link[i] = i;
    sizes.resize(C+1, 1);

    for (tuple<int,int,int> &arista : aristas) {
        int cost, from, to;
        tie(cost, from, to) = arista;
        if (!same(from, to)) {
            unite(from, to);
            g[from].push_back({to, cost});
            g[to].push_back({from, cost});
        }
    }

    for (pair<int,int> &hacker : hackers) {
        cout << minDfs(hacker.first, -1, hacker.second) << " ";
    }
    cout << "\n";
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, L, H;

    while (true) {
        cin >> C >> L >> H;
        if (C == -1 && L == -1 && H == -1) break;
        solve(C,L,H);
    }
}