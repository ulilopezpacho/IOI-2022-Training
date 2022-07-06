#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long tint;

struct Node {
    tint sum, pref;

    friend Node operator+ (const Node &o1, const Node &o2) {
        Node newNode;
        newNode.sum = o1.sum + o2.sum;
        newNode.pref = max(o1.pref, o1.sum + o2.pref);
        return newNode;
    }
};

struct SegmentTree {

    vector<Node> segTree;
    int segN;

    SegmentTree (int n) {
        segN = 1;
        while (segN < n) segN *= 2;
        segTree.resize(segN*2);
    }

    void update (int pos, tint val) {
        pos += segN; segTree[pos] = {val, val};
        for (pos /= 2; pos >= 1; pos /= 2) {
            segTree[pos] = segTree[pos*2] + segTree[pos*2+1];
        }
    }

    tint get (int a, int b) {
        Node nd = {0,0};
        return (nd + query(a,b,1,0,segN-1)).pref;
    }

    Node query (int a, int b, int k, int l, int r) {
        if (r < a || b < l) return {0,0};
        if (a <= l && r <= b) return segTree[k];
        int m = (l+r) / 2;
        Node q1 = query(a, b, k*2, l, m);
        Node q2 = query(a, b, k*2+1, m+1, r);
        return q1 + q2;
    }

};

ostream &operator << (ostream &os, Node node) {
    os << "(S: " << node.sum << ", P: " << node.pref << ")";
    return os;
}

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

    int n, q; cin >> n >> q;
    SegmentTree tree (n);

    forn(i,n) {
        tint temp; cin >> temp;
        tree.update(i,temp);
    }

    forn(i,q) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            a--; tree.update(a, tint(b));
        } else {
            a--; b--;
            cout << tree.get(a, b) << "\n";
        }
    }
}