#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool p(...) {
    //predicate
}

int main() {
    int lo = , hi = ;
    
//verification :  https://codeforces.com/contest/1221/submission/60853815
    while (lo < hi) {
        int m = (lo + hi)>>1;
        if (p(m)) {
            lo = m;
        } else {
            hi = m-1;
        }
    }
    cout << lo << endl;
    //TTTTTT FFFFFFFF
   //      *
    
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (p(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << lo << endl;
    //FFFFFF T TTTTTT
    //       *       
    if (lo == hi && p(lo)) {
        //ans = lo
    } else {
        //ans don't exist
    }
    
    //over real numbers
    double EPS = 1e-10, lo = -1000.0, hi = 1000.0;
    
    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2.0;
        if (p(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return 0;
}
