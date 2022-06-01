#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;
/*
struct ProductorConsumidor {
    int diaTolerado, precio;
    bool esConsumidor;

    bool operator()(const ProductorConsumidor &p1, const ProductorConsumidor &p2) {
        if (p1.diaTolerado < p2.diaTolerado) return true;
        else if (p1.diaTolerado == p2.diaTolerado && p1.esConsumidor && !p2.esConsumidor) return true;
        else return false;
    }
};*/

int main () {
    int n, m;
    cin >> m >> n;

    vector<ProductorConsumidor> pc (n+m);
    set<ProductorConsumidor> setConsumidores;
    
    forn (i,m) {
        cin >> pc[i].diaTolerado >> pc[i].precio;
        pc[i].esConsumidor = false;
    }

    forn (i,n) {
        cin >> pc[i].diaTolerado >> pc[i].precio;
        pc[i].esConsumidor = true;
        se
    }

}