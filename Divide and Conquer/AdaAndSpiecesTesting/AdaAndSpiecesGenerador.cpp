#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

const int n = 10;
const int rows = 4;

int main () {
    srand(time(0));
    vector<set<int>> salieron (rows);
    cout << n << "\n";

    forn (i,n) {
        forn (j,rows) {
            while (true) {
                int numero = (rand() % n) + 1;
                if (salieron[j].count(numero) > 0) continue;
                cout << numero << " ";
                salieron[j].insert(numero);
                break;
            }
        }
        cout << "\n";
    }
}