#include <bits/stdc++.h>

using namespace std;
typedef long long tint;

struct Punto {
    tint x, y;
    Punto operator +(const Punto &o) const {
        return {x + o.x, y + o.y};
    }
    Punto operator -(const Punto &o) const {
        return {x + o.x, y + o.y};
    }
    tint operator *(const Punto &o) const {
        return x * o.x + y * o.y;
    }
    tint operator ^(const Punto &o) const {
        return x * o.y - y * o.x;
    }
    tint normaCuadrado () const {
        return x*x + y*y
    }
    bool operator == (const Punto &o) const {
        return x==o.x && y==o.y;
    }
};

Punto puntoMedio(Punto a,Punto b)
{
    return (a+b)/2;
}