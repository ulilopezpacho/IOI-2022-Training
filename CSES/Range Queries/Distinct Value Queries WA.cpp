#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

struct SegmentTree {
    int segN;
    vector<map<int,int>> segTree;

    void operation (map<int,int> &map, int val, bool ins) {
        if (ins) map[val]++;
        else if (--map[val] == 0) map.erase(val);
    } 

    SegmentTree(int n) {
        segN = 1;
        while (segN < n) segN *= 2;
        segTree.resize(segN * 2);
    }

    void insert (int pos, int val) {
        update(pos, val, true, 1, 0, segN-1);
    }

    void remove (int pos, int val) {
        update(pos, val, false, 1, 0, segN-1);
    }

    void update (int pos, int val, bool ins, int k, int l, int r) {
        if (l == r) { operation(segTree[k], val, ins); return; }
        int m = (l + r) / 2;
        if (m <= pos) update(pos, val, ins, k*2, l, m);
        else update(pos, val, ins, k*2+1, m+1, r);
        operation(segTree[k], val, ins);
    }

    int get (int a, int b) {
        set<int> res;
        a += segN; b += segN;
        while (a <= b) {
            if (a % 2 == 1) {
                for (auto &e: segTree[a]) res.insert(e.first);
                a++;
            }
            if (b % 2 == 0) {
                for (auto &e: segTree[b]) res.insert(e.first);
                b--;
            }
            a /= 2; b /= 2;
        }
        return res.size();
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    forn (i, n) 
    
}