#include <bits/stdc++.h>

using namespace std;

template<class T>
struct SegmentTree {
    int segN, N;
    vector<T> segTree;

    SegmentTree (int n) {
        n = N; segN = 1;
        while (segN < n) segN *= 2;
        segTree.resize(segN*2);
    }

    SegmentTree (SegmentTree )
    
    void update (int pos, int val) {
        update(pos, val, 1, 0, segN-1);
    }

    void update (int pos, int val, int k, int l, int r) {
        if (l == r) { segTree[k] = val; return; }
        int m = (l + r) / 2;
        if (pos <= m) update(pos, val, k*2, l, m);
        else update(pos, val, k*2+1, m+1, r);
        segTree[k] = segTree[k*2] + segTree[k*2+1];
    }

    T retrieve (int a, int b) {
        return retrieve(a, b, 1, 0, segN-1);
    }

    T retrieve (int a, int b, int k, int l, int r) {
        if (a > r || b < l) return 0;
        else if (a <= l && r <= b) return segTree[k];
        int m = (l + r) / 2;
        int q1 = retrieve(a, b, k*2, l, m);
        int q2 = retrieve(a, b, k*2+1, m+1, r);
        return q1 + q2;
    }

    friend SegmentTree operator+ (SegmentTree &o1, SegmentTree &o2){
        SegmentTree ret (N);
        re
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    SegmentTree<SegmentTree<int>> tree (n, SegmentTree<int> (m));    
}