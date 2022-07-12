#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
    
int sheets, rounds, maxNum, num;
vector<int> seccionesCubiertas, seccionesCubiertasRev;

void answer (int pos, int num) {
    seccionesCubiertas[pos] = num;
    seccionesCubiertasRev[sheets-(1+pos)] = num;
    cout << pos+1 << endl;
}

int main () {
    cin >> sheets >> rounds >> maxNum;

    seccionesCubiertas.resize(sheets);
    seccionesCubiertasRev.resize(sheets);

    while (cin >> num) {
        forn (i,sheets) {
            if (seccionesCubiertas[i] == 0 || num < seccionesCubiertas[i]) {
                answer(i, num);
                break;
            }
            if (seccionesCubiertasRev[i] == 0 || num > seccionesCubiertas[i]) {
                answer(sheets-(i+1), num);
                break;
            }
        }
    }
}