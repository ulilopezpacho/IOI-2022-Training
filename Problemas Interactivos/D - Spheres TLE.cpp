#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

string weight (vector<int> left, vector<int> right) {
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
    
    bool foundDifferent = false;
    tuple<int,int,string> differentWeights;
    
    for (int i = 1; i < n && !foundDifferent; i += 2) {
        string res = weight(i, i+1);
        if (res != "EQUAL") {
            differentWeights = {i,i+1,res};
            foundDifferent = true;
        }
    }

    if (n % 2 == 1 && !foundDifferent) differentWeights = {1, n, weight(1, n)};
    int dif1, dif2; string status;
    tie(dif1, dif2, status) = differentWeights;

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
        break;
    }
}