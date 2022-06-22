#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int rows = 4;

#define DBG(x) cerr << #x << " = " << (x) << endl 
#define DBG2(x,y) cerr << #x << " = " << (x) << " , " << #y << " = " << (y) << endl 
#define SIZE(c) int((c).size())

template <typename T>
ostream & operator <<(ostream &os, const vector<T>& v) {
    os << "[";
    forn(i,SIZE(v))
    {
        if (i > 0) os << " ";
        os << v[i];
    }
    return os << "]";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> nums (n, vector<int> (rows));
    vector<bool> tachados(n, false);

    forn (i,n) forn (j, rows) cin >> nums[i][j];
    
    forn (i,n) {
        forn (j,n) {
            if (i== j) continue;
            bool esPisado = true;
            forn (r, rows) {
                if (nums[i][r] > nums[j][r]) esPisado = false;
            }
            tachados[j] = tachados[j] | esPisado;
        }
    }

    int ans = 0;
    for (auto e: tachados) {
        if (!e) ans++;
    }

    cout << ans << "\n";
}