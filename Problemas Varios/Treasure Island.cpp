#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid (R, vector<int> (C));
    forn (i,R) forn (j,C) cin >> grid[i][j];

    for (int i = R-1; i >= 0; i--) {
        for (int j = C-1; j >= 0; j--) {
            if (i < (R-1)) grid[i][j] = min(grid[i][j], grid[i+1][j]-1);
            if (j < (C-1)) grid[i][j] = min(grid[i][j], grid[i][j+1]-1);
        }
    }
    
    if (grid[0][0] <= 0) cout << -1;
    else cout << grid[0][0] - 1;
}