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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> nums (n);
    vector<pair<int,int>> qs; 

    forn (i, n) cin >> nums[i];
    
    forn (i, q) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        qs.push_back({b, a});
    }

    sort(qs.begin(), qs.end());

}