#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T> v) {
    os << "[";
    forn (i, v.size()) {
        if (i != 0) os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

struct SegmentTree {
    int segN;
    vector<vector<int>> segTree;

    SegmentTree(int n) {
        segN = 1;
        while (segN < n) segN *= 2;
        segTree.resize(segN * 2);
    }

    void update (int pos, int val) {
        update(pos, val, 1, 0, segN-1);
    }

    void update (int pos, int val, int k, int l, int r) {
        if (l == r) { segTree[k].push_back(val); return; }
        int m = (l + r) / 2;
        if (pos <= m) update(pos, val, k*2, l, m);
        else update(pos, val, k*2+1, m+1, r);
        segTree[k].push_back(val);
    }

    int get (int a, int b) {
        vector<int> ans;
        a += segN; b += segN;
        while (a <= b) {
            if (a % 2 == 1) {
                for (auto &e: segTree[a]) ans.push_back(e);
                a++;
            }
            if (b % 2 == 0) {
                for (auto &e: segTree[b]) ans.push_back(e);
                b--;
            }
            a /= 2; b /= 2;
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return int(ans.size());
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    SegmentTree segTree (n);

    forn (i, n) {
        int temp;
        cin >> temp;
        segTree.update(i, temp);
    }
    
    forn (i, q) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << segTree.get(a, b) << "\n";
    }    
}