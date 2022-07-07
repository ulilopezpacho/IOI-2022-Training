#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

const int MAXINT = 2e9;

struct MinSegmentTree {

    int segN; int op;
    vector<int> segTree;

    MinSegmentTree(int n, int specialOp) {
        segN = 1; op = specialOp;
        while (segN < n) segN *= 2;
        segTree.resize(segN*2, MAXINT);
    }

    void update (int pos, int val) {
        update(pos, val, 1, 0, segN-1);
    }

    void update (int i, int val, int k, int l, int r) {
        if (l == r) { segTree[k] = val + op*l; return; }
        int m = (l+r)/2;
        if (i <= m) update(i, val, 2*k, l, m);
        else update(i, val, 2*k+1, m+1, r);
        segTree[k] = min(segTree[2*k], segTree[2*k+1]);
    }

    int get (int a, int b) {
        return get(a, b, 1, 0, segN - 1);
    }

    int get (int a, int b, int k, int l, int r) {
        if (b < l || a > r) return MAXINT;
        if (a <= l && r <= b) return segTree[k];
        int m = (l+r)/2;
        int q1 = get(a, b, 2*k, l, m);
        int q2 = get(a, b, 2*k+1, m+1, r);
        return min(q1, q2);
    }

};

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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    MinSegmentTree leftTree(n, -1);
    MinSegmentTree rightTree(n, 1);

    forn (i,n) {
        int temp;
        cin >> temp;
        leftTree.update(i, temp);
        rightTree.update(i, temp);
    }

    forn (i,q) {
        int op; cin >> op;
        if (op == 2) {
            int k;
            cin >> k; k--;
            cout << min(leftTree.get(0,k)+k, rightTree.get(k,n-1)-k) << "\n";
        } else {
            int k, x;
            cin >> k >> x; k--;
            leftTree.update(k, x);
            rightTree.update(k, x);
        }
    }
}