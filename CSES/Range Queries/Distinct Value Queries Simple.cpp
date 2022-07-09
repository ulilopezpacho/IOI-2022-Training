#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

struct SegmentTree {
    int segN;
    vector<set<int>> segTree;

    SegmentTree(int n) {
        segN = 1;
        while (segN < n) segN *= 2;
        segTree.resize(segN * 2);
    }

    void update (int pos, int val, int k, int l, int r) {
        if (l == r) { segTree[k].insert(val); return; }
        int m = (l + r) / 2;
        if (m <= pos) update(pos, val, k*2, l, m);
        else update(pos, val, k*2+1, m+1, r);
        segTree[k].insert(val);
    }

    int get (int a, int b) {
        set<int> ans;
        a += segN; b += segN;
        while (a <= b) {
            if (a % 2 == 1) {
                for (auto &e: segTree[a]) ans.insert(e);
                DBG(a);
                a++;
            }
            if (b % 2 == 0) {
                for (auto &e: segTree[b]) ans.insert(e);
                DBG(b);
                b--;
            }
            a /= 2; b /= 2;
        }
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
        segTree.update(i, temp, 1, 0, segTree.segN - 1);
    }
    
    forn (i, q) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << segTree.get(a, b) << "\n";
    }    
}