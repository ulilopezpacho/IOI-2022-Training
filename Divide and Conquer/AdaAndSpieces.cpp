#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int rows = 4;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0; cin >> n;
    vector<vector<int>> nums (n, vector<int> (rows));
    forn (i,n) forn (j, rows) cin >> nums[i][j];

    forn (j, min(rows, n-1)) {
        sort(nums.rbegin(), nums.rend());
        int bestValue = nums[0][j];
        if (bestValue == -1) continue;

        forn (i, n) {
            if (nums[i][j] != bestValue) break;
            forn (k, rows) {
                cout << nums[i][k] << " ";
                nums[i][k] = -1;
            }
            cout << endl;
            ans++; 
        }

        forn (i, n) {
            nums[i][j] = -1;
        }
    }

    cout << ans;
}