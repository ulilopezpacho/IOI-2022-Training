#include <bits/stdc++.h>

#define DBG(x) cerr << #x << " = " << (x) << endl 
#define DBG2(x,y) cerr << #x << " = " << (x) << " , " << #y << " = " << (y) << endl 
#define SIZE(c) int((c).size())

template <typename T>
ostream & operator <<(ostream &os, const vector<T>& v) {
    os << "[";
    forn(i,SIZE(v))
    {
        if (i > 0) os << " ";
        os << v[i];
    }
    return os << "]";
}