#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int rows = 4;
typedef bitset<200000> bbitset;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<pair<int,int>>> nums (rows, vector<pair<int,int>> (n));
    vector<bbitset> bitsets (rows);

    forn (i,n) {
        forn (j, rows) {
            cin >> nums[j][i].first;
            nums[j][i].second = i;
        }
    }

    forn (i, rows) {
        sort(nums[i].begin(), nums[i].end());
        int winner = nums[i][n-1].first;
        for (auto &e: nums[i]) {
            if (e.first == winner) bitsets[i][e.second] = 1;
        }
    }

    bbitset result = bitsets[0];
    forn (i, rows) result &= bitsets[i];
    cout << result.count() << endl;
}