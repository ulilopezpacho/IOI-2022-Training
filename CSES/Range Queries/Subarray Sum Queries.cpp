#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;
typedef long long tint;

struct Node {
    tint sum, pref, suf, maxSubarray;
    friend Node operator+ (const Node &o1, const Node &o2) {
        Node newNode;
        newNode.sum = o1.sum + o2.sum;
        newNode.pref = max(o1.pref, o1.sum+o2.pref);
        newNode.suf = max(o2.suf, o2.sum+o1.suf);
        newNode.maxSubarray = max(max(o1.maxSubarray, o2.maxSubarray), o1.suf + o2.pref);
        return newNode;
    }
};

struct SegmentTree {
    int segN;
    vector<Node> segTree;
    
    SegmentTree(int n) {
        segN = 1;
        while (segN < n) segN *= 2;
        segTree.resize(segN*2, {0,0,0,0});
    }

    void update (int pos, int val) {
        update(pos, {val,max(0,val),max(0,val),max(0,val)}, 1, 0, segN-1);
    }

    void update (int pos, Node val, int k, int l, int r) {
        if (l == r) { segTree[k] = val; return; }
        int m = (l + r) / 2;
        if (pos <= m) update(pos, val, k*2, l, m);
        else update(pos, val, k*2+1, m+1, r);
        segTree[k] = segTree[k*2] + segTree[k*2+1];
    }

    tint get(int a, int b) {
        return get(a, b, 1, 0, segN-1).maxSubarray;
    }

    Node get (int a, int b, int k, int l, int r) {
        if (b < l || a > r) return {0,0,0,0};
        if (a <= l && r <= b) return segTree[k];
        int m = (l+r)/2;
        Node q1 = get(a, b, k*2, l, m);
        Node q2 = get(a, b, k*2+1, m+1, r);
        return q1 + q2;
    }
};

ostream &operator << (ostream &os, Node node) {
    os << "(S: " << node.sum << ", SA: " << node.maxSubarray << ")";
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

    forn (i, n) {
        int temp;
        cin >> temp;
        tree.update(i, temp);
    }

    forn (i, q) {
        int pos, val;
        cin >> pos >> val;
        pos--;
        tree.update(pos, val);
        cout << tree.get(0, n-1) << "\n";
    }
}