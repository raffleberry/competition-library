#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int a[N];
int T[4*N], delta[4*N];

void build(int c, int tl, int tr) {
    if (tl == tr) {
        T[c] = T[tl];
        return;
    }
    
    int tm = (tl + tr) / 2;
    
    build(2*c, tl, tm);
    build(2*c + 1, tm+1, tr);
    
    T[c] = T[2*c] + T[2*c + 1];
}

void prop(int c) {
    delta[2*c] += delta[c];
    delta[2*c + 1] += delta[c];
    delta[c] = 0;
}

void update(int c, int tl, int tr, int ul, int ur, int val) {
    if (ur < tl || tr < ul)
        return;
    if (ul <= tl && tr <= ur) {
        delta[c] += val;
        return;
    }
    
    prop(c);
    
    int tm = (tl + tr) / 2;
    
    update(2*c, tl, tm, ul, ur, val);
    update(2*c + 1, tm + 1, tr, ul, ur, val);
    
    T[c] = T[2*c] + T[2*c + 1];
    
/*
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
*/
}

int query(int c, int tl, int tr, int ql, int qr) {
    if (qr < tl || tr < ql)
        return -inf;
    if (ql <= tl && tr <= qr)
        return T[c] + delta[c];
    
    prop(c);
    
    int tm = (tl + tr) / 2;
    
    int lq = query(2*c, tl, tm, ql, qr);
    int rq = query(2*c + 1, tm + 1, tr, ql, qr);
    
    T[c] = T[2*c] + T[2*c + 1];
    //reflects the updates if there was anything to propagate in this node.
    
    return lq + rq;
}

int main() {
    build(1, 0, n - 1);
    return 0;
}
