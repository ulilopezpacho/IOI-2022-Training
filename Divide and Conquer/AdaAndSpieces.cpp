#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int rows = 4;

struct SegmentTree {

    int n, segN = 1;
    vector<int> pastInserts;
    vector<int> segTree;

    SegmentTree(int n_) {
        n = n_;
        while (segN < n) segN *= 2;
        segTree.resize(segN*2, 0);
    }

    void update (int pos, int value, bool saveHistory = true) {
        if (saveHistory) pastInserts.push_back(pos);
        pos += segN; segTree[pos] = value;
        for (pos /= 2; pos >= 1; pos /= 2) {
            segTree[pos] = segTree[2*pos] + segTree[2*pos+1];
        }
    }

    int get (int a) {
        int maximo = 0;
        int b = n + segN;
        a += segN;
        while (a <= b) {
            if (a % 2 == 1) maximo = max(maximo, segTree[a++]);
            if (b % 2 == 0) maximo = max(maximo, segTree[b--]);
            a /= 2; b /= 2;
        }
        return maximo;
    }

    void fastClear () {
        for (auto &element: pastInserts) update(element, 0, false);
        pastInserts.clear();
    }

};

SegmentTree segTree (0);

void divideAndConquer(int from, int to, vector<vector<int>> &nums, vector<bool> &tachados) {
    
    if (to-from == 1) return;
    int mid = (to+from) / 2;

    // Tacho los de la izquierda
    divideAndConquer(from, mid, nums, tachados);
    // Tacho los de la derecha
    divideAndConquer(mid, to, nums, tachados);
    
    // Tacho los cruzados
    // Los agrego a un array y los ordeno
    vector<tuple<int, bool, int, int, int>> secondSort;
    for (int i = from; i < mid; i++)
        if (!tachados[i]) secondSort.push_back({nums[i][1], false, nums[i][2], nums[i][3], i});
    for (int i = mid; i < to; i++)
        if (!tachados[i])
            secondSort.push_back({nums[i][1], true, nums[i][2], nums[i][3], i});
    
    sort(secondSort.rbegin(), secondSort.rend());

    // Los evalúo uno por uno
    for (auto &element: secondSort) {
        bool isRight; int b, c, d, i;
        tie(b, isRight, c, d, i) = element;

        // Si es de la izquierda, no puede ser dominado. Debo insertarlo al segment tree de los posibles candidatos a dominar por c y por d.
        if (!isRight) segTree.update(c, d);
        else {
            // Si está a la derecha, puede ser que sea dominado por uno de la izquierda. Busco el mejor candidato a que domine con el segment tree;
            int maximoD = segTree.get(c+1);
            if (maximoD > d) {
                tachados[i] = true;
            }
        }
    }

    segTree.fastClear();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> nums (n, vector<int> (rows));
    vector<bool> tachados(n);
    segTree = SegmentTree(n+2);

    forn (i,n) forn (j, rows) cin >> nums[i][j];

    sort(nums.rbegin(), nums.rend());
    divideAndConquer(0, n, nums, tachados);

    int ans = 0;
    for (auto e: tachados) {
        if (!e) ans++;
    }

    cout << ans << "\n";
}