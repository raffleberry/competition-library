#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n;
int a[N];
int T[4*N];

void build(int c = 1, int tl = 0, int tr = n-1) {
    if (tl == tr) {
        T[c] = a[tl];
        return;
    }
    
    int tm = (tl + tr) / 2;
    
    build(2*c, tl, tm);
    build(2*c + 1, tm+1, tr);
    
    T[c] = T[2*c] + T[2*c + 1];
}

void update(int c = 1, int tl = 0, int tr = n-1, int idx, int d) {
    if (tl == tr) {
        T[c] = d;
        return;
    }
    
    int tm = (tl + tr) / 2;
    
    if (idx <= tm) {
        update(2*c, tl, tm, idx, d);
    } else {
        update(2*c + 1, tm+1, tr, idx, d);
    }
    
    T[c] = T[2*c] + T[2*c + 1];
}

int query(int c = 1, int tl = 0, int tr = n-1, int ql, int qr) {
    if (qr < tl || tr < ql)
        return -inf;
    if (ql <= tl && tr <= qr)
        return T[c];
    
    int tm = (tl + tr) / 2;
    
    int lq = query(2*c, tl, tm, ql, qr);
    int rq = query(2*c + 1, tm + 1, tr, ql, qr);
    
    return lq + rq;
}

int main() {
    build(1, 0, n - 1);
    return 0;
}
