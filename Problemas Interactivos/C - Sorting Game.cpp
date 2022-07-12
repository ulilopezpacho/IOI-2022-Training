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
            bool canLeft, canRight;
            int leftPos = i, rightPos = sheets-(i+1);
            if (seccionesCubiertas[i] == 0 || num < seccionesCubiertas[i]) canLeft = true;
            if (seccionesCubiertasRev[i] == 0 || num > seccionesCubiertasRev[i]) canRight = true;

            if (canLeft && canRight) {
                if (abs(maxNum - num) < num) answer(rightPos, num);
                else answer(leftPos, num);
            } else if (canLeft) {
                answer(leftPos, num);
            } else if (canRight) {
                answer(rightPos, num);
            }

            if (canLeft || canRight) break;
        }
    }
}