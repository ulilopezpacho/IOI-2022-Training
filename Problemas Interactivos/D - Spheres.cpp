#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

string weight (vector<int> &left, vector<int> &right) {
    cout << "WEIGHT " << left.size() << " ";
    for (auto a: left) cout << a << " ";
    for (auto a: right) cout << a << " ";
    cout << endl;
    string ans;
    cin >> ans;
    return ans;
}

string weight (int left, int right) {
    cout << "WEIGHT 1 " << left << " " << right << endl;
    string ans;
    cin >> ans;
    return ans;
}

void answer (int ans) {
    cout << "ANSWER " << ans << endl;
}

int main () {
    int n; cin >> n;
    int a = 1; int b = n;
    while (b-a > 1) {
        int m = (a+b)/2;
        if (((m - a + 1) % 2) == 1) m--;
        vector<int> left, right;

        const int upTo = (a + m) / 2;
        for (int i = a; i <= upTo; i++) left.push_back(i);
        for (int i = upTo + 1; i <= m; i++) right.push_back(i);

        string res = weight(left, right);
        if (res == "EQUAL") a = m+1;
        else b = m;
    }

    if (a == b) {
        int diff = 1;
        if (diff == a) b++;
        string res = weight(a, diff);
        if (res == "LEFT") answer(a);
        else answer(-a);
        return 0;
    }

    int dif1 = a, dif2 = b;

    for(int eq = 1; eq <= n; eq++) {
        if (eq == dif1 || eq == dif2) continue;
        string val1 = weight(dif1, eq);
        string val2 = weight(dif2, eq);

        if (val1 != "EQUAL") {
            swap(dif1, dif2);
            swap(val1, val2);
        }

        if (val2 == "LEFT") answer(dif2);
        else if (val2 == "RIGHT") answer(-dif2);
        return 0;
    }
}