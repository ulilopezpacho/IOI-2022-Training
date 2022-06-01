#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, result = 0;
    string find, row;
    vector<int> cantChars (255, 0), cantBase (255, 0);
    cin >> n >> m >> find >> row;

    for (int i = 0; i < n; i++) cantBase[int(find[i])]++;
    for (int i = 0; i < (n-1); i++) cantChars[int(row[i])]++;

    for (int i = n-1; i < m; i++) {
        cantChars[int(row[i])]++;
        bool esCorrecto = true;
        for (int j = 0; j < 255; j++) {
            if (cantChars[j] == cantBase[j]) continue;
            esCorrecto = false;
            break;
        }
        if (esCorrecto) result++;
        cantChars[int(row[i-n+1])]--;
    }

    cout << result;
}