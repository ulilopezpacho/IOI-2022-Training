#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
    
int sheets, rounds, maxNum, num;
vector<int> seccionesCubiertas, seccionesCubiertasRev;

void answer (int pos, int number) {
    seccionesCubiertas[pos] = number;
    seccionesCubiertasRev[sheets-(1+pos)] = number;
    cout << pos+1 << endl;
}

int main () {
    cin >> sheets >> rounds >> maxNum;

    seccionesCubiertas.resize(sheets);
    seccionesCubiertasRev.resize(sheets);

    while (cin >> num) {
        forn (i,sheets) {
            int leftPos = i, rightPos = sheets-(i+1);

            if (num <= maxNum/2 && seccionesCubiertas[i] == 0 || num < seccionesCubiertas[i]) {
                answer(leftPos, num);
                break;
            }
            if (num > maxNum/2 && seccionesCubiertasRev[i] == 0 || num > seccionesCubiertasRev[i]) {
                answer(rightPos, num);
                break;
            }
        }
    }
}