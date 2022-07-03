#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)
#define dbg(x) cerr << #x << " = " << x

using namespace std;
typedef int tint;

unordered_map<string, vector<pair<string,int>> g;
unordered_map<string, int> autoejes;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    forn (i,n) {
        string s;
        cin >> s;

        if (s.size() < 2) continue;
        string begString = string(1,s[0]) + string(1,s[1]);
        string endString = string(1,s[int(s.size() - 1)]) + string(1,s[int(s.size() - 2)]);

        int score = s.size() - 2;
        if (begString == endString) {
            autoejes[begString] = max(score, autoejes[begString]);
            continue;
        }

        g[begString].push_back({endString, score});
        g[endString].push_back({begString, score});
    }
}