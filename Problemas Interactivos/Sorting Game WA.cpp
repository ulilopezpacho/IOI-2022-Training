#include <bits/stdc++.h>

using namespace std;
    
vector<int> seccionesCubiertas;
vector<int> sectionStart;

void answer (int pos, int num) {
    seccionesCubiertas[pos] = num;
    cout << pos+1 << endl;
}

int main () {
    int sheets, rounds, maxNum;
    cin >> sheets >> rounds >> maxNum;

    sectionStart.resize(maxNum+1);
    seccionesCubiertas.resize(sheets);

    sectionStart[1] = 0;
    sectionStart[maxNum] = sheets-1;
    int sectionJump = sheets / maxNum;

    for (int i = 2; i < maxNum; i++) {
        sectionStart[i] = (i-1) * sectionJump;
    }

    int num;
    while (cin >> num) {
        int posStart = sectionStart[num];
        int a = posStart; int b = posStart;

        while (a >= 0 && seccionesCubiertas[a] == num) a--;
        while (b < sheets && seccionesCubiertas[b] == num) b++;
        
        if (a == -1 && b == sheets) answer(0,num);
        else if (a == -1) answer(b, num);
        else if (b == sheets) answer(a, num);
        else if (abs(posStart-a) > abs(posStart-b)) answer(b, num);
        else if (abs(posStart-a) < abs(posStart-b)) answer(a, num);
        else answer(b, num);
    }
}